#include "data.h"
#include <iostream>

int Data::getDistances(int i, int j) const
{
    return distances[i][j];
}

int Data::getStream(int i, int j) const
{
    return stream[i][j];
}

int Data::size()
{

    return stream.size();
}

Data::Data(string file)
{
    file_name = file;
    ifstream input(file);

    cout << "Probando con fichero: " << file << endl;
    if(!input){
        cerr << "Error, el fichero de entrada no ha podido abrirse.\n\n";
        exit(-1);
    }

    int tam;

    input >> tam;

    distances.resize(tam);
    stream.resize(tam);

    for(int i=0; i<tam; i++){
        distances[i].resize(tam);
        stream[i].resize(tam);
    }

    for(int i=0; i<tam; i++)
        for(int j=0; j<tam; j++){
            input >> stream[i][j];
        }

    for(int i=0; i<tam; i++)
        for(int j=0; j<tam; j++){
            input >> distances[i][j];
        }
}
