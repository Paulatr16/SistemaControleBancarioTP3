//
//  Interface.cpp
//  Sistema de Controle Bancario
//
//  Created by Alice Diniz Ferreira on 10/5/19.
//  Edited by Monique Stephanie Rodrigues Silva 10/11/19.
//  Edited by Paula Resende Teixeira on 10/15/19.
//  Copyright © 2019 trabalhoPOO. All rights reserved.
//

#include "Interface.hpp"
#include "Banco.hpp"
#include "ExceptionClass.hpp"
#include <time.h>
#include <string>
#include <ctime>


using namespace std;

Interface::Interface(string bankName):interfaceBanco(bankName) {};

Banco Interface::getBank() {
    return interfaceBanco;
}

void Interface::menu()
{
    while (1)
    {
        int opcao;
        puts("  [1] - Cadastrar novo Cliente\n");
        puts("  [2] - Abrir Nova Conta\n");
        puts("  [3] - Excluir Cliente\n");
        puts("  [4] - Excluir Conta\n");
        puts("  [5] - Depositar\n");
        puts("  [6] - Sacar\n");
        puts("  [7] - Transferencia\n");
        puts("  [8] - Cobrar Tarifa\n");
        puts("  [9] - Cobrar CPMF\n");
        puts(" [10] - Saldo\n");
        puts(" [11] - Extrato\n");
        puts(" [12] - Listar Clientes\n");
        puts(" [13] - Listar Contas\n");
        puts(" [14] - Teste\n");
        puts("Qualquer outra tecla para Sair");
        puts("\n\n");
        cin >> opcao;
        switch (opcao)
        {
        case 1: //METODO PARA CRIAR NOVO CLIENTE E INSERIR NA LISTA DE CLIENTES
        {
            criaNovoCliente();
            break;
        }

        case 2: //METODO PARA CRIAR NOVA CONTA E INSERIR NA LISTA DE CONTAS
        {
            criaNovaConta();
            break;
        }

        case 3: //METODO PARA EXCLUIR UM CLIENTE QUE NÃO TENHA CONTA
        {
            excluiCliente();
            break;
        }

        case 4: //METODO PARA EXCLUIR UMA CONTA DE UM CLIENTE
        {
            excluiConta();
            break;
        }

        case 5: //METODO PARA DEPOSITAR EM UMA CONTA
        {
            deposita();
            break;
        }

        case 6: //METODO PARA SACAR DE UMA CONTA
        {
            saca();
            break;
        }

        case 7: //METODO PARA TRANSFERÊNCIA ENTRE CONTAS
        {
            transfere();
            break;
        }

        case 8: //METODO PARA COBRAR TARIFA
        {
            interfaceBanco.newFee(15.0);
            break;
        }

        case 9: //METODO PARA COBRAR CPMF
        {
            cout << "Sera tarifado CPMF." << endl;
            interfaceBanco.newTaxCPMF();
            break;
        }

        case 10: //METODO PARA VER SALDO
        {
            checaSaldo();
            break;
        }
        case 11: //METODO PARA LISTAR EXTRATO
        {
            listStatement();
            break;
        }

        case 12:
        {
            listaClientes();
            break;
        }

        case 13:
        {
            listaContas();
            break;
        }
        case 14: {
            interfaceBanco.testeStatement();
            break;
        }
        case 0:
            return;
            break;

        default:
            return;
            break;
        }
    };
};

void Interface::criaNovoCliente()
{
    string nome;
    string cpf_cnpj;
    string endereco;
    string telefone;

    cout << "Nome Completo:" << endl;
    cin.ignore();
    getline(cin, nome);
    cout << "Número CPF/CNPJ:" << endl;
    cin >> cpf_cnpj;
    cout << "Endereço:" << endl;
    cin.ignore();
    getline(cin, endereco);
    cout << "Número de telefone:" << endl;
    cin >> telefone;

    Cliente novoCliente = Cliente(nome, cpf_cnpj, endereco, telefone);
    try {
        interfaceBanco.newClient(novoCliente);
        cout << "Cliente cadastrado com sucesso" << endl;
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
};

void Interface::criaNovaConta()
{
    string nome;
    string cpf_cnpj;
    string endereco;
    string telefone;

    cout << "Digite os dados do cliente para gerar a conta" << endl;
    cout << "Nome Completo: " << endl;
    cin.ignore();
    getline(cin, nome);
    cout << "Número CPF/CNPJ: " << endl;
    cin >> cpf_cnpj;
    cout << "Endereço: " << endl;
    cin.ignore();
    getline(cin, endereco);
    cout << "Número de telefone: " << endl;
    cin >> telefone;
    
    Cliente cliente = Cliente(nome, cpf_cnpj, endereco, telefone);
    try {
        interfaceBanco.newBankAccount(cliente);
        cout << "Conta criada com sucesso" << endl;
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
    
}

void Interface::excluiCliente () {
    string cadastro;
    
    cout << "Digite CPF/CNPJ para excluir o cadastro do cliente:";
    cin >> cadastro;

    try {
        interfaceBanco.removeClient(cadastro);
        cout << "Cliente excluido da base de dados" << endl;
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
}

void Interface::excluiConta() {
    int numConta;
    cout << "Digite a o numero da conta que deseja excluir:";
    cin >> numConta;

    try {
        interfaceBanco.removeBankAccount(numConta);
        cout << "Conta excluida" << endl;
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
    
}

void Interface::deposita() {
    int numConta;
    double valorDeposito;
    cout << "Para um novo deposito, digite numero da conta:";
    cin >> numConta;
    cout << "Digite o valor do deposito:\n";
    cin >> valorDeposito;

    try {
        interfaceBanco.newDeposit(numConta, valorDeposito);
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
    
}

void Interface::saca() {
    int numConta;
    double valorSaque;
    cout << "Para novo saque digite o numero da conta :\n";
    cin >> numConta;
    cout << "Valor do saque:\n";
    cin >> valorSaque;

    try {
        interfaceBanco.newWithdraw(numConta, valorSaque);
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
    
}

void Interface::transfere() {
    int contaOrigem;
    int contaDestino;
    double valorTransferencia;
    
    cout << "Digite o numero da conta de origem: \n";
    cin >> contaOrigem;
    cout << "Digite o numero da conta de destino: \n";
    cin >> contaDestino;
    cout << "Digite o valor da transferencia: \n";
    cin >> valorTransferencia;

    try {
        interfaceBanco.newTransaction(contaOrigem, contaDestino, valorTransferencia);
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
    
}

void Interface::checaSaldo(){
    int numeroConta;
    cout << "Digite sua conta: ";
    cin >> numeroConta;

    try {
        cout << interfaceBanco.bankBalance(numeroConta) << endl;
    }
    catch (ExceptionClass error){
        cout << error.what() << endl;
    }
    
}

void Interface::listaClientes() {
    vector <Cliente> listClients = interfaceBanco.getClientList();
    for (auto cliente : listClients ){
        cout << "Nome: " << cliente.getName() << endl;
    }
}

void Interface::listaContas() {
    vector <Conta> listAccs = interfaceBanco.getAccountList();
    for (auto acc : listAccs){
        cout << "Cliente: " << acc.getClient().getName() << endl;
        cout << "Número da Conta: " << acc.getAccountNumber() << endl;
    }
}

void Interface::listStatement() {
    char extrato;
    int numConta;
    string stringStartDate;
    string stringEndDate;
    
    struct tm inputStartDate;
    struct tm inputEndDate;
    
    cout << "Escolha o tipo de extrato desejado:\n"
         << " A) Extrato do ultimo mes.\n"
         << " B) Extrato com data incial ate data vigente.\n"
         << " C) Extrato entre as datas escolhidas.\n"
         << endl;
    cin >> extrato;

    if (extrato == 'a' || extrato == 'A'){
        cout << "Digite numero da conta: " << endl;
        cin >> numConta;

        try {
            vector <Movimentacao> auxStatement = interfaceBanco.bankStatement(numConta);
            printStatement(auxStatement);
        }
        catch (ExceptionClass error){
            cout << error.what() << endl;
        }

    }
    if (extrato == 'b' || extrato == 'B'){
        cout << "Digite numero da conta: " << endl;
        cin >> numConta;
        cout << "Digite a data incial: (Formato DD/MM/AAAA)" << endl;
        cin >> stringStartDate;
        inputStartDate = handleStringDate(stringStartDate);

        try {
            vector <Movimentacao> auxStatement = interfaceBanco.bankStatement(numConta, inputStartDate);
            printStatement(auxStatement);
        }
        catch (ExceptionClass error){
            cout << error.what() << endl;
        }

    }
    if (extrato == 'c' || extrato == 'C'){
        cout << "Digite numero da conta: " << endl;
        cin >> numConta;
        cout << "Digite a data incial: " << endl;
        cin >> stringStartDate;
        cout << "Digite a data final: " << endl;
        cin >> stringEndDate;
        inputStartDate = handleStringDate(stringStartDate);
        inputEndDate = handleStringDate(stringEndDate);
        
        try {
            vector <Movimentacao> auxStatement = interfaceBanco.bankStatement(numConta, inputStartDate, inputEndDate);
            printStatement(auxStatement);
        }
        catch (ExceptionClass error){
            cout << error.what() << endl;
        }
        
    }
}


struct tm Interface::handleStringDate(string inputDate) {
    int day = stoi(inputDate.substr(0,inputDate.find("/")));
    
    string monthYear = inputDate.substr(inputDate.find("/") + 1);
    int month = stoi(monthYear.substr(0, monthYear.find("/")));
    int year = stoi(monthYear.substr(monthYear.find("/")+1));
    
    time_t timeNow = time(0);
    struct tm convertedDate;
    convertedDate = *localtime(&timeNow);

    convertedDate.tm_mday = day;
    convertedDate.tm_mon = month - 1;
    convertedDate.tm_year = year - 1900;
    return convertedDate;
}


void Interface::printStatement(vector <Movimentacao> statements){
    for (auto it : statements){
        struct tm dataInicial = it.getDate();
        cout << "Data:" << dataInicial.tm_mday << "/" << (dataInicial.tm_mon + 1) << "/" << (dataInicial.tm_year + 1900) << endl;
        cout << "Descrição:" << it.getDescription() << endl;
        cout << "Valor:" << it.getValue() << endl;
        cout << "\n\n";
    }
}
