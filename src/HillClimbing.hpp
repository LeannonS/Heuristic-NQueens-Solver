#ifndef HILLCLIMBING_HPP
#define HILLCLIMBING_HPP

#include <vector>
#include "Utils.hpp"

using namespace std;

class HillClimbing
{
    private:
        int n;
        int max_steps;
        vector<int> posicoesDasRainhas;
        Utils utils;

        int calcular_custo_total(vector<int>& tabuleiro);

    public:
        HillClimbing(vector<int> solucao_inicial, int max_steps_inicial);
        vector<int> SolucaoHillClimbing();
};

#endif