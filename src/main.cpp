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
    cout << "RE: " ;
    cin >> escolha;

    switch (escolha)
    {
    case 1://gestor
        int res;
        res = validaGestor();
        if(res == true){
            menuGestor();
            cout << "RE: ";
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
            //CADASTRAR E SALVAR SANDUICHES NO ARQUIVO
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
            if(escolha == 7){
                //pendente
            }
            if(escolha == 8){
                //pendente
            }
            //VOLTAR AO MENU PRINCIPAL
            if(escolha == 9){
                main();
            }
            //EXTRA CADASTRAR PESSOA, MAS NÃO SALVA EM ARQUIVO TXT SÓ FICA NO MAP.
            if(escolha == 10){
                extras();
                cout << "RE: ";
                cin >> escolha;
                if(escolha == 1){
                    string pessoa;
                    cout << "Informe um nome para o Gestor: \n";
                    cin >> pessoa;
                    cadastrarGestor(pessoa);
                    cout << "Gestor cadastrado com sucesso! \n Retornando a main para realizar o login. \n";
                    main();
                } else if(escolha == 2){  
                    listarGestor();
                    cout << "Listagem de gestores: \n";
                    main();
                } else if(escolha == 3){  
                    string pessoa;
                    cout << "Informe um nome para o Gestor: \n";
                    cin >> pessoa;
                    cadastrarCliente(pessoa);
                    main();
                } else if(escolha == 4){  
                    listarCliente();
                    cout << "Listagem de clientes: \n";
                    main();
                }
            }
        }else {
            cout << "Senha incorreta! Reinicie a operacao." << endl;
        }
        break;
    case 2://cliente
        menuCliente();
        cout << "RE: ";
            cin >> escolha;
            //LISTAR SANDUICHES CADASTRADOS
            if(escolha == 1){
                carregarProdutosDoArquivo(SANDUICHE);
            }
            //LISTAR SUCOS CADASTRADOS
            if(escolha == 2){
                carregarProdutosDoArquivo(SUCO);
            }
            if(escolha == 7){
                main();
            }
        break;
    case 3://sair
        cout << "Obrigado, volte sempre!" << endl;
        break;
    
    default:
        cout << "Nenuma das alternativas foi escolhida, obrigado volte sempre!" << endl;
        break;
    }

    return 0;
}

