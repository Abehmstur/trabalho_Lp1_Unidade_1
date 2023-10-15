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

std::string Gestor::getSenha() const {
    return senha;
}

map<string, Gestor> gestor;









//cadastrar gestor #USAR SÓ SE TIVER TEMPO (EXTRA)
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

//Valida se gestor eh o correto de acordo com a senha.
void validarGestor(){
    Gestor gestorValida;
    string senha;
    cout << "Por favor, informe sua senha: " << endl;
    cin >> senha;
    if(senha == gestorValida.getSenha()){
        cout << "Usuário atenticado.";
    }else {
        cout << "Senha incorreta.";
    }
}