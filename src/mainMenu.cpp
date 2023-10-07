#include <iostream>
using namespace std;

void menuPrincipal(){
    cout << "===== Main Menu =====" << endl;
    cout << "Identifique-se, por favor: " << endl;
    cout << "1. Gestor" << endl;
    cout << "2. Cliente" << endl;
    cout << "3. Sair" << endl;
    cout << "======================" << endl;
}
//Menu do cliente
void menuCliente(){
    cout << "===== Main Cliente =====" << endl;
    cout << "Ola %d que você deseja fazer? " << endl;
    cout << "1. Listar todos os itens cadastrados." << endl;
    cout << "2. Listar todos os sanduiches cadastrados." << endl;
    cout << "3. Listar todos os sucos cadastrados." << endl;
    cout << "4. Escolher o lanche." << endl;
    cout << "5. Visualizar carrinho de lanche escolhido." << endl;
    cout << "6. Excluir um lanche do carrinho." << endl;
    cout << "7. Voltar ao Main Menu." << endl;
    cout << "======================" << endl;
}


//Menu do gestor
void menuGestor(){
    cout << "===== Main Gestor =====" << endl;
    cout << "O que você deseja fazer? " << endl;
    cout << "1. Listar todos os itens cadastrados." << endl;
    cout << "2. Listar todos os sanduiches cadastrados." << endl;
    cout << "3. Listar todos os sucos cadastrados." << endl;
    cout << "4. Escolher o lanche." << endl;
    cout << "5. Visualizar carrinho de lanche escolhido." << endl;
    cout << "6. Excluir um lanche do carrinho." << endl;
    cout << "7. Voltar ao Main Menu." << endl;
    cout << "======================" << endl;
}