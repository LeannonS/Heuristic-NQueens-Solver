# NQueens-Heuristics (Solucionador das N-Rainhas)

Este projeto é porpõe solucionar o problema de computação das **N-Rainhas**, com ma implementação em C++. O objetivo é comparar diferentes meta-heurísticaspara encontrar uma solução onde nenhuma rainha possa atacar a outra em um tabuleiro N x N.

## Código-fonte

O código é separado por diversos arquivos, sendo eles:

* `main.cpp`: Ponto de entrada. Inicializa os objetos principais e inicia o loop do menu.
* `Menu (.hpp/.cpp)`: Exibe os menus de escolha para o usuário.
* `Construcao (.hpp/.cpp)`: Responsável por criar diferentes tipos de solução.
* `MinConflicts (.hpp/.cpp)`: Implementação do algoritmo de resolução Min-Conflicts.
* `HillClimbing (.hpp/.cpp)`: Implementação do algoritmo de resolução Hill Climbing (Steepest Ascent).
* `Utils (.hpp/.cpp)`: Classe utilitária com funções de apoio (impressão do tabuleiro, geração de elementos aleatórios de um vetor).


## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contato

✉️ <i>leanndrosousac@gmail.com</i>
</a>