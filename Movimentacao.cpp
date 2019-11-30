//
//  Movimentacao.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include "Movimentacao.hpp"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Movimentacao::Movimentacao(string description, char debitCredit, double value) {
    time_t timeNow = time(0);
    struct tm tstruct;
    tstruct = *localtime(&timeNow);
    setMovimentation(tstruct, description, debitCredit, value);
};

void Movimentacao::setMovimentation(struct tm dateMov, string description, char debitCredit, double value) {
    dataMov = dateMov;
    descricao = description;
    debitoCredito = debitCredit;
    valor = value;
};

struct tm Movimentacao::getDate(){
    return dataMov;
};

string Movimentacao::getDescription(){
    return descricao;
};

char Movimentacao::getDebitCredit(){
    return debitoCredito;
};

double Movimentacao::getValue(){
    return valor;
}
