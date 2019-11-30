//
//  Interface.hpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira on 10/5/19.
//  Edited by Paula Resende Teixeira on 10/15/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include <stdio.h>
#include <ctime>
#include <string>
#include <vector>
#include "Banco.hpp"
#include "Conta.hpp"
#include "Movimentacao.hpp"
#include "Cliente.h"

using namespace std;

class Interface {
private:
    Banco interfaceBanco;
    struct tm handleStringDate(string inputDate);
    void printStatement(vector <Movimentacao> statements);
    
public:
    Interface(string bankName);
    
    Banco getBank();
    void criaNovoCliente();
    void criaNovaConta();
    void menu();
    void excluiCliente();
    void excluiConta();
    void deposita();
    void saca();
    void transfere();
    void checaSaldo();
    void listaClientes();
    void listaContas();
    void listStatement();
    
    
};
#endif /* Interface_hpp */
