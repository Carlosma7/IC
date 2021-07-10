#ifndef GENETICALBALDWINIANALGORITHM_H
#define GENETICALBALDWINIANALGORITHM_H

#include "solution.h"
#include "data.h"
#include "localsearch.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>

class GeneticalBaldwinianAlgorithm
{
private:
    vector<Solution> poblation;

    Solution final_solution;

    clock_t time;

    int max_iterations;
    
    int num_generations;

public:
    GeneticalBaldwinianAlgorithm(Data data, bool generational, bool position);

    void Generational(Data &data, bool position);

    void Estational(Data &data, bool position);

    Solution SelectionTournament();

    Solution Cross_position(Data &data, Solution &parent1, Solution &parent2);

    Solution Cross_OX(Data &data, Solution &parent1, Solution &parent2);

    Solution getSolution() const;

    float getTime() const;
    
    int getNumGenerations() const;
};

#endif // GENETICALBALDWINIANALGORITHM_H
