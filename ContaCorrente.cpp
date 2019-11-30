//  ContaCorrente.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 11/30/2019.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include <string>
#include <vector>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "Cliente.h"
#include "ExceptionClass.hpp"

using namespace std;

ContaCorrente::ContaCorrente(string name , string document, string address, string phone, double limit):Conta(name,document,address,phone){
    Cliente client = Cliente(name, document, address,phone);
    setAccount(client, limit);
};

void ContaCorrente::setAccount(Cliente client, double limit){
    setNumConta(getProximoNumConta());
    setBalance(0);
    setClient(client);
    setMovimentacoes({});
    setProxNumConta();
};

double ContaCorrente::getCreditLimit () {
    return limiteCredito;
};

void ContaCorrente::debit(string description, double value) {
    double depositLimit = getBalance() + limiteCredito;
    if (value <= depositLimit || description == "Cobrança de tarifa" || description == "Cobrança de CPMF") {
        double novoSaldo = getBalance() - value;
        setBalance(novoSaldo);
        vector <Movimentacao> newMovs = getFinancialMovements();
        Movimentacao newMov = Movimentacao(description, 'C', value);
        newMovs.push_back(newMov);
        setMovimentacoes(newMovs);
    }
    else {
        throw ExceptionClass(1);
    }
};

void ContaCorrente::credit(string description, double value) {
    double novoSaldo = getBalance() + value;
    setBalance(novoSaldo);
    vector <Movimentacao> newMovs = getFinancialMovements();
    Movimentacao newMov = Movimentacao(description, 'C', value);
    newMovs.push_back(newMov);
    setMovimentacoes(newMovs);
};

