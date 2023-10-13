#include "../include/produto.hpp"
#include <map>
#include <iostream>
using namespace std;

Produto::Produto() {
}

void Produto::setNome(const std::string& novoNome) {
    nome = novoNome;
}

std::string Produto::getNome() const {
    return nome;
}

void Produto::setPreco(const float& novoPreco) {
    preco = novoPreco;
}

float Produto::getPreco() const {
    return preco;
}

map<string, Produto> produto;

void alterarProduto(const string nome) {
    //Ver se produto existe no map
    if(produto.find(nome) == produto.end()){
    //Cria novo produto caso nao exista
    Produto novoProduto;
    novoProduto.setNome(nome);
    
    // adiciona o novo produto no mapa
    produto[nome] = novoProduto;
    } else {
        //se o produto já existe no map, então só atualiza o nome dele
        produto[nome].setNome(nome);
    }
}
