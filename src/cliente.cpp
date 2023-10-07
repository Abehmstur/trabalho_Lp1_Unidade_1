#include "../include/cliente.hpp"
#include <map>
#include <iostream>
using namespace std;

Cliente::Cliente() {
}

void Cliente::setNome(const std::string& novoNome) {
    nome = novoNome;
}

std::string Cliente::getNome() const {
    return nome;
}

map<string, Cliente> cliente;

//cadastrar Cliente
void cadastrarCliente(const string nome){
    //Ver se Cliente existe no map
    if(cliente.find(nome) == cliente.end()){
    //Cria novo Cliente caso nao exista
    Cliente novoCliente;
    novoCliente.setNome(nome);
    
    // adiciona o novo Cliente no mapa
    cliente[nome] = novoCliente;
    } else {
        //se o Cliente já existe no map, então só atualiza o nome dele
        cliente[nome].setNome(nome);
    }
};

//listar Cliente
void listarCliente(){
    map<string, Cliente>::iterator it;

    for(it = cliente.begin(); it != cliente.end(); it++){
        cout << "Cliente: " << it->first << endl;
        //cout << "Cliente: " << it->second.getNome() << endl;
    }
}