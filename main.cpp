//  main.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 9/29/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//
#include <time.h>
#include <iostream>
#include <stdio.h>
#include "Interface.hpp"
#include "Banco.hpp"
#include "Conta.hpp"
#include "Cliente.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Interface interPOO = Interface("Banco POO");
    
    interPOO.menu();
    
    return 0;
}
