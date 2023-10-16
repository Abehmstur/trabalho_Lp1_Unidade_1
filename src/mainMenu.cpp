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
    cout << "Ola cliente que voce deseja fazer? " << endl;
    cout << "1. Listar todos os sanduiches cadastrados." << endl;
    cout << "2. Listar todos os sucos cadastrados." << endl;
    cout << "3. Escolher o lanche." << endl;
    cout << "4. Calcular valor do lanche." << endl;
    cout << "5. Visualizar carrinho de lanche escolhido." << endl;
    cout << "6. Excluir um lanche do carrinho." << endl;
    cout << "7. Voltar ao Main Menu." << endl;
    cout << "======================" << endl;
}

//Menu do gestor
void menuGestor(){
    cout << "===== Main Gestor =====" << endl;
    cout << "Ola gestor voce deseja fazer? " << endl;
    cout << "1. Listar todos os sanduiches cadastrados." << endl;
    cout << "2. Listar todos os sucos cadastrados." << endl;
    cout << "3. Adicionar novo sanduiche." << endl;
    cout << "4. Adicionar novo suco." << endl;
    cout << "5. Alterar preco de um sanduiche." << endl;
    cout << "6. Alterar preco de um suco." << endl;
    cout << "7. Excluir sanduiche." << endl;
    cout << "8. Excluir suco." << endl;
    cout << "9. Voltar ao Main Menu." << endl;
    cout << "10. Extras." << endl;
    cout << "======================" << endl;
}

void extras(){
    cout << "===== Main Extras =====" << endl;
    cout << "1. Cadastrar Gestor." << endl;
    cout << "2. Listar Gestor." << endl;
    cout << "3. Cadastrar Cliente." << endl;
    cout << "4. Listar Cliente." << endl;
    cout << "======================" << endl;
}