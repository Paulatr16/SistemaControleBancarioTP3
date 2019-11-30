//
//  Cliente.h
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira and Paula Resende Teixeira on 10/1/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#ifndef Cliente_h
#define Cliente_h

#include <string>

using namespace std;

class Cliente {
private:
    string nomeCliente;
    string cpf_cnpj;
    string endereco;
    string fone;

public:
    // Construtor
    Cliente(string name , string document, string address, string phone);
    
    // Metodos Set
    void setClient(string name , string document, string address, string phone);
    void setName (string name);
    void setDocumentNumber (string document);
    void setAddress (string address);
    void setPhone (string phone);
    
    // Metodos get
    string getName ();
    string getDocumentNumber ();
    string getAddress ();
    string getPhone ();
};

#endif /* Cliente_h */
