//
//  Cliente.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

Cliente::Cliente(string name , string document, string address, string phone){
    setClient(name, document, address, phone);
};

void Cliente::setClient(string name , string document, string address, string phone){
    nomeCliente = name;
    cpf_cnpj = document;
    endereco = address;
    fone = phone;
};

void Cliente::setName (string name){
    nomeCliente = name;
};

void Cliente::setDocumentNumber (string document) {
    cpf_cnpj = document;
};

void Cliente::setAddress (string address) {
    endereco = address;
};

void Cliente::setPhone (string phone) {
    fone = phone;
};


string Cliente::getName () {
    return nomeCliente;
};

string Cliente::getDocumentNumber () {
    return cpf_cnpj;
};

string Cliente::getAddress () {
    return endereco;
};

string Cliente::getPhone () {
        return fone;
};
                
