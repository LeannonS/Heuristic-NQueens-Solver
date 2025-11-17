#include "Construcao.hpp"
#include <cstdlib> // Para rand()
#include <cmath>   // Para abs()
#include <vector>

using namespace std;

Construcao::Construcao() {}

// Constroi uma solução inicial de forma gulosa
vector<int> Construcao::constroi_solucao_inicial_gulosa(int n)
{
    vector<int> posicoesDasRainhas(n); 

    for (int col = 0; col < n; ++col)
    {
        int min_conflicts = n + 1;
        vector<int> best_rows;

        // Conta o número de conflitos para cada linha
        for (int row = 0; row < n; ++row)
        {
            int current_conflicts = 0;

            for (int prev_col = 0; prev_col < col; ++prev_col)
            {
                if (posicoesDasRainhas[prev_col] == row)
                { 
                    current_conflicts++;
                }
                else if (abs(posicoesDasRainhas[prev_col] - row) == abs(prev_col - col))
                {
                    current_conflicts++;
                }
            }

            if (current_conflicts < min_conflicts)
            {
                min_conflicts = current_conflicts;
                best_rows.clear();
                best_rows.push_back(row);
            }
            else if (current_conflicts == min_conflicts)
            {
                best_rows.push_back(row);
            }
        }

        // Escolhe aleatoriamente um dos melhores valores
        posicoesDasRainhas[col] = utils.obter_elemento_aleatorio(best_rows);
    }

    return posicoesDasRainhas;
}

// Constroi uma solução inicial de forma aleatoria
vector<int> Construcao::constroi_solucao_inicial_aleatoria(int n)
{
    vector<int> posicoesDasRainhas(n);

    for (int col = 0; col < n; ++col)
    {
        posicoesDasRainhas[col] = rand() % n;
    }

    return posicoesDasRainhas;
}