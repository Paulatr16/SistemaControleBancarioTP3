//
//  Conta.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef Conta_hpp
#define Conta_hpp

#include <list>
#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "Movimentacao.hpp"

using namespace std;

class Conta {
private:
    int numConta;
    double saldo;
    Cliente cliente;
    vector <Movimentacao> movimentacoes;
    static int proximoNumConta;

public:
    
    Conta(string name , string document, string address, string phone);
    virtual void setAccount(Cliente client);
    
    // Metodos set
    void setNumConta(int numAccount);
    void setBalance(int balanceValue);
    void setClient(Cliente client);
    void setMovimentacoes(vector <Movimentacao> movs);
    void setProxNumConta();
    
    // Metodos get
    virtual double getBalance ();
    int getAccountNumber ();
    Cliente getClient ();
    vector <Movimentacao> getFinancialMovements();
    int getProximoNumConta();
    
    // Funcoes
    virtual void debit (string description, double value) = 0 ;
    virtual void credit (string description, double value) = 0 ;
    vector <Movimentacao> getAccountBalance();
    vector <Movimentacao> getAccountBalance(struct tm startTime);
    vector <Movimentacao> getAccountBalance(struct tm startTime, struct tm endTime);

    // Teste
    void newMovTest(struct tm dataMov, string description, double value);
};


#endif /* Conta_hpp */
