#include "solution.h"

Solution::Solution()
{

}

Solution Solution::two_opt(int r, int s, Data & data)
{
    Solution sol = *this;

    swap(sol.solution[r], sol.solution[s]);

    for(unsigned int k = 0; k < solution.size(); k++){
        if((int)k!=r && (int)k!=s)
        sol.coste += data.getStream(r, k) * (data.getDistances(solution[s],solution[k]) - data.getDistances(solution[r],solution[k]))
                + data.getStream(s, k) * (data.getDistances(solution[r],solution[k]) - data.getDistances(solution[s],solution[k]))
                + data.getStream(k, r) * (data.getDistances(solution[k],solution[s]) - data.getDistances(solution[k],solution[r]))
                + data.getStream(k, s) * (data.getDistances(solution[k],solution[r]) - data.getDistances(solution[k],solution[s]));
    }


    return sol;

}

void Solution::cost_calculate(Data & data)
{
    coste = 0;

    for(unsigned int i=0; i< solution.size(); i++)
        for(unsigned int j=0; j< solution.size(); j++)
            coste += data.getStream(i,j) * data.getDistances(solution[i], solution[j]);
}

int Solution::random_value(int min, int max)
{
    return Randint(min, max);
}

bool Solution::operator <(const Solution &s1) const
{
    return (*this).coste < s1.coste;

}

void Solution::set_coste(long nuevo_coste){
	coste = nuevo_coste;
}

long Solution::get_coste(){
	return coste;
}

void Solution::set_solution(vector<int> new_solution){
	solution = new_solution;
}

vector<int> Solution::get_solution(){
	return solution;
}
