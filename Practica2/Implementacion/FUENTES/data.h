#ifndef DATA_H
#define DATA_H
#include <vector>
#include <fstream>

using namespace std;

class Data
{
private:
    // File name
    string file_name;
    // Distance matrix
    vector<vector<int>> distances;

    // Stream matrix
    vector<vector<int>> stream;
public:
    // Constructor
    Data(string file);

    // Get stream

    int getDistances(int i, int j) const;
    int getStream(int i, int j) const;
    int size();
};

#endif // DATA_H
