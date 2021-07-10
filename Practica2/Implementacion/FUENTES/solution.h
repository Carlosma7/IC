#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <data.h>

/***** GENERADOR DE NUMEROS PSEUDOALETORIOS *****/

/* used in random number generator below */
#define MASK 2147483647
#define PRIME 65539
#define SCALE 0.4656612875e-9

using namespace std;

class Solution
{
public:
    vector<int> solution;
    long coste = 0;

    static long Seed;

    Solution();
    Solution two_opt(int index1, int index2, Data &data);
    void cost_calculate(Data & data);
    int random_value(int min, int max);
    bool operator <(const Solution& s1) const;
    void set_coste(long nuevo_coste);
	long get_coste();
	void set_solution(vector<int> new_solution);
	vector<int> get_solution();
};
/*******************************************************************/
/*  Rand genera un numero real pseudoaleatorio entre 0 y 1,        */
/*  excluyendo el 1.						   */
/*  Randint genera un numero entero entre low y high, ambos 	   */
/*  incluidos.	   						   */
/*  Randfloat genera un numero real entre low y high, incluido low */
/*  y no incluido high                                             */
/*******************************************************************/

#define Rand()  (( Solution::Seed = ( (Solution::Seed * PRIME) & MASK) ) * SCALE )

#define Randint(low,high) ( (int) (low + (high-(low)+1) * Rand()))

#define Randfloat(low,high) ( (low + (high-(low))*Rand()))

#endif // SOLUTION_H
