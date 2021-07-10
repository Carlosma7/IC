#ifndef GENETICALLAMARCKIANALGORITHM_H
#define GENETICALLAMARCKIANALGORITHM_H

#include "solution.h"
#include "data.h"
#include "localsearch.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>

class GeneticalLamarckianAlgorithm
{
private:
    vector<Solution> poblation;

    Solution final_solution;

    clock_t time;

    int max_iterations;
    
    int num_generations;

public:
    GeneticalLamarckianAlgorithm(Data data, bool generational, bool position);

    void Generational(Data &data, bool position);

    void Estational(Data &data, bool position);

    Solution SelectionTournament();

    Solution Cross_position(Data &data, Solution &parent1, Solution &parent2);

    Solution Cross_OX(Data &data, Solution &parent1, Solution &parent2);

    Solution getSolution() const;

    float getTime() const;
    
    int getNumGenerations() const;
};

#endif // GENETICALLAMARCKIANALGORITHM_H
