#include <iostream>
#include <vector>
#include <ctime>

#include "Menu.hpp"
#include "Construcao.hpp"
#include "MinConflicts.hpp"
#include "HillClimbing.hpp"
#include "Utils.hpp"

using namespace std;

int main()
{
    srand(time(0));

    const int N = 1000; // Número de rainhas no tabuleiro NxN
    const int MAX_STEPS = 5000; // Número máximo de iterações

    Menu menu;
    Construcao construtor;
    Utils utils;

    clock_t inicio_CPU, fim_CPU;

    vector<int> solucao_inicial;
    bool executando = true;

    while (executando)
    {
        int escolha_principal = menu.menu_principal(); 

        switch (escolha_principal)
        {  
            case 1: // Gerar Solução Inicial
            {
                int escolha_construcao = menu.menu_construcao(); 
                
                if (escolha_construcao == 1)
                {
                    solucao_inicial = construtor.constroi_solucao_inicial_gulosa(N);
                }
                else if (escolha_construcao == 2)
                {
                    solucao_inicial = construtor.constroi_solucao_inicial_aleatoria(N);
                }

                break;
            }
            
            case 2: // Resolve com MinConflicts
            {
                if (solucao_inicial.empty())
                {
                    cout << "Gere uma solucao inicial primeiro." << endl;
                }
                else
                {
                    MinConflicts MC(solucao_inicial, MAX_STEPS);

                    inicio_CPU = clock();
                    vector<int> solucao = MC.SolucaoMinConflicts();
                    fim_CPU = clock();

                    printf("Tempo execucao = %10.2f segundos\n",(float)(fim_CPU - inicio_CPU)/CLOCKS_PER_SEC);

                    if(N < 100) if (!solucao.empty()) utils.print_tabuleiro(solucao);
                }

                break;
            }

            case 3:
            {
                if (solucao_inicial.empty())
                {
                    cout << "Gere uma solucao inicial primeiro." << endl;
                }
                else
                {
                    HillClimbing HC(solucao_inicial, MAX_STEPS);

                    inicio_CPU = clock();
                    vector<int> solucao = HC.SolucaoHillClimbing();
                    fim_CPU = clock();

                    printf("Tempo execucao = %10.2f segundos\n",(float)(fim_CPU - inicio_CPU)/CLOCKS_PER_SEC);

                    if(N < 100) if (!solucao.empty()) utils.print_tabuleiro(solucao);
                }
                break;
            }

            case 0:
                executando = false;
                break;
        }
    }

    return 0;
}