#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

Utils::Utils() {}

void Utils::print_tabuleiro(const vector<int>& tabuleiro)
{
    int n = tabuleiro.size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (tabuleiro[col] == row)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }

        cout << endl;
    }
}

// Obtem uma rainha aleatoria
int Utils::obter_elemento_aleatorio(vector<int>& vec)
{
    int idx = rand() % vec.size();
    return vec[idx];
}