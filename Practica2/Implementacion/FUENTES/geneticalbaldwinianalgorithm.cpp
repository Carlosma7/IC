#include "geneticalbaldwinianalgorithm.h"

GeneticalBaldwinianAlgorithm::GeneticalBaldwinianAlgorithm(Data data, bool generational, bool position)
{

    // Initialize 50 poblation
    poblation.resize(50);

    // Random solution
    for(unsigned int i = 0; i < poblation.size(); i++){
        poblation[i].solution.resize(data.size(), data.size());

        auto it = poblation[i].solution.begin();
        int x;

        for(int j=0; j<data.size(); j++){
            x = poblation[i].random_value(0, data.size()-1);
            it = find(poblation[i].solution.begin(), poblation[i].solution.end(), x);
            while(it!=poblation[i].solution.end()){
                x = poblation[i].random_value(0,data.size()-1);
                it = find(poblation[i].solution.begin(), poblation[i].solution.end(), x);
            }
            poblation[i].solution[j] = x;
        }
		poblation[i].cost_calculate(data);
    }
    
    num_generations = 1;

    if(generational)
        Generational(data, position);
    else
        Estational(data, position);

}

void GeneticalBaldwinianAlgorithm::Generational(Data &data, bool position)
{

    max_iterations = 50;    // Initial poblation

    clock_t time_initial, time_final;
    time_initial = clock();


    while(max_iterations < 50000){
    	// Local search for baldwinian variable of the algorithm
        for(Solution sol:poblation){
        	Local_Search local_search(data, sol);
        	sol.coste = local_search.getSolution().coste;
        }
        
    	// Sort poblation
        sort(poblation.begin(), poblation.end());

        // Selection
        vector<Solution> parents;
        for(int i = 0; i < 50; i++){
            parents.push_back(SelectionTournament());
        }

        // Cross position
        vector<Solution> children;
        Solution child1, child2;

        for(int i = 0; i < 36; i+=2){       // (0.7*poblation.size()) -> 36
           if(position){
               child1 = Cross_position(data, parents[i], parents[i+1]);
               child2 = Cross_position(data, parents[i], parents[i+1]);
           }else{
               child1 = Cross_OX(data, parents[i], parents[i+1]);
               child2 = Cross_OX(data, parents[i+1], parents[i]);
           }

           children.push_back(child1);
           children.push_back(child2);
           max_iterations += 2;
        }

        // Fill with the rest of parents
        for(unsigned int i=children.size(); i<poblation.size(); i++)
            children.push_back(parents[i]);

        // Mutation

        int expected_num_mutaciones = 0.001 * poblation[0].solution.size() * poblation.size();
        int gen_1, gen_2;
        for(int i=0; i< expected_num_mutaciones; i++){
            gen_1 = gen_2 = children[0].random_value(0, data.size()-1);

            while(gen_2 == gen_1){
                gen_2 = children[0].random_value(0, data.size()-1);
            }

            int random = children[0].random_value(0, poblation.size()-1);
            children[random] = children[random].two_opt(gen_1, gen_2, data);
			
			children[random].cost_calculate(data);
            max_iterations++;
        }

        // Sort children
        sort(children.begin(), children.end());

        // Elitism
        bool best_parent = false;
        for(unsigned int i=0; i<children.size(); i++)
                if(children[i].solution == poblation[0].solution)
                    best_parent = true;


        if(!best_parent)
            children[children.size()-1] = poblation[0];

        poblation = children;
        
        num_generations++;
    }

    if(poblation[0] < poblation[poblation.size() - 1])
        final_solution = poblation[0];
    else
        final_solution = poblation[poblation.size() - 1];

    time_final = clock();
    time = time_final - time_initial;
}

void GeneticalBaldwinianAlgorithm::Estational(Data &data, bool position)
{
    max_iterations = 50;    // Initial poblation

    clock_t time_initial, time_final;
    time_initial = clock();

    int mutations = 1000/(poblation[0].solution.size() * 2);
    int count_mutation = 0;

    while(max_iterations < 50000){
    	// Local search for baldwinian variable of the algorithm
        for(unsigned int i=0; i<poblation.size(); i++){
        	Local_Search local_search(data, poblation[i]);
        	poblation[i].set_coste(local_search.getSolution().get_coste());
        }
        
        // Sort poblation
        sort(poblation.begin(), poblation.end());

        // Selection
        vector<Solution> parents;
        for(int i = 0; i < 2; i++){
            parents.push_back(SelectionTournament());
        }

        // Cross position
        vector<Solution> children;
        Solution child1, child2;

        if(position){
            child1 = Cross_position(data, parents[0], parents[1]);
            child2 = Cross_position(data, parents[0], parents[1]);
        }else{
            child1 = Cross_OX(data, parents[0], parents[1]);
            child2 = Cross_OX(data, parents[1], parents[0]);
        }

        children.push_back(child1);
        children.push_back(child2);
        max_iterations += 2;


        count_mutation++;   // Count of mutations

        // Mutation
        if((count_mutation%mutations)==0 && count_mutation!=0){
            int random = children[0].random_value(0, children.size()-1);
            int gen_1, gen_2;
            gen_1 = gen_2 = children[0].random_value(0, data.size()-1);

            while(gen_2 == gen_1){
                gen_2 = children[0].random_value(0, data.size()-1);
            }

            children[random] = children[random].two_opt(gen_1, gen_2, data);
            
			children[random].cost_calculate(data);
            max_iterations++;
        }

        // Sort children
        sort(children.begin(), children.end());

        // Children instead of parents
        vector<Solution> children_change = children;
        children_change.push_back(poblation[poblation.size()-2]);
        children_change.push_back(poblation[poblation.size()-1]);
        sort(children_change.begin(), children_change.end());


        poblation[poblation.size()-2] = children_change[1];
        poblation[poblation.size()-1] = children_change[0];
        
        num_generations++;
    }

    if(poblation[0] < poblation[poblation.size() - 1])
        final_solution = poblation[0];
    else
        final_solution = poblation[poblation.size() - 1];

    time_final = clock();
    time = time_final - time_initial;
}

Solution GeneticalBaldwinianAlgorithm::SelectionTournament()
{
    // Selection
    int a = poblation[1].random_value(0, poblation.size()-1);
    int b = poblation[1].random_value(0, poblation.size()-1);

    while(a==b){
        b = poblation[1].random_value(0, poblation.size()-1);
    }

    if(a < b)
        return poblation[a];
    else
        return poblation[b];
}

Solution GeneticalBaldwinianAlgorithm::Cross_position(Data &data, Solution &parent1, Solution &parent2)
{
    Solution child;
    child.solution.resize(parent1.solution.size(), -1);

    for(unsigned int i=0; i<parent1.solution.size(); i++){
        if(parent1.solution[i] == parent2.solution[i])
            child.solution[i] = parent1.solution[i];
    }

    vector<int>::iterator it = child.solution.begin();
    int aux;

    for(unsigned int i=0; i<child.solution.size(); i++){
        if(child.solution[i]==-1){
            aux = child.random_value(0, child.solution.size()-1);
            it = find(child.solution.begin(), child.solution.end(), aux);

            while(it!=child.solution.end()){
                aux = child.random_value(0,child.solution.size()-1);
                it = find(child.solution.begin(), child.solution.end(), aux);

            }
            child.solution[i] = aux;
        }
    }


    // Calculate children cost
    child.cost_calculate(data);

    return child;
}

Solution GeneticalBaldwinianAlgorithm::Cross_OX(Data &data, Solution &parent1, Solution &parent2)
{
    int n_values_parent1 = data.size()/6;   // n/6
    int middle = parent1.solution.size()/2;
    int start_parent1 = (middle-(n_values_parent1/2));

    Solution child;
    child.solution.resize(parent1.solution.size(), -1);

    // Fill middle with first parent
    for(int i= start_parent1; i < (start_parent1 + n_values_parent1); i++){
        child.solution[i] = parent1.solution[i];
    }

    auto it = child.solution.begin();

    vector<int> aux_parent2;
    int pos_aux_parent2 = 0;

    for(unsigned int i=0; i < parent2.solution.size(); i++){
        it = find(child.solution.begin(), child.solution.end(), parent2.solution[i]);

        if(it==child.solution.end())
            aux_parent2.push_back(parent2.solution[i]);
    }

    it = find(child.solution.begin(), child.solution.end(), -1);

    int start_parent2= start_parent1 + n_values_parent1;

    while(it!=child.solution.end()){
        child.solution[start_parent2] = aux_parent2[pos_aux_parent2];
        pos_aux_parent2++;
        start_parent2 = (start_parent2 + 1)%child.solution.size();
        it = find(child.solution.begin(), child.solution.end(), -1);
    }

    // Calculate children cost
    child.cost_calculate(data);
    return child;


}

Solution GeneticalBaldwinianAlgorithm::getSolution() const
{
    return final_solution;
}

float GeneticalBaldwinianAlgorithm::getTime() const
{
    return ((float)time)/CLOCKS_PER_SEC;
}

int GeneticalBaldwinianAlgorithm::getNumGenerations() const
{
    return num_generations;
}
