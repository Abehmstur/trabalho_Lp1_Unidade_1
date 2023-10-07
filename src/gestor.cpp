#include "../include/gestor.hpp"
#include <map>
#include <iostream>
using namespace std;

Gestor::Gestor() {
}

void Gestor::setNome(const std::string& novoNome) {
    nome = novoNome;
}

std::string Gestor::getNome() const {
    return nome;
}

map<string, Gestor> gestor;

//cadastrar gestor
void cadastrarGestor(const string nome){
    //Ver se gestor existe no map
    if(gestor.find(nome) == gestor.end()){
    //Cria novo gestor caso nao exista
    Gestor novoGestor;
    novoGestor.setNome(nome);
    
    // adiciona o novo gestor no mapa
    gestor[nome] = novoGestor;
    } else {
        //se o gestor já existe no map, então só atualiza o nome dele
        gestor[nome].setNome(nome);
    }
};

//listar gestor
void listarGestor(){
    map<string, Gestor>::iterator it;

    for(it = gestor.begin(); it != gestor.end(); it++){
        cout << "Gestor: " << it->first << endl;
        //cout << "Gestor: " << it->second.getNome() << endl;
    }
}