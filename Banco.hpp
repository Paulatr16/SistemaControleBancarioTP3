//
//  Banco.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/2/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef Banco_hpp
#define Banco_hpp

#include <string>
#include <vector>
#include "Conta.hpp"
#include "Cliente.h"

using namespace std;


class Banco {
private:
    string nomeBanco;
    vector <Cliente> clientes;
    vector <Conta> contas;
    
    int findAccountIndex(int accountNumber);
    int checkClientHasAccount(string documentNumber);
    int findClient(string cpf_cnpj);
    
    
public:
    Banco(string bankName);
    void setBank(string bankName);

    // Metodos get
    vector <Cliente> getClientList ();
    vector <Conta> getAccountList ();
    
    // Funcoes
    void newClient (Cliente client);
    void newBankAccount (Cliente client);
    void removeClient (string cpf_cnpj);
    void removeBankAccount (int accountNumber);
    void newDeposit (int accountNumber, double value, string description = "Depósito");
    void newWithdraw (int accountNumber, double value, string description = "Saque");
    void newTransaction (int sourceAccountNumber, int destinationAccountNumber, double value);
    void newFee (double value);
    void newTaxCPMF ();
    double bankBalance (int accountNumber);
    vector <Movimentacao> bankStatement(int accountNumber);
    vector <Movimentacao> bankStatement (int accountNumber, struct tm startTime);
    vector <Movimentacao> bankStatement (int accountNumber, struct tm startTime, struct tm endTime);
    
    void readFile(string fileName);
    void writeFile(string fileName, string operation, string text);
    
    void testeStatement();
    
};
#endif /* Banco_hpp */
