//
//  SaldoDiaBase.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include "SaldoDiaBase.hpp"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

SaldoDiaBase::SaldoDiaBase(int baseDate, double baseDateBalance) {
    setSaldo(baseDate, baseDateBalance);
};

void SaldoDiaBase::setSaldo(int baseDate, double baseDateBalance) {
    diaBase = baseDate;
    saldoDiaBase = baseDateBalance;
};

int SaldoDiaBase::getDate(){
    return diaBase;
};

double SaldoDiaBase::getValue(){
    return saldoDiaBase;
}

void SaldoDiaBase::setDate (int baseDate){
    diaBase = baseDate;
};

void SaldoDiaBase::setValue (double baseDateBalance) {
    saldoDiaBase = baseDateBalance;
};