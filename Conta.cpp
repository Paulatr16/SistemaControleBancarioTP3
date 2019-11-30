//
//  Conta.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//
#include <string>
#include <vector>
#include "Conta.hpp"
#include "Cliente.h"

using namespace std;

int Conta::proximoNumConta = 0;

Conta::Conta(string name , string document, string address, string phone):cliente(name, document,address,phone){
    setAccount(cliente);
};

void Conta::setAccount(Cliente client){
    numConta = proximoNumConta;
    saldo = 0;
    cliente = client;
    movimentacoes = {};
    proximoNumConta++;
};

// Metodos set
void Conta::setNumConta(int numAccount){
    numConta = numAccount;
};

void Conta::setBalance(int balanceValue){
    saldo = balanceValue;
};

void Conta::setClient(Cliente client){
    cliente = client;
};

void Conta::setMovimentacoes(vector <Movimentacao> movs){
    movimentacoes = movs;
};

void Conta::setProxNumConta(){
    proximoNumConta ++;
};

// Metodos get
int Conta::getAccountNumber () {
    return numConta;
};

double Conta::getBalance () {
    return saldo;
};
Cliente Conta::getClient () {
    return cliente;
};

vector <Movimentacao> Conta::getFinancialMovements() {
    return movimentacoes;
};

vector <Movimentacao> Conta::getAccountBalance(){
    return getFinancialMovements();
};

vector <Movimentacao> Conta::getAccountBalance(struct tm startTime){
    vector <Movimentacao> movs = {};
    vector <Movimentacao> accountMovs = getFinancialMovements();
    if (accountMovs.empty()) {
        return {};
    }
    else {
        time_t timeNow = time(0);
        for (auto v : accountMovs) {
            struct tm movDate = v.getDate();
            if ((mktime(&movDate) >= mktime(&startTime)) and (mktime(&movDate) <= timeNow)){
                movs.push_back(v);
            }
        }
    }
    return movs;
};

vector <Movimentacao> Conta::getAccountBalance(struct tm startTime, struct tm endTime){
    vector <Movimentacao> movs = {};
    vector <Movimentacao> accountMovs = getFinancialMovements();
    if (accountMovs.empty()) {
        return {};
    }
    else {
        for (auto v : accountMovs) {
            struct tm movDate = v.getDate();
            if ((mktime(&movDate) >= mktime(&startTime)) and (mktime(&movDate) <= mktime(&endTime))){
                movs.push_back(v);
            }
        }
    }
    return movs;
};

int Conta::getProximoNumConta() {
    return proximoNumConta;
};


void Conta::newMovTest (struct tm dataMov, string description, double value){
    Movimentacao newMov = Movimentacao(description, 'T', value);
    newMov.setMovimentation(dataMov, description, 'T', value);
    movimentacoes.push_back(newMov);
    cout << "Ola" << endl;
};
