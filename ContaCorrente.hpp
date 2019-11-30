//
//  ContaCorrente.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 11/30/2019.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef ContaCorrente_hpp
#define ContaCorrente_hpp

#include <list>
#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "Movimentacao.hpp"
#include "Conta.hpp"

using namespace std;

class ContaCorrente : public Conta {
private:
    double limiteCredito;
public:
    ContaCorrente(string name , string document, string address, string phone, double limit);

    void setAccount(Cliente client, double limit);

    //Metodos get
    double getCreditLimit();

    // Funcoes
    void debit (string description, double value);
    void credit (string description, double value);
};


#endif /* ContaCorrente_hpp */
