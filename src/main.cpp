#include <iostream>
#include "../src/gestor.cpp"
#include "../src/cliente.cpp"
#include "../src/mainMenu.cpp"

int main()
{   
    int resposta;
    //Chamar menu Principal
    menuPrincipal();
    cout << "RE: " ;
    cin >> resposta;

    switch (resposta)
    {
    case 1:
        validaGestor();
        break;
    case 2:
        /* code */
        break;
    case 3:
        cout << "Obrigado, volte sempre!" << endl;
        break;
    
    default:
        cout << "Nenuma das alternativas foi escolhida, obrigado volte sempre!" << endl;
        break;
    }

    return 0;
}

