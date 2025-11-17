#include "HillClimbing.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

HillClimbing::HillClimbing(vector<int> solucao_inicial, int max_steps_inicial) :
                            n(solucao_inicial.size()),
                            max_steps(max_steps_inicial),
                            posicoesDasRainhas(solucao_inicial)
{}

vector<int> HillClimbing::SolucaoHillClimbing()
{
    vector<int> tabuleiro_atual = posicoesDasRainhas;

    for (int iter = 0; iter < max_steps; iter++)
    {
        int custo_atual = calcular_custo_total(tabuleiro_atual);

        if (custo_atual == 0)
        {
            cout << endl << "Solucao encontrada em " << iter << " passos!" << endl;
            return tabuleiro_atual;
        }

        vector<int> melhor_vizinho;
        int custo_melhor_vizinho = INT_MAX; 

        for (int col = 0; col < n; col++)
        {
            for (int row = 0; row < n; row++)
            {
                if (tabuleiro_atual[col] == row) continue;

                vector<int> vizinho_teste = tabuleiro_atual;
                vizinho_teste[col] = row;
                int custo_vizinho = calcular_custo_total(vizinho_teste);

                if (custo_vizinho < custo_melhor_vizinho)
                {
                    custo_melhor_vizinho = custo_vizinho;
                    melhor_vizinho = vizinho_teste;
                }
            }
        }

        if (custo_melhor_vizinho >= custo_atual)
        {
            cout << endl << "Parou em minimo local apos " << iter << " passos." << endl  << endl;
            cout << "Custo final: " << custo_atual << " conflitos." << endl;
            return tabuleiro_atual;
        }

        tabuleiro_atual = melhor_vizinho;
    }

    cout << endl << "Não foi possível encontrar a solução em " << max_steps << " passos." << endl;
    cout << "Custo final: " << calcular_custo_total(tabuleiro_atual) << " conflitos." << endl;

    return {};
}

int HillClimbing::calcular_custo_total(vector<int>& tabuleiro)
{
    int custo_total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tabuleiro[i] == tabuleiro[j])
            {
                custo_total++;
            }
            else if (abs(tabuleiro[i] - tabuleiro[j]) == abs(i - j))
            {
                custo_total++;
            }
        }
    }

    return custo_total;
}