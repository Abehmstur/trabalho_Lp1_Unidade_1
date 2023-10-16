#include <iostream>
#include "../src/gestor.cpp"
#include "../src/cliente.cpp"
#include "../src/mainMenu.cpp"
#include "../src/produto.cpp"
#include "../include/gestor.hpp"

int main()
{   
    system("clear");
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
            cout << "RE: " ;
            cin >> escolha;
            if(escolha == 1){}
            if(escolha == 2){}
            if(escolha == 3){}
            if(escolha == 4){}
            if(escolha == 5){}
            if(escolha == 6){}
            if(escolha == 7){}
            if(escolha == 8){}
            if(escolha == 9){}
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

