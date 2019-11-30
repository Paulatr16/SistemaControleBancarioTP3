//
//  Banco.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/2/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include <ctime>
#include "Banco.hpp"
#include "ExceptionClass.hpp"
#include "Cliente.h"
#include "Conta.hpp"
#include <fstream>

using namespace std;

Banco::Banco(string bankName){
    setBank(bankName);
};

void Banco::setBank(string bankName){
    nomeBanco = bankName;
    clientes = {};
    contas = {};
};

vector <Cliente> Banco::getClientList () {
    return clientes;
}

vector <Conta> Banco::getAccountList () {
    return contas;
}

void Banco::newClient(Cliente client) {
    if (findClient(client.getDocumentNumber()) == -1) {
        clientes.push_back(client);
    }
    else {
        throw ExceptionClass(2);
    }
};

void Banco::newBankAccount(Cliente client) {
    string docNum = client.getDocumentNumber();
    if (checkClientHasAccount(docNum) == -1 ) {
        newClient(client);
        Conta newAccount = Conta(client.getName(), docNum, client.getAddress(), client.getPhone());
        contas.push_back(newAccount);
    }
    else {
        throw ExceptionClass(3);
    }
};

int Banco::findClient(string cpf_cnpj){
    int clientPosition = 0 ;
    for (auto client :clientes) {
        if (client.getDocumentNumber() == cpf_cnpj){
            return clientPosition;
        }
        clientPosition ++;
    }
    return -1;
}

void Banco::removeClient(string cpf_cnpj) {
    int index = findClient(cpf_cnpj);
    bool deleteClient = true;
    if (index == -1){
        deleteClient = false;
    }
    if (deleteClient) {
        int accIndex = checkClientHasAccount(cpf_cnpj);
        if ( accIndex != - 1) {
            int accNumber = contas[accIndex].getAccountNumber();
            removeBankAccount(accNumber);
        }
        clientes.erase(clientes.begin()+index);
    }
    else {
        throw ExceptionClass(4);
    }
};

void Banco::removeBankAccount(int accountNumber) {
    int accIndex = findAccountIndex(accountNumber);
    if ( accIndex != - 1){
        contas.erase(contas.begin() + accIndex);
    }
    else{
        throw ExceptionClass(5);
    }
};

void Banco::newDeposit(int accountNumber, double value, string description) {
    if (value <= 0) {
        throw ExceptionClass(6);
    }
    int accIndex = findAccountIndex(accountNumber);
    
    if ( accIndex != -1) {
        contas[accIndex].credit(description, value);
    }
    else{
        throw ExceptionClass(5);
    }
};

void Banco::newWithdraw(int accountNumber, double value, string description ) {
    if (value <= 0) {
        throw ExceptionClass(6);
    }
    int accIndex = findAccountIndex(accountNumber);
    if ( accIndex != -1) {
        contas[accIndex].debit(description, value);
    }
    else {
        throw ExceptionClass(5);
    }
};

void Banco::newTransaction (int sourceAccountNumber, int destinationAccountNumber, double value){
    if (value <= 0) {
        throw ExceptionClass(6);
    }
    if ( findAccountIndex(sourceAccountNumber) == -1 ) {
        throw ExceptionClass(7);
    }
    if (findAccountIndex(destinationAccountNumber) == -1) {
        throw ExceptionClass(8);
    }
    
    if ( contas[sourceAccountNumber].getBalance() - value >= 0 ) {
        string descriptionSource = "Transferência para conta " + std::to_string(destinationAccountNumber);
        string descriptionDestination = "Transferência da conta " + std::to_string(sourceAccountNumber);
        newWithdraw(sourceAccountNumber, value, descriptionSource);
        newDeposit(destinationAccountNumber, value, descriptionDestination);
    }
    else {
        throw ExceptionClass(9);
    }
};

void Banco::newFee (double value) {
    string description = "Cobrança de tarifa";
    int j;
    for (j = 0; j < contas.size(); j++ ) {
        contas[j].debit(description, value);
    }
};

void Banco::newTaxCPMF () {
    string description = "Cobrança de CPMF";
    double descountFee = 0.0038;
    double descountValue = 0 ;
    vector <Movimentacao> movimentacoesAux;
    time_t lastDay = time(0);
    time_t firtsDay = lastDay - 7*24*60*60;

    for (auto acc:contas) {
        movimentacoesAux = acc.getFinancialMovements();
        for (auto mov:movimentacoesAux){
            if(mov.getDebitCredit() == 'D'){
                struct tm movDate = mov.getDate();
                if(mktime(&movDate) >= firtsDay || mktime(&movDate) <= lastDay ) {
                    descountValue = mov.getValue();
                }
            }
        }

        descountValue = descountValue * descountFee;
        newWithdraw(acc.getAccountNumber(), descountValue, description);
    }
}

double Banco::bankBalance(int accountNumber) {
    int accIndex = findAccountIndex(accountNumber);
    double saldo = 0.0;
    if( accIndex != - 1) {
        saldo = contas[accIndex].getBalance();
    }
    else {
        throw ExceptionClass(5);
    }
    return saldo;
};

vector <Movimentacao> Banco::bankStatement(int accountNumber) {
    time_t timeNow = time(0);
    struct tm actualMonth;
    actualMonth = *localtime(&timeNow);
    actualMonth.tm_mday = 1;
    vector <Movimentacao> statement;
    
    int accIndex = findAccountIndex(accountNumber);
    if (accIndex != - 1) {
        statement = bankStatement(accountNumber, actualMonth);
    }
    else {
        throw ExceptionClass(5);
    }
    return statement;
};

vector <Movimentacao> Banco::bankStatement(int accountNumber, struct tm startTime) {
    int accIndex = findAccountIndex(accountNumber);
    vector <Movimentacao> statement;
    if (accIndex != -1) {
        statement =  contas[accountNumber].getAccountBalance(startTime);
    }
    else {
        throw ExceptionClass(5);
    }
    return statement;
};

vector <Movimentacao> Banco::bankStatement(int accountNumber, struct tm startTime, struct tm endTime) {
    int accIndex = findAccountIndex(accountNumber);
    vector <Movimentacao> statement;
    if (accIndex != -1) {
        statement =  contas[accIndex].getAccountBalance(startTime, endTime);
    }
    else {
        throw ExceptionClass(5);
    }
    return statement;
};

void Banco::writeFile(string fileName, string operation, string text) {
    ofstream outputFile;
    outputFile.open(fileName, ios::app);
    outputFile << operation + ":\n";
    outputFile << text + "\n";
    outputFile.close();
};

void Banco::readFile(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);
    string readData;
    if(inputFile.is_open()) {
        while (getline(inputFile, readData)) {
            //leitura linha a linha
        }
    };
    inputFile.close();
};

int Banco::findAccountIndex(int accountNumber) {
    for (int j= 0; j< contas.size(); j++ ) {
        if (contas[j].getAccountNumber() == accountNumber) {
            return j;
        }
    }
    return -1;
}

int Banco::checkClientHasAccount(string documentNumber) {
    int count = 0;
    vector <Conta> listAccs = contas;
    for (auto acc:listAccs) {
        if ( acc.getClient().getDocumentNumber()  == documentNumber) {
            return count;
        }
        count++;
    }
    return -1;
}
        
void Banco::testeStatement() {
    struct tm tstruct;
    tstruct.tm_mday = 10;
    tstruct.tm_mon = 10-1;
    tstruct.tm_year = 2010 - 1900;
    contas[0].newMovTest(tstruct, "Teste 10/10/2010", 10.5);
    
    tstruct.tm_mday = 10;
    tstruct.tm_mon = 9-1;
    tstruct.tm_year = 2008 - 1900;
    contas[0].newMovTest(tstruct, "Teste 10/09/2008", 10);

    tstruct.tm_mday = 10;
    tstruct.tm_mon = 9-1;
    tstruct.tm_year = 2005 - 1900;
    contas[0].newMovTest(tstruct, "Teste 10/09/2005", 10);

}
