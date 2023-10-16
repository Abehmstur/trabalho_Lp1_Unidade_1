#include "../include/produto.hpp"
#include "../include/carrinho.hpp"
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

const int SUCO = 0;
const int SANDUICHE = 1;
const int CARRINHO = 3;

//constructor e funcoes de encapsulamento da de produto.hpp
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

//constructor e funcoes de encapsulamento da de carrinho.hpp
Carrinho::Carrinho(){
}

void Carrinho::setItem(const string& novoItem){
    item = novoItem;
}

void Carrinho::setPreco(const float& novoPreco){
    preco = novoPreco;    
}

string Carrinho::getItem(){
    return item;
}

float Carrinho::getPreco() const {
    return preco;
}


map<string, Produto> produto;
map<string, Produto> carrinho;

//funcao para salvar os produtos em arquivos diferentes
void salvarArquivo(int escolha, map<string, Produto>& produto) {
    float preco_produto = 0.0;
    //caso o cliente deseje cadastrar um suco ou um sanduiche.
    if (escolha == SUCO) {
        fstream arquivoSuco("arquivoSuco.txt", ios::out | ios::app);

        cout << "Voce escolheu cadastrar um suco, informe o nome e o preco." << endl;

        for (auto& it : produto) {
            string nomeSuco = it.first;

            cout << "Informe o nome do produto: " << nomeSuco << endl;
            arquivoSuco << "Item: " << nomeSuco << endl;

            cout << "Informe o preço do produto: ";
            cin >> preco_produto;
            it.second.setPreco(preco_produto);

            arquivoSuco << "Preço: " <<preco_produto << endl;
        }

        arquivoSuco.close();

    }else if(escolha == SANDUICHE){
        fstream arquivoSanduiche("arquivoSanduiche.txt", ios::out | ios::app);

        cout << "Voce escolheu cadastrar um sanduiche, informe o nome e o preco: " << endl;

        for (auto& it : produto) {
            string nomeSanduiche = it.first;

            cout << "Informe o nome do produto: " << nomeSanduiche << endl;
            arquivoSanduiche << "Item: " << nomeSanduiche << endl;

            cout << "Informe o preço do produto: ";
            cin >> preco_produto;
            it.second.setPreco(preco_produto);

            arquivoSanduiche << "Preço: " << preco_produto << endl;
        }
        
        arquivoSanduiche.close();
    }
}

//alterar produto
void alterarProduto(int escolha, map<string, Produto>& produtos){
    string nomeProduto = "";

    //caso o cliente deseje ALTERAR um suco ou um sanduiche.
    if (escolha == SUCO) {

        cout << "Você escolheu ALTERAR um suco, informe o nome do suco que deseja alterar." << endl;
        getline(cin, nomeProduto);
        
        auto it = produtos.find(nomeProduto);
        
        //Verificar se o produto existe no map
        if (it != produtos.end()){
            //alteração do produto no map
            string novoNome;
            float novoPreco;
            float precoAntigo = it->second.getPreco();

            cout << "Digite o novo nome para o suco: ";
            getline(cin, novoNome);
            cout << "Digite o  novo preco para o suco: ";
            cin >> novoPreco;
            it->second.setNome(novoNome);
            it->second.setPreco(novoPreco);
            cout << "Produto alterado com sucesso!"; 
            cout <<"ANTIGO => Nome: " << nomeProduto << "Preco: " << precoAntigo << endl;
            cout << "NOVO => Nome: " << novoNome << "Preco: " << novoPreco << endl;

            //abrir arquivo para leitura e escrita.
            fstream arquivoSuco("arquivoSuco.txt", ios::in | ios::out |ios::app);

            if(arquivoSuco.is_open()){
                string nomeNoArquivo, valorNoArquivo;
                string linha;
                
                while(getline(arquivoSuco, linha)){
                    if(linha.find(nomeProduto) == 0){
                        nomeNoArquivo = linha;
        
                        getline(arquivoSuco, linha);
                        //verificar se o preco se encontra na linha.
                        if(linha.find(precoAntigo) == 0){
                            valorNoArquivo = linha;
                            //converte o valor no arquivo para float para salvar no map.
                            float preco = stof(valorNoArquivo);

                            //atualiza o map com o nome e o preco antigo do produto.
                            produtos[nomeNoArquivo].setNome(nomeNoArquivo);   
                            produtos[valorNoArquivo].setPreco(preco);   
                        };        
                    };
                };
            };  

            //atualizar produto no map.
            produtos[nomeProduto].setNome(novoNome);
            produtos[nomeProduto].setPreco(novoPreco);  

            arquivoSuco.close();

            //abrir arquivo para leitura e escrita e escreve o map atualizado no arquivo
           //fstream arquivoSuco("arquivoSuco.txt", ios::in | ios::out |ios::app);
            for (const auto& produto : produtos) {
                    arquivoSuco << produto.first << "\n";
                    arquivoSuco << produto.second.getPreco() << "\n";
                }
            arquivoSuco.close();
            
        }else {
            cout << "Produto não encontrado." << endl;
        };
    };

    //se a escolha for alterar o sanduiche.
    //caso o cliente deseje ALTERAR um suco ou um sanduiche.
    if (escolha == SANDUICHE) {

        cout << "Você escolheu ALTERAR um sanduicge, informe o nome do suco que deseja alterar." << endl;
        getline(cin, nomeProduto);
        
        auto it = produtos.find(nomeProduto);
        
        //Verificar se o produto existe no map
        if (it != produtos.end()){
            //alteração do produto no map
            string novoNome;
            float novoPreco;
            float precoAntigo = it->second.getPreco();

            cout << "Digite o novo nome para o sanduiche: ";
            getline(cin, novoNome);
            cout << "Digite o  novo preco para o sanduiche: ";
            cin >> novoPreco;
            it->second.setNome(novoNome);
            it->second.setPreco(novoPreco);
            cout << "Produto alterado com sucesso!"; 
            cout <<"ANTIGO => Nome: " << nomeProduto << "Preco: " << precoAntigo << endl;
            cout << "NOVO => Nome: " << novoNome << "Preco: " << novoPreco << endl;

            //abrir arquivo para leitura e escrita.
            fstream arquivoSanduiche("arquivoSanduiche.txt", ios::in | ios::out |ios::app);


            if(arquivoSanduiche.is_open()){
                string nomeNoArquivo, valorNoArquivo;
                string linha;
                
                while(getline(arquivoSanduiche, linha)){
                    if(linha.find(nomeProduto) == 0){
                        nomeNoArquivo = linha;
        
                        getline(arquivoSanduiche, linha);
                        //verificar se o preco se encontra na linha.
                        if(linha.find(precoAntigo) == 0){
                            valorNoArquivo = linha;
                            //converte o valor no arquivo para float para salvar no map.
                            float preco = stof(valorNoArquivo);

                            //atualiza o map com o nome e o preco antigo do produto.
                            produtos[nomeNoArquivo].setNome(nomeNoArquivo);   
                            produtos[valorNoArquivo].setPreco(preco);   
                        };        
                    };
                };
            };  

            //atualizar produto no map.
            produtos[nomeProduto].setNome(novoNome);
            produtos[nomeProduto].setPreco(novoPreco);  

            arquivoSanduiche.close();

            //abrir arquivo para leitura e escrita e escreve o map atualizado no arquivo
            for (const auto& produto : produtos) {
                    arquivoSanduiche << produto.first << "\n";
                    arquivoSanduiche << produto.second.getPreco() << "\n";
                }
            arquivoSanduiche.close();
            
        }else {
            cout << "Produto não encontrado." << endl;
        };
    };
};

//listar produto
map<string, Produto> carregarProdutosDoArquivo(const int& escolha) {
    map<string, Produto> produtos;

    if(escolha == SUCO){
        string nomeArquivo = "arquivoSuco.txt";
        ifstream arquivo(nomeArquivo);
        
        cout << "Itens:\n";

        string linha;
        while (getline(arquivo, linha)) {
            
            if (linha.find("Item: ") == 0) {
                Produto produto;
                produto.setNome(linha.substr(6));//Extrai o nome do produto e coloca no atributo

                if (std::getline(arquivo, linha) && linha.find("Preço: ") == 0) {
                    produto.setPreco(std::stof(linha.substr(7)));  // Extrai e converte o preço
                    produtos[produto.getNome()] = produto;  // Adiciona o produto ao mapa
                }
            }
            arquivo.close();
            return produtos;
        }
    
    } else if(escolha == SANDUICHE){
        string nomeArquivo = "arquivoSanduiche.txt";
        ifstream arquivo(nomeArquivo);
        
        cout << "Itens:\n";

        string linha;
        while (getline(arquivo, linha)) {
            
            if (linha.find("Item: ") == 0) {
                Produto produto;
                produto.setNome(linha.substr(6));//Extrai o nome do produto e coloca no atributo

                if (std::getline(arquivo, linha) && linha.find("Preço: ") == 0) {
                    produto.setPreco(std::stof(linha.substr(7)));  // Extrai e converte o preço
                    produtos[produto.getNome()] = produto;  // Adiciona o produto ao mapa
                }
        }

        arquivo.close();
        return produtos;
        }

    } else if(escolha == CARRINHO){
        string nomeArquivo = "arquivoCarrinho.txt";
        ifstream arquivo(nomeArquivo);
        
        cout << "Itens:\n";

        string linha;
        while (getline(arquivo, linha)) {
            
            if (linha.find("Item: ") == 0) {
                Produto produto;
                produto.setNome(linha.substr(6));//Extrai o nome do produto e coloca no atributo

                if (std::getline(arquivo, linha) && linha.find("Preço: ") == 0) {
                    produto.setPreco(std::stof(linha.substr(7)));  // Extrai e converte o preço
                    produtos[produto.getNome()] = produto;  // Adiciona o produto ao mapa
                }
        }

        arquivo.close();
        return produtos;
        }
    }
}

//escolher produto e adicionar ao carrinho SE DER TEMPO EU FAÇO
/* void adicionarAoCarrinho(map<string, Produto>& carrinho, const Produto& produto) {
    carrinho[produto.getNome()] = produto;
    cout << "Produto adicionado ao carrinho: " << produto.getNome() << " (R$" << produto.getPreco() << ")\n";

    fstream arquivoCarrinho("arquivoCarrinho.txt", std::ios::out|std::ios::in|std::ios::app);

    if(arquivoCarrinho.is_open()){

    }
} */