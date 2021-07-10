#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include "solution.h"
#include "data.h"
#include <vector>
#include <limits>
#include <algorithm>
#include <time.h>
#include <iostream>

class Local_Search
{
private:

    Solution solution;

    clock_t time;
    
    int iterations;

public:
    Local_Search(Data data, Solution initial);

    float getTime() const;

    Solution getSolution() const;
    
    int getIterations() const;
};

#endif // LOCAL_SEARCH_H
