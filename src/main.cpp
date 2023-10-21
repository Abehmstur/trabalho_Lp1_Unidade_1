#include <iostream>
#include "../src/gestor.cpp"
#include "../src/cliente.cpp"
#include "../src/mainMenu.cpp"
#include "../src/produto.cpp"
#include "../include/gestor.hpp"

int main()
{   
    //Adicionar alguns produtos ao mapa antes de salvar
    map<string, Produto> produtos;

    int escolha;
    //Chamar menu Principal
    menuPrincipal();
    std::cout << "RE: " ;
    cin >> escolha;

    switch (escolha)
    {
    case 1://gestor
        int res;
        res = validaGestor();
        if(res == true){
            menuGestor();
            std::cout << "RE: ";
            cin >> escolha;
            //LISTAR SANDUICHES CADASTRADOS
            if(escolha == 1){
                carregarProdutosDoArquivo(SANDUICHE);
            }
            //LISTAR SUCOS CADASTRADOS
            if(escolha == 2){
                carregarProdutosDoArquivo(SUCO);
            }
            //CADASTRAR E SALVAR SANDUICHES NO ARQUIVO
            if(escolha == 3){
                //adição de alguns produtos para criar o arquivo txt
                /* Produto sanduicheNatural;
                sanduicheNatural.setNome("Sanduiche natural");
                sanduicheNatural.setPreco(1.00);
                produtos["SanduicheNatural"] = sanduicheNatural;

                Produto mistoQuente;
                mistoQuente.setNome("Misto Quente");
                mistoQuente.setPreco(5.00);
                produtos["MistoQuente"] = mistoQuente; */
                
                //cadastrar produtos
                cadastrarProduto(produtos);
                //salvar map preenchido no arquivo
                salvarArquivo(SANDUICHE, produtos);
            }
            //CADASTRAR E SALVAR SUCOS NO ARQUIVO
            if(escolha == 4){
                //adição de alguns produtos para criar o arquivo txt
                /* Produto sucoLaranja;
                sucoLaranja.setNome("Suco de Laranja");
                sucoLaranja.setPreco(2.50);
                produtos["SucoLaranja"] = sucoLaranja;

                Produto sucoUva;
                sucoUva.setNome("Suco de Uva");
                sucoUva.setPreco(3.00);
                produtos["SucoUva"] = sucoUva; */
                cadastrarProduto(produtos);

                salvarArquivo(SUCO, produtos);
            }
            //ALTERAR NOME E PRECO DO SANDUICHE
            if(escolha == 5){
                alterarProduto(SANDUICHE, produtos);
            }
            //ALTERAR NOME E PRECO DO SUCO
            if(escolha == 6){
                alterarProduto(SUCO, produtos);
            }
            //EXCLUIR SANDUICHE
            if(escolha == 7){
                excluirProduto(SANDUICHE, produtos); 
            }
            //EXCLUIR SUCO
            if(escolha == 8){
                excluirProduto(SUCO, produtos);
            }
            //VOLTAR AO MENU PRINCIPAL
            if(escolha == 9){
                main();
            }
            //EXTRA CADASTRAR PESSOA, MAS NÃO SALVA EM ARQUIVO TXT SÓ FICA NO MAP.
            if(escolha == 10){
                extras();
                std::cout << "RE: ";
                cin >> escolha;
                if(escolha == 1){
                    string pessoa;
                    std::cout << "Informe um nome para o Gestor: \n";
                    cin >> pessoa;
                    cadastrarGestor(pessoa);
                    std::cout << "Gestor cadastrado com sucesso! \n Retornando a main para realizar o login. \n";
                    main();
                } else if(escolha == 2){  
                    listarGestor();
                    std::cout << "Listagem de gestores: \n";
                    main();
                } else if(escolha == 3){  
                    string pessoa;
                    std::cout << "Informe um nome para o Gestor: \n";
                    cin >> pessoa;
                    cadastrarCliente(pessoa);
                    main();
                } else if(escolha == 4){  
                    listarCliente();
                    std::cout << "Listagem de clientes: \n";
                    main();
                }
            }
        }else {
            std::cout << "Senha incorreta! Reinicie a operacao." << endl;
        }
        break;
    case 2://cliente
        menuCliente();
        std::cout << "RE: ";
            cin >> escolha;
            //LISTAR SANDUICHES CADASTRADOS
            if(escolha == 1){
                carregarProdutosDoArquivo(SANDUICHE);
            }
            //LISTAR SUCOS CADASTRADOS
            if(escolha == 2){
                carregarProdutosDoArquivo(SUCO);
            }
            //ESCOLHER LANCHE
            if(escolha == 3){
                //antes de chamar a funcao escolher, lista os produtos.
                cout << "Você desejou escoljer o lanche, segue as opções: " << endl;
                cout << "=========== SANDUICHES ===========" << endl;
                carregarProdutosDoArquivo(SANDUICHE);
                escolherProduto(SANDUICHE, produtos);
                cout << "=========== SUCOS ===========" << endl;
                carregarProdutosDoArquivo(SUCO);
                escolherProduto(SUCO, produtos);
                cout << "=========== xxxxx ===========" << endl;

                cout << "Produtos escolhidos com sucesso! Gostaria de retornar ao Main Menu? (0) para SIM - (1) para NAO \n RE: ";
                int newEscolha;
                cin >> newEscolha;
                while (newEscolha != 0 && newEscolha != 1) {
                    cout << "Escolha inválida! Tente novamente! \n (0) para SIM - (1) para NAO \n RE: ";
                    cin >> newEscolha;
                }
                if(newEscolha == 0){
                    cout << "Retornando ao MAIN MENU!" << endl;
                    main();
                } else {
                    cout << "Pedido realizado!" << endl;
                }
            }
            if(escolha == 4){
                cout << "TOTAL: R$" << calcularPreco();
            } 
            if(escolha == 5){
                cout << "=== Produtos no carrinho === " << endl;
                carregarProdutosDoArquivo(CARRINHO);
            }
            if(escolha == 6){
                cout << "=== Excluir produtos do carrinho === " << endl;
                excluirProduto(CARRINHO, produtos);
            } 
            if(escolha == 7){
                main();
            }
        break;
    case 3://sair
        std::cout << "Obrigado, volte sempre!" << endl;
        break;
    
    default:
        std::cout << "Nenuma das alternativas foi escolhida, obrigado volte sempre!" << endl;
        break;
    }

    return 0;
}

