#ifndef CONSTRUCAO_HPP
#define CONSTRUCAO_HPP

#include <vector>

#include "Utils.hpp"

using namespace std;

class Construcao
{
    private:
        Utils utils;

    public:
        Construcao(); 
        vector<int> constroi_solucao_inicial_gulosa(int n);
        vector<int> constroi_solucao_inicial_aleatoria(int n);
};

#endif