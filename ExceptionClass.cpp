//
//  ExceptionClass.cpp
//  Sistema de Controle Bancário
//
//  Created by Alice Diniz Ferreira on 11/2/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include "ExceptionClass.hpp"

ExceptionClass::ExceptionClass(int index){
    switch (index) {
        case 1:
            message = "Saldo insuficiente para debito";
            break;
        case 2:
            message = "Cliente já possui cadastro";
            break;
        case 3:
            message = "Cliente ja possui conta no banco";
            break;
        case 4:
            message = "Cliente não registrado";
            break;
        case 5:
            message = "Conta não encontrada";
            break;
        case 6:
            message = "Valor invalido";
            break;
        case 7:
            message = "Conta remetente não foi encontrada";
            break;
        case 8:
            message = "Conta Destinatária não foi encontrada";
            break;
        case 9:
            message = "Saldo insuficiente para realizar transferencia";
            break;

        default:
            break;
    }
};
