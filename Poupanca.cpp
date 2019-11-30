//
//  Poupanca.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 11/30/2019.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include <string>
#include <vector>
#include "Conta.hpp"
#include "Poupanca.hpp"
#include "Cliente.h"
#include "ExceptionClass.hpp"

using namespace std;

Poupanca::Poupanca(string name , string document, string address, string phone):Conta(name, document, address, phone) {
    Cliente client = Cliente(name, document, address,phone);
    setAccount(client);
};

void Poupanca::setAccount(Cliente client){
    setNumConta(getProximoNumConta());
    setBalance(0);
    setClient(client);
    setMovimentacoes({});
    setProxNumConta();
    saldoPoupanca = {};
};

double Poupanca::getBalance (){
    double savings = 0;
    for (auto balance : saldoPoupanca) {
        savings = savings + balance.getValue();
    }
    return savings;
}

int Poupanca::findBaseDateSaving(int baseDate) {
    for (int j= 0; j< saldoPoupanca.size(); j++ ) {
        if (saldoPoupanca[j].getDate() == baseDate) {
            return saldoPoupanca[j].getValue();
        }
    }
    return -1;
}

int Poupanca::checkBaseDate(int baseDate) {
    for (int j= 0; j< saldoPoupanca.size(); j++ ) {
        if (saldoPoupanca[j].getDate() == baseDate) {
            return j;
        }
    }
    return -1;
}

void Poupanca::debit(string description, double value, int baseDate) {
    int valorInicial = value;
    int novoSaldo = 0;
    int datePosition = 0;

    vector<SaldoDiaBase> debitoSaldoAux = {};

    if (baseDate == 29 || baseDate == 30 || baseDate == 31){
        baseDate = 28;
    }
    try {
        while (value > 0) {
            datePosition = checkBaseDate(baseDate);
            if (datePosition != -1) {
                novoSaldo = findBaseDateSaving(baseDate) - value;
                if (novoSaldo < 0){
                    SaldoDiaBase auxDebit = SaldoDiaBase(datePosition, 0);
                    debitoSaldoAux.push_back(auxDebit);
                    value = novoSaldo*(-1);
                }
                else {
                    saldoPoupanca[datePosition].setValue(novoSaldo);
                    value = 0;
                }
            }

            baseDate = baseDate - 1;

            if(baseDate <= 0 && value > 0){
                throw ExceptionClass(1);
            }
        }

        for (int j= 0; j< debitoSaldoAux.size(); j++ ) {
            saldoPoupanca[debitoSaldoAux[j].getDate()].setValue(debitoSaldoAux[j].getValue());
        }

        vector <Movimentacao> newMovs = getFinancialMovements();
        Movimentacao newMov = Movimentacao(description, 'D', valorInicial);
        newMovs.push_back(newMov);
        setMovimentacoes(newMovs);
    }
    catch {
        throw ExceptionClass(1);
    }
    
};

void Poupanca::credit (string description, double value, int baseDate) {
    int novoSaldo = 0;

    if (baseDate == 29 || baseDate == 30 || baseDate == 31){
        baseDate = 28;
    }

    int datePosition = checkBaseDate(baseDate);

    if (datePosition != -1) {
        novoSaldo = findBaseDateSaving(baseDate) + value;
        saldoPoupanca[datePosition].setValue(novoSaldo);
    }
    else {
        SaldoDiaBase newSaving = SaldoDiaBase(baseDate, value);
        saldoPoupanca.push_back(newSaving);
    }

    vector <Movimentacao> newMovs = getFinancialMovements();
    Movimentacao newMov = Movimentacao(description, 'C', value);
    newMovs.push_back(newMov);
    setMovimentacoes(newMovs);
};

