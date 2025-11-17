#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

using namespace std;

class Utils
{
    public:
        Utils();
        void print_tabuleiro(const vector<int>& tabuleiro);
        int obter_elemento_aleatorio(vector<int>& vec);
};

#endif