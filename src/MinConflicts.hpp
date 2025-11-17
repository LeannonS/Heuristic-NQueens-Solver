#ifndef MINCONFLICTS_HPP
#define MINCONFLICTS_HPP

#include <vector>
#include <random>

#include "Utils.hpp"

using namespace std;

class MinConflicts
{
    private:
        vector<int> posicoesDasRainhas; 
        int max_steps;
        int n;
        Utils utils;

        int contar_conflitos_da_posicao(int var_col, int value_row);
        vector<int> obter_rainhas_conflitantes();

    public:
        MinConflicts(vector<int> solucao_inicial, int max_steps);
        vector<int> SolucaoMinConflicts();
};

#endif