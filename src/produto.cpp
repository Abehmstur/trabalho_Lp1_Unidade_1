#include "../include/produto.hpp"
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

Produto::Produto() {
}

void Produto::setNome(const string& novoNome) {
    nome = novoNome;
}

string Produto::getNome() const {
    return nome;
}

void Produto::setPreco(const float& novoPreco) {
    preco = novoPreco;
}

float Produto::getPreco() const {
    return preco;
}

map<string, Produto> produto;
map<string, Produto> carrinho;


//cadastrar produto
void cadastrarProduto(const string nome, float preco){
    //Ver se produto existe no map
    if(produto.find(nome) == produto.end()){
    //Cria novo produto caso nao exista
    Produto novoProduto;
    novoProduto.setNome(nome);
    novoProduto.setPreco(preco);
    
    // adiciona o novo produto no mapa
    produto[nome] = novoProduto;
    } else {
        //se o produto já existe no map, então só atualiza o nome dele
        produto[nome].setNome(nome);
        produto[nome].setPreco(preco);
    }
};

//funcao para salvar os produtos em arquivos diferentes
void salvarArquivo(int escolha, map<string, Produto>& produto) {
    float preco_produto = 0.0;
    //caso o cliente deseje cadastrar um suco ou um sanduiche.
    if (escolha == 0) {
        ofstream arquivoSuco("arquivoSuco.txt", ios::out | ios::app);

        cout << "Você escolheu cadastrar um suco, informe o nome e o preço." << endl;

        for (auto& it : produto) {
            string nomeSuco = it.first;

            cout << "Informe o nome do produto: " << nomeSuco << endl;
            arquivoSuco << nomeSuco << endl;

            cout << "Informe o preço do produto: ";
            cin >> preco_produto;
            it.second.setPreco(preco_produto);

            arquivoSuco << preco_produto << endl;
        }

        arquivoSuco.close();

    }else if(escolha == 1){
        ofstream arquivoSanduiche("arquivoSanduiche.txt", ios::out | ios::app);

        cout << "Você escolheu cadastrar um sanduiche, informe o nome e o preço." << endl;

        for (auto& it : produto) {
            string nomeSanduiche = it.first;

            cout << "Informe o nome do produto: " << nomeSanduiche << endl;
            arquivoSanduiche << nomeSanduiche << endl;

            cout << "Informe o preço do produto: ";
            cin >> preco_produto;
            it.second.setPreco(preco_produto);

            arquivoSanduiche << preco_produto << endl;
        }
        
        arquivoSanduiche.close();
    }
}

//alterar produto
void alterarProduto(int escolha, map<string, Produto>& produtos){
    string nomeProduto = "";
    float preco_produto = 0.0;

    //caso o cliente deseje ALTERAR um suco ou um sanduiche.
    if (escolha == 0) {

        ofstream arquivoSuco("arquivoSuco.txt", ios::in | ios::out |ios::app);

        cout << "Você escolheu ALTERAR um suco, informe o nome do suco que deseja alterar." << endl;
        getline(cin, nomeProduto);

        
        auto it = produtos.find(nomeProduto);
        //if para verificar se o produto existe no map
        if (it != produtos.end()){
            cout << "Digite o novo nome para o suco: ";
            cin >> nomeProduto;
            
        }
    };


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
};

//listar produto
void listarProduto(){
    map<string, Produto>::iterator it;

    for(it = produto.begin(); it != produto.end(); it++){
        cout << "Produto: " << it->first << endl;
        cout << "Produto: " << it->second.getPreco() << endl;
    }
}

//escolher produto
void escolherLanche(string sandwinche, string suco){

};