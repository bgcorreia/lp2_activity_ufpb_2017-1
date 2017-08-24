/*
UFPB - CENTRO DE INFORMATICA
DISCIPLINA: LOGICA DE PROGRAMACAO II
ATIVIDADE
AUTOR: BRUNO CORREIA
DATA: 20/08/2017
VERSÃO: 0.001
   
MULTIPLICAÇÃO DE MATRIZES - SEQUENCIAL

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// For activate debug, set DEBUG != 0
#define DEBUG 0

// For activate manual mode, set AUTOMATED = 0
#define AUTOMATED 1

// Define dimension matrix
#define MAX_DIM 100

// Defini matrix static
#define STATIC 1

// Define limit values for elements
#define MAX_VALUE_ELEMENTS 50

class mensagem {
public:
	void apresentacao(){
		cout << endl;
		cout << "UFPB - CENTRO DE INFORMATICA" << endl;
		cout << "DISCIPLINA: LOGICA DE PROGRAMACAO II" << endl;
		cout << "ATIVIDADE" << endl;
		cout << "AUTOR(ES): BRUNO CORREIA / JOSE OLIVIO - 11510180/11512267" << endl;
		cout << "DATA: 20/08/2017" << endl;
		cout << "VERSÃO: 0.001" << endl;
   		cout << endl ;
		cout << "MULTIPLICAÇÃO DE MATRIZES - SEQUENCIAL" << endl;
		cout << endl;
	}
};

int main(){

	mensagem exibir;

	exibir.apresentacao();

	int lA, cA, lB, cB;

	if (AUTOMATED) {
		/* Do the function rand really rand */
		srand(time(NULL));

		if (STATIC){
			lA = cA = lB = cB = MAX_DIM ;
		} else {
			lA = rand() % MAX_DIM + 1 ;
			cA = lB = rand() % MAX_DIM + 1 ;
			cB = rand() % MAX_DIM + 1 ;
		}

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

	int matrizA[lA][cA], matrizB[lB][cB], matrizC[lA][cB];
	int i, j, k;
	
	if (AUTOMATED){

		/* Matrix A */
		for ( i = 0; i < lA; i++){
			for ( j = 0; j < cA; j++){
				matrizA[i][j]= rand() % MAX_VALUE_ELEMENTS + 1;
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

		/* Matrix B */
		for ( i = 0; i < lB; i++){
			for ( j = 0; j < cB; j++){
				matrizB[i][j]= rand() % MAX_VALUE_ELEMENTS + 1;
			}
		}

		/* Show matrix B */
        cout<<endl<<"Matriz B - "<<lB<<"x"<<cB<<endl;
        for ( i = 0; i < lB; i++){
                cout<<"|";
                for ( j = 0; j < cB; j++){
                        cout<<string(2, ' ')<<matrizB[i][j];
                }
                cout<<"  |"<<endl;
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
		cout<<endl<<"Matriz A"<<endl;
		for ( i = 0; i < lA; i++){
			cout<<"|";
			for ( j = 0; j < cA; j++){
				cout<<string(2, ' ')<<matrizA[i][j];
			}
			cout<<"  |"<<endl;
		}

		/* Read values matrix B */
		cout<<endl<<"Matriz B"<<endl;

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

	// Clean matrix C before calc
    for ( i = 0; i < lA; i++){
            for ( j = 0; j < cB; j++){
                    matrizC[i][j]=0;
            }
    }

	// Calc matrix result
	for ( i = 0; i < lA; i++){
		for ( j = 0; j < cB; j++){
			for ( k = 0; k < cA; k++ ){

				if (DEBUG){
                    cout<<endl<<"!--- INI DEBUG ---!"<<endl;
					cout<<"Valor da posição matrizC["<<i+1<<"]["<<k+1<<"] antes do cálculo: ";
					cout<<matrizC[i][j]<<endl;
                    cout<<endl<<"!--- FIM DEBUG ---!"<<endl;
				}

				// Sum values each position matrix C
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
				
				if (DEBUG){
                    cout<<endl<<"!--- INI DEBUG ---!"<<endl;
					cout<<"matrizC["<<i+1<<"]["<<k+1<<"]"<<" += matrizA["<<i+1<<"]["<<k+1<<"] * matrizB["<<k+1<<"]["<<j+1<<"]"<<endl;
					cout<<matrizA[i][k]<<" * "<<matrizB[k][j]<<endl;
					cout<<matrizC[i][j]<<endl;
                    cout<<endl<<"!--- FIM DEBUG ---!"<<endl;
				}
			}
		}
	}
	
	/* Show matriz A * B */
    cout<<endl<<"Matriz A * B - "<<lA<<"x"<<cB<<endl;
    for ( i = 0; i < lA; i++){
            cout<<"|";
            for ( j = 0; j < cB; j++){
                    cout<<string(2, ' ')<<matrizC[i][j];
            }
            cout<<"  |"<<endl;
    }

	cout<<endl;
        

    /* Show elements matrix A x B 
    for ( i = 0; i < lA; i++){
            for ( j = 0; j < cB; j++){
                    cout<<"Elemento "<<i+1<<"x"<<j+1<<": "<<matrizC[i][j]<<endl;
            }
    }
    */

	cout<<endl;

	return 0;

}