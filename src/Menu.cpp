#include "Menu.hpp"
#include <iostream> 

int Menu::menu_principal()
{
    int escolha = -1;

    while (escolha < 0 || escolha > 3)
    {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "1. Gerar Solucao Inicial" << endl;
        cout << "2. Resolver com MinConflicts" << endl;
        cout << "3. Resolver com Hill Climbing" << endl;
        cout << "0. Finalizar" << endl;
        cout << "Escolha uma opcao: ";

        cin >> escolha;

        if (escolha < 0 || escolha > 3) cout << "Opcao invalida." << endl;
    } 

    return escolha;
}

int Menu::menu_construcao()
{
    int escolha = -1;

    while (escolha < 1 || escolha > 2)
    {
        cout << "\n--- Gerar Solucao ---" << endl;
        cout << "1. Gerar Solucao Gulosa" << endl;
        cout << "2. Gerar Solucao Aleatoria" << endl;
        cout << "Escolha um tipo: ";

        cin >> escolha;

        if (escolha < 1 || escolha > 2) cout << "Opcao invalida." << endl;
    } 

    return escolha;
}