#include "localsearch.h"

Solution Local_Search::getSolution() const
{
    return solution;
}

float Local_Search::getTime() const
{
    return ((float)time)/CLOCKS_PER_SEC;
}

int Local_Search::getIterations() const
{
	return iterations;
}

Local_Search::Local_Search(Data data, Solution initial)
{
    solution = initial;

    vector<bool> dlb(data.size(), false);

    bool improve_flag = false;
    bool better_solution = false;
	while(!better_solution && (iterations < 400)){

        for(int i = 0; i < data.size() && (iterations <400); i++){

            if (!dlb[i]){
                improve_flag = false;

                for(int j = 0; j < data.size(); j++){
                    Solution new_solution = solution.two_opt(i,j, data);
                    iterations++;

                    if(new_solution.coste < solution.coste){
                        solution = new_solution;
                        dlb[i]=false;
                        dlb[j]=false;
                        improve_flag = true;
                        better_solution = true;
                    }

                }

                if (!improve_flag)
                        dlb[i] = true;
            }

            bool movement_possible = false;

            for(unsigned int j=0; j<dlb.size(); j++)
                if(dlb[j]==0)
                    movement_possible = true;

            if(!movement_possible)
                better_solution = true;
        }
	}
	
}
