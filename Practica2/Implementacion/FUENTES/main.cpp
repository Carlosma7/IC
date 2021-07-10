#include <iostream>

#include "geneticalalgorithm.h"
#include "geneticalbaldwinianalgorithm.h"
#include "geneticallamarckianalgorithm.h"

using namespace std;

long Solution::Seed = 0;

int main(int argc, char *argv[])
{
    if(argc<4){
        cerr << "Numero de parametros incorrecto. El formato correcto es: " << endl;
        cerr << "./practica1 <algoritmo> <fichero> <semilla>" << endl;
        cerr << "Los algoritmos son:" << endl;
        cerr << "1  -> AGG-Posicion" << endl;
        cerr << "2  -> AGG-Posicion Baldwiniano" << endl;
        cerr << "3  -> AGG-Posicion Lamarckiano" << endl;
        cerr << "4  -> AGG-OX" << endl;
        cerr << "5  -> AGG-OX Baldwiniano" << endl;
        cerr << "6  -> AGG-OX Lamarckiano" << endl;
        cerr << "7  -> AGE-Posicion" << endl;
        cerr << "8  -> AGE-Posicion Baldwiniano" << endl;
        cerr << "9  -> AGE-Posicion Lamarckiano" << endl;
        cerr << "10 -> AGE-OX" << endl;
        cerr << "11 -> AGE-OX Baldwiniano" << endl;
        cerr << "12 -> AGE-OX Lamarckiano" << endl;
        exit(-1);
    }

    int algoritmo_ejecutar = atoi(argv[1]);
    Data data(argv[2]);
    Solution::Seed = atoi(argv[3]);

    switch (algoritmo_ejecutar) {
    	case 1:
            {
                GeneticalAlgorithm aggpos(data, true, true);
                cout << "El coste es: " << aggpos.getSolution().coste << endl;
                cout << "El tiempo es: " << aggpos.getTime() << endl;
                cout << "El numero de generaciones es: " << aggpos.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico generacional con cruce posicion: ";
                for(unsigned int i=0; i<aggpos.getSolution().solution.size(); i++)
                    cout << aggpos.getSolution().solution[i] << " ";
                break;
            }
        case 2:
            {
                GeneticalBaldwinianAlgorithm aggpos_baldwin(data, true, true);
                cout << "El coste es: " << aggpos_baldwin.getSolution().coste << endl;
                cout << "El tiempo es: " << aggpos_baldwin.getTime() << endl;
                cout << "El numero de generaciones es: " << aggpos_baldwin.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico generacional baldwiniano con cruce posicion: ";
                for(unsigned int i=0; i<aggpos_baldwin.getSolution().solution.size(); i++)
                    cout << aggpos_baldwin.getSolution().solution[i] << " ";
                break;
            }
        case 3:
            {
                GeneticalLamarckianAlgorithm aggpos_lamarck(data, true, true);
                cout << "El coste es: " << aggpos_lamarck.getSolution().coste << endl;
                cout << "El tiempo es: " << aggpos_lamarck.getTime() << endl;
                cout << "El numero de generaciones es: " << aggpos_lamarck.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico generacional lamarckiano con cruce posicion: ";
                for(unsigned int i=0; i<aggpos_lamarck.getSolution().solution.size(); i++)
                    cout << aggpos_lamarck.getSolution().solution[i] << " ";
                break;
            }
        case 4:
            {
                GeneticalAlgorithm aggox(data, true, false);
                cout << "El coste es: " << aggox.getSolution().coste << endl;
                cout << "El tiempo es: " << aggox.getTime() << endl;
                cout << "El numero de generaciones es: " << aggox.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico generacional con cruce ox: ";
                for(unsigned int i=0; i<aggox.getSolution().solution.size(); i++)
                    cout << aggox.getSolution().solution[i] << " ";
                break;
            }
        case 5:
            {
                GeneticalBaldwinianAlgorithm aggox_baldwin(data, true, false);
                cout << "El coste es: " << aggox_baldwin.getSolution().coste << endl;
                cout << "El tiempo es: " << aggox_baldwin.getTime() << endl;
                cout << "El numero de generaciones es: " << aggox_baldwin.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico generacional baldwiniano con cruce ox: ";
                for(unsigned int i=0; i<aggox_baldwin.getSolution().solution.size(); i++)
                    cout << aggox_baldwin.getSolution().solution[i] << " ";
                break;
            }
        case 6:
            {
                GeneticalLamarckianAlgorithm aggox_lamarck(data, true, false);
                cout << "El coste es: " << aggox_lamarck.getSolution().coste << endl;
                cout << "El tiempo es: " << aggox_lamarck.getTime() << endl;
                cout << "El numero de generaciones es: " << aggox_lamarck.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico generacional lamarckiano con cruce ox: ";
                for(unsigned int i=0; i<aggox_lamarck.getSolution().solution.size(); i++)
                    cout << aggox_lamarck.getSolution().solution[i] << " ";
                break;
            }
        case 7:
            {
                GeneticalAlgorithm agepos(data, false, true);
                cout << "El coste es: " << agepos.getSolution().coste << endl;
                cout << "El tiempo es: " << agepos.getTime() << endl;
                cout << "El numero de generaciones es: " << agepos.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico estacionario con cruce posicional: ";
                for(unsigned int i=0; i<agepos.getSolution().solution.size(); i++)
                    cout << agepos.getSolution().solution[i] << " ";
                break;
            }
        case 8:
            {
                GeneticalBaldwinianAlgorithm agepos_baldwin(data, false, true);
                cout << "El coste es: " << agepos_baldwin.getSolution().coste << endl;
                cout << "El tiempo es: " << agepos_baldwin.getTime() << endl;
                cout << "El numero de generaciones es: " << agepos_baldwin.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico estacionario baldwiniano con cruce posicional: ";
                for(unsigned int i=0; i<agepos_baldwin.getSolution().solution.size(); i++)
                    cout << agepos_baldwin.getSolution().solution[i] << " ";
                break;
            }
        case 9:
            {
                GeneticalLamarckianAlgorithm agepos_lamarck(data, false, true);
                cout << "El coste es: " << agepos_lamarck.getSolution().coste << endl;
                cout << "El tiempo es: " << agepos_lamarck.getTime() << endl;
                cout << "El numero de generaciones es: " << agepos_lamarck.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico estacionario lamarckiano con cruce posicional: ";
                for(unsigned int i=0; i<agepos_lamarck.getSolution().solution.size(); i++)
                    cout << agepos_lamarck.getSolution().solution[i] << " ";
                break;
            }
        case 10:
            {
                GeneticalAlgorithm ageox(data, false, false);
                cout << "El coste es: " << ageox.getSolution().coste << endl;
                cout << "El tiempo es: " << ageox.getTime() << endl;
                cout << "El numero de generaciones es: " << ageox.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico estacionario con cruce ox: ";
                for(unsigned int i=0; i<ageox.getSolution().solution.size(); i++)
                    cout << ageox.getSolution().solution[i] << " ";
                break;
            }
        case 11:
            {
                GeneticalBaldwinianAlgorithm ageox_baldwin(data, false, false);
                cout << "El coste es: " << ageox_baldwin.getSolution().coste << endl;
                cout << "El tiempo es: " << ageox_baldwin.getTime() << endl;
                cout << "El numero de generaciones es: " << ageox_baldwin.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico estacionario baldwiniano con cruce ox: ";
                for(unsigned int i=0; i<ageox_baldwin.getSolution().solution.size(); i++)
                    cout << ageox_baldwin.getSolution().solution[i] << " ";
                break;
            }
        case 12:
            {
                GeneticalLamarckianAlgorithm ageox_lamarck(data, false, false);
                cout << "El coste es: " << ageox_lamarck.getSolution().coste << endl;
                cout << "El tiempo es: " << ageox_lamarck.getTime() << endl;
                cout << "El numero de generaciones es: " << ageox_lamarck.getNumGenerations() << endl;
                cout << "Solucion algoritmo genetico estacionario lamarckiano con cruce ox: ";
                for(unsigned int i=0; i<ageox_lamarck.getSolution().solution.size(); i++)
                    cout << ageox_lamarck.getSolution().solution[i] << " ";
                break;
            }
        default:
            cerr << "Numero de algoritmo " << argv[1] << " proporcionado incorrecto." << endl << endl;
            cerr << "Los algoritmos son:" << endl;
            cerr << "1  -> AGG-Posicion" << endl;
        	cerr << "2  -> AGG-Posicion Baldwiniano" << endl;
        	cerr << "3  -> AGG-Posicion Lamarckiano" << endl;
        	cerr << "4  -> AGG-OX" << endl;
        	cerr << "5  -> AGG-OX Baldwiniano" << endl;
        	cerr << "6  -> AGG-OX Lamarckiano" << endl;
        	cerr << "7  -> AGE-Posicion" << endl;
        	cerr << "8  -> AGE-Posicion Baldwiniano" << endl;
        	cerr << "9  -> AGE-Posicion Lamarckiano" << endl;
        	cerr << "10 -> AGE-OX" << endl;
        	cerr << "11 -> AGE-OX Baldwiniano" << endl;
        	cerr << "12 -> AGE-OX Lamarckiano" << endl;
            exit(-1);

    }

     cout << endl << endl;

    return 0;
}

