#include "MinConflicts.hpp"
#include <iostream>
#include <cmath>
#include <set>
#include <ctime>

MinConflicts::MinConflicts(vector<int> solucao_inicial, int max_steps) : 
                            posicoesDasRainhas(solucao_inicial),
                            max_steps(max_steps),
                            n(solucao_inicial.size())
{
    srand(time(0));
}

vector<int> MinConflicts::SolucaoMinConflicts()
{
    for (int i = 0; i < max_steps; i++)
    {
        // Pega a coluna de todas rainhas que estão em conflito
        vector<int> rainhas_conflitantes = obter_rainhas_conflitantes();

        if (rainhas_conflitantes.empty())
        {
            cout << endl << "Solucao encontrada em " << i << " passos!" << endl;
            return posicoesDasRainhas;
        }

        // Pega aleatoriamente uma das rainhas em conflito
        int col = utils.obter_elemento_aleatorio(rainhas_conflitantes);
        int min_conflitos = n + 1;
        vector<int> best_values;

        for (int row = 0; row < n; row++)
        {
            // Conta quantos conflitos tem caso coloque a rainha na linha row
            int conflitos = contar_conflitos_da_posicao(col, row);

            if (conflitos < min_conflitos)
            {
                min_conflitos = conflitos;
                best_values.clear();
                best_values.push_back(row);
            }
            else if (conflitos == min_conflitos)
            {
                best_values.push_back(row);
            }
        }

        // Escolhe aleatoriamente um dos melhores valores
        int best_row = utils.obter_elemento_aleatorio(best_values);
        posicoesDasRainhas[col] = best_row;
    }

    cout << endl << "Não foi possível encontrar a solução em " << max_steps << " passos." << endl;

    return {};
}

// Conta quantos conflitos tem em uma determinada pos
int MinConflicts::contar_conflitos_da_posicao(int col, int row)
{
    int conflitos = 0;

    for (int new_col = 0; new_col < n; new_col++)
    {
        if (new_col == col) continue; 

        int new_row = posicoesDasRainhas[new_col]; 

        if (new_row == row)
        { 
            conflitos++;
        }
        else if (abs(new_row - row) == abs(new_col - col))
        {
            conflitos++;
        }
    }

    return conflitos;
}

// Verifica quais rainhas estão em conflito
vector<int> MinConflicts::obter_rainhas_conflitantes()
{
    set<int> rainhas_conflitantes; 

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (posicoesDasRainhas[i] == posicoesDasRainhas[j] || abs(posicoesDasRainhas[i] - posicoesDasRainhas[j]) == abs(i - j))
            {
                rainhas_conflitantes.insert(i);
                rainhas_conflitantes.insert(j);
            }
        }
    }

    return vector<int>(rainhas_conflitantes.begin(), rainhas_conflitantes.end());
}