//
//  Poupanca.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 11/30/2019.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef Poupanca_hpp
#define Poupanca_hpp

#include <list>
#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "Movimentacao.hpp"
#include "Conta.hpp"
#include "SaldoDiaBase.hpp"

using namespace std;

class Poupanca : public Conta {
private:
    vector <SaldoDiaBase> saldoPoupanca;

public:
    Poupanca(string name , string document, string address, string phone);
    void setAccount(Cliente client);

    // Metodos get
    double getBalance ();
    int findBaseDateSaving(int baseDate);
    int checkBaseDate(int baseDate);
    
    // Funcoes
    void debit (string description, double value, int baseDate);
    void credit (string description, double value, int baseDate);
};


#endif /* Poupanca_hpp */
