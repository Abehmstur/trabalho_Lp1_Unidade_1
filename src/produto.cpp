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

//funcao cadastrar novo produto
void cadastrarProduto(std::map<std::string, Produto>& produtos) {
    string nome;
    cout << "Informe o nome do produto: " << endl;
    cout << "RE: " << endl;
    cin >> nome;

    Produto novoProduto;
    novoProduto.setNome(nome);
    produtos[nome] = novoProduto;
}

//funcao para salvar os produtos em arquivos diferentes
void salvarArquivo(int escolha, map<string, Produto>& produto) {
    float preco_produto = 0.0;
    //caso o cliente deseje cadastrar um suco ou um sanduiche.
    if (escolha == SUCO) {
        fstream arquivoSuco("arquivoSuco.txt", ios::out | ios::app);

        cout << "Voce escolheu cadastrar um suco, informe o nome e o preco." << endl;

        for (auto& it : produto) {
            string nomeSuco = it.first;

            cout << "Produto: " << nomeSuco << endl;
            arquivoSuco << "Item: " << nomeSuco << endl;

            cout << "Informe o preco do produto: ";
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

            cout << "Produto: " << nomeSanduiche << endl;
            arquivoSanduiche << "Item: " << nomeSanduiche << endl;

            cout << "Informe o preco do produto: ";
            cin >> preco_produto;
            it.second.setPreco(preco_produto);

            arquivoSanduiche << "Preço: " << preco_produto << endl;
        }
        
        arquivoSanduiche.close();
    }
}

//alterar produto
void alterarProduto(int escolha, map<string, Produto>& produtos) {
    string nomeProduto;

    // Caso o cliente deseje ALTERAR um suco ou um sanduíche.
    if (escolha == SUCO || escolha == SANDUICHE) {
        string nomeArquivo;
        if (escolha == SUCO) {
            nomeArquivo = "arquivoSuco.txt";
            cout << "Voc escolheu ALTERAR um suco, informe o nome do suco que deseja alterar: ";
        } else {
            nomeArquivo = "arquivoSanduiche.txt";
            cout << "Voce escolheu ALTERAR um sanduiche, informe o nome do sanduoche que deseja alterar: ";
        }

        cin.ignore();  // Limpar o buffer para garantir que a entrada funcione corretamente
        getline(cin, nomeProduto);

        // Abrir o arquivo para leitura e escrita
        fstream arquivo(nomeArquivo, ios::in | ios::out);

        if (arquivo.is_open()) {
            string linha;

            while (getline(arquivo, linha)) {
                if (linha.find("Item: " + nomeProduto) != string::npos) {
                    // Encontramos o produto
                    string nomeNoArquivo = linha;

                    // Ler a linha do preço
                    getline(arquivo, linha);

                    // Verificar se o preço se encontra na linha.
                    if (linha.find("Preço: ") == 0) {
                        string valorNoArquivo = linha.substr(7);
                        float precoAntigo = stof(valorNoArquivo);

                        string novoNome, novoPrec;
                        float novoPreco;

                        cout << "Digite o novo nome para o produto: ";
                        getline(cin, novoNome);

                        cout << "Digite o novo prec para o produoto: ";
                        getline(cin, novoPrec);
                        novoPreco = stof(novoPrec);

                        // Atualiza o map com o novo nome e o novo preco do produto.
                        produtos[nomeNoArquivo].setNome("Item: " + novoNome);
                        produtos[nomeNoArquivo].setPreco(novoPreco);

                        cout << "Produto alterado com sucesso!\n";
                        cout << "ANTIGO => Nome: " << nomeNoArquivo << ", Preco: " << precoAntigo << endl;
                        cout << "NOVO => Nome: " << "Item: " + novoNome << ", Preco: " << novoPreco << endl;
                    }
                }
            }
            // Abrir arquivo para leitura e escrita e escrever o mapa atualizado no arquivo
            fstream arquivoAtualizado(nomeArquivo, ios::out | ios::trunc);
             for (const auto& produto : produtos) {
            arquivoAtualizado << "Item: " << produto.second.getNome() << "\n";
            arquivoAtualizado << "Preço: " << produto.second.getPreco() << "\n";
            }
            arquivo.close();
        } else {
            cout << "Não foi possuvel abrir o arquivo." << endl;
        }
    }
}

//listar produtos
map<string, Produto> carregarProdutosDoArquivo(const int& escolha) {
    map<string, Produto> produtos;

    string nomeArquivo;
    //Aqui vai determinar qual item arquivo será chamaado.
    if (escolha == SUCO) {
        nomeArquivo = "arquivoSuco.txt";
    } else if (escolha == SANDUICHE) {
        nomeArquivo = "arquivoSanduiche.txt";
    } else if (escolha == CARRINHO) {
        nomeArquivo = "arquivoCarrinho.txt";
    } else {
        cout << "Escolha inválida!" << endl;
        return produtos;
    }

    ifstream arquivo(nomeArquivo);
    
    //validacao caso o arquivo não abra.
    if (!arquivo.is_open()) {
        cerr << "Nao foi possivel abrir o arquivo." << endl;
        return produtos;
    }

    cout << "Itens:" << endl;

    string linha;
    //enquanto o arquivo está sendo lido.
    while (getline(arquivo, linha)) {
        if (linha.find("Item: ") == 0) {
            Produto produto;
            produto.setNome(linha.substr(6));

            if (getline(arquivo, linha) && linha.find("Preço: ") == 0) {
                produto.setPreco(std::stof(linha.substr(7)));
                produtos[produto.getNome()] = produto;
                cout << "Nome: " << produto.getNome() << ", Preco: " << produto.getPreco() << endl;
            }
        }
    }

    arquivo.close();
    return produtos;
}

//escolher produto e adicionar ao carrinho SE DER TEMPO EU FAÇO
/* void adicionarAoCarrinho(map<string, Produto>& carrinho, const Produto& produto) {
    carrinho[produto.getNome()] = produto;
    cout << "Produto adicionado ao carrinho: " << produto.getNome() << " (R$" << produto.getPreco() << ")\n";

    fstream arquivoCarrinho("arquivoCarrinho.txt", std::ios::out|std::ios::in|std::ios::app);

    if(arquivoCarrinho.is_open()){

    }
} */