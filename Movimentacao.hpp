//
//  Movimentacao.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//
#ifndef Movimentacao_hpp
#define Movimentacao_hpp

#include <iostream>
#include <string>

using namespace std;

class Movimentacao {
private:
    struct tm dataMov;
    string descricao;
    char debitoCredito;
    double valor;

public:
    // Construtor
    Movimentacao(string description, char debitCredit, double value);
    
    // Metodo Set
    void setMovimentation(struct tm dataMov, string desc, char debitCredit, double value);

    // Metodos Get
    struct tm getDate();
    string getDescription();
    char getDebitCredit();
    double getValue();
};

#endif /* Movimentacao_hpp */
