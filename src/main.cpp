#include <iostream>
#include "../src/gestor.cpp"
#include "../src/cliente.cpp"
#include "../src/mainMenu.cpp"
#include "../src/produto.cpp"
#include "../include/gestor.hpp"

int main()
{   
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
            if(escolha == 1){
                carregarProdutosDoArquivo(SANDUICHE);
            }
            if(escolha == 2){
                carregarProdutosDoArquivo(SUCO);
            }
            if(escolha == 3){
                salvarArquivo(SANDUICHE, produto);
            }
            if(escolha == 4){
                salvarArquivo(SUCO, produto);
            }
            if(escolha == 5){
                alterarProduto(SANDUICHE, produto);
            }
            if(escolha == 6){
                alterarProduto(SUCO, produto);
            }
            if(escolha == 7){
                //pendente
            }
            if(escolha == 8){
                //pendente
            }
            if(escolha == 9){
                main();
            }
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

