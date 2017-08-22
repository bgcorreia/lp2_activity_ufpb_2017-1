/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: LOGICA DE PROGRAMACAO II
ATIVIDADE
AUTOR: BRUNO CORREIA
DATA: 20/08/2017
VERSÃO: 0.001
   
MULTIPLICAÇÃO DE MATRIZES - PARALELO

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;

// For activate debug, set DEBUG != 0
#define DEBUG 0

// For activate manual mode, set AUTOMATED = 0
#define AUTOMATED 1

// Define dimension matrix
#define MAX_DIM 100

// Define limit values for elements
#define MAX_VALUE_ELEMENTS 50

class mensagem {
public:
	void apresentacao(){
		cout << endl;
		cout << "UFPB - CENTRO DE INFORMATICA" << endl;
		cout << "DISCIPLINA: LOGICA DE PROGRAMACAO II" << endl;
		cout << "ATIVIDADE" << endl;
		cout << "AUTOR: BRUNO CORREIA - 11510180" << endl;
		cout << "DATA: 20/08/2017" << endl;
		cout << "VERSÃO: 0.001" << endl;
   		cout << endl ;
		cout << "MULTIPLICAÇÃO DE MATRIZES - PARALELO" << endl;
		cout << endl;
	}
};

void criaThread(int i, int j, int cA, int cB, int *matrizA, int *matrizB, int *posMatrizC){

			/* Variables */
			int k, valorAtualA, valorAtualB;
			
			for ( k = 0; k < cA; k++ ){
				/*
				Find value per address using pointer:
				
				Summary: If you have a multidimensional array defined as int [][], 
				then x = y[a][b] is equivalent to x = *((int *)y + a * NUMBER_OF_COLUMNS + b);

				https://stackoverflow.com/questions/13554244/how-to-use-pointer-expressions-to-access-elements-of-a-two-dimensional-array-in?answertab=active#tab-top
				*/

				valorAtualA = *((int *)matrizA + i * cA + k);
				valorAtualB = *((int *)matrizB + k * cB + j);

				if (DEBUG){
					cout<<"Valor atual Matriz A - "<<i+1<<"x"<<k+1<<": "<<valorAtualA<<endl;
					cout<<"Valor atual Matriz B - "<<j+1<<"x"<<k+1<<": "<<valorAtualB<<endl;
				}

				/* Do sum values */
				*posMatrizC += valorAtualA * valorAtualB;

				
				if (DEBUG){
					cout<<posMatrizC<<" += "<<valorAtualA<<" * "<<valorAtualB<<endl;
					cout<<valorAtualA * valorAtualB<<endl;
					cout<<"Valor: "<<*posMatrizC<<endl<<endl;
				}
				
			}
}

int main(){

	/* Create object type mensagem */
	mensagem exibir;

	/* Show header */
	exibir.apresentacao();

	/* Variables */
	int lA, cA, lB, cB;
	int numElementsC;

	if (AUTOMATED){
		/* Do the function rand really rand */
		srand(time(NULL));

		lA = rand() % MAX_DIM + 1 ;
		cA = lB = rand() % MAX_DIM + 1 ;
		cB = rand() % MAX_DIM + 1 ;

	} else {

		cout<<endl<<"Matriz A "<<endl;
		cout<<"Nº Linhas: ";
		cin>>lA;
		cout<<"Nº Colunas: ";
		cin>>cA;

		cout<<endl<<"Matriz B "<<endl;
		cout<<"Nº Linhas: ";
		cin>>lB;
		cout<<"Nº Colunas: ";
		cin>>cB;

		if ( cA != lB ){
			cout<<endl<<"A matrizes não podem ser mutiplicadas, o nº de colunas da matriz A tem de ser igual ao nº de linhas da matriz B."<<endl<<endl;
			return 1;
		}
	}

	numElementsC = lA*cB;

	thread objThread[numElementsC];

	int matrizA[lA][cA], matrizB[lB][cB], matrizC[lA][cB];
	int i, j, indice=0;
	
	if (AUTOMATED){

		/* Fill matrix A */
		for ( i = 0; i < lA; i++){
			for ( j = 0; j < cA; j++){
				matrizA[i][j]= rand() % MAX_VALUE_ELEMENTS + 1;
			}
		}

		/* Show matrix A */
		cout<<endl<<"Matriz A - "<<lA<<"x"<<cA<<endl;
		for ( i = 0; i < lA; i++){
			/* Comment line because easy validation */
			//cout<<"|";
			for ( j = 0; j < cA; j++){
				cout<<string(2, ' ')<<matrizA[i][j];
			}
			/* Comment line because easy validation */
			//cout<<"  |"<<endl;
			cout<<endl;
		}

		/* Fill matrix B */
		for ( i = 0; i < lB; i++){
			for ( j = 0; j < cB; j++){
				matrizB[i][j]= rand() % MAX_VALUE_ELEMENTS + 1;
			}
		}

		/* Show matrix B */
        cout<<endl<<"Matriz B - "<<lB<<"x"<<cB<<endl;
        for ( i = 0; i < lB; i++){
        	/* Comment line because easy validation */
            //cout<<"|";
            for ( j = 0; j < cB; j++){
                    cout<<string(2, ' ')<<matrizB[i][j];
            }
			/* Comment line because easy validation */
			//cout<<"  |"<<endl;
			cout<<endl;
        }

	} else {
		/* Read values matrix A */
		cout<<endl<<"Matriz A"<<endl;

		for ( i = 0; i < lA; i++){
			for ( j = 0; j < cA; j++){
				cout<<"Elemento "<<i+1<<"x"<<j+1<<": ";
				cin>>matrizA[i][j];
			}
		}

		/* Show matrix A */
		cout<<endl<<"Matriz A - "<<lA<<"x"<<cA<<endl;
		for ( i = 0; i < lA; i++){
			cout<<"|";
			for ( j = 0; j < cA; j++){
				cout<<string(2, ' ')<<matrizA[i][j];
			}
			cout<<"  |"<<endl;
		}

		/* Read values matrix B */
		cout<<endl<<"Matriz B - "<<lB<<"x"<<cB<<endl;

        for ( i = 0; i < lB; i++){
                for ( j = 0; j < cB; j++){
                        cout<<"Elemento "<<i+1<<"x"<<j+1<<": ";
                        cin>>matrizB[i][j];
                }
        }
	
        /* Show matrix B */
        cout<<endl<<"Matriz B"<<endl;
        for ( i = 0; i < lB; i++){
                cout<<"|";
                for ( j = 0; j < cB; j++){
                        cout<<string(2, ' ')<<matrizB[i][j];
                }
                cout<<"  |"<<endl;
        }
	}

	/* Clean matrix C before calc */
    for ( i = 0; i < lA; i++){
            for ( j = 0; j < cB; j++){
                    matrizC[i][j]=0;
            }
    }

	/* Calc matrix result */
	for ( i = 0; i < lA; i++){
		for ( j = 0; j < cB; j++){
				/*  */
				objThread[indice++] = thread(criaThread, i, j, cA, cB, &matrizA[0][0], &matrizB[0][0], &matrizC[i][j]);
			}
	}

	/* Wait finish exec thread each line */
	for ( i = 0; i < numElementsC; i++){
		objThread[i].join();
	}
	
	/* Show matriz A x B */
    cout<<endl<<"Matriz A * B - "<<lA<<"x"<<cB<<endl;
    for ( i = 0; i < lA; i++){
            cout<<"|";
            for ( j = 0; j < cB; j++){
                    cout<<string(2, ' ')<<matrizC[i][j];
            }
            cout<<"  |"<<endl;
    }

    /* 
	For validation results, get values matrix A and B
	and add in: 

    https://matrixcalc.org/pt/
    */

	cout<<endl;
        

    /* Show elements matrix A x B  */
    if (DEBUG){
	    for ( i = 0; i < lA; i++){
	            for ( j = 0; j < cB; j++){
	                    cout<<"Elemento "<<i+1<<"x"<<j+1<<": "<<matrizC[i][j]<<endl;
	            }
	    }
	}

	cout<<endl;

	return 0;

}