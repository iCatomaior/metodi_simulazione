#include <iostream>
#include <cmath>
#include <random>
#include <TApplication.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TGraph.h>

using namespace std;

//parametri fisici del problema
double T = 300;
const double kb = 1.38*10e-23;
double J = 1;

//checking the number of particles
void check(int** matrix, int size){
    int N_acc=0;
    int N_particles = size*size*0.5;

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if(matrix[i][j]==1){
                N_acc++;
            }
        }
    }

if (N_acc!=N_particles){
        cerr << "Il numero di particelle è errato!!" <<endl;
        exit(1);
    }
}

double Energy(int **matrix, int L, int x, int y){
    double energy;

    energy = J*(matrix[(x+1)%L][y]+matrix[abs(x-1)%L][y]+matrix[x][(y+1)%L]+matrix[x][abs(y-1)%L]);

    return energy;
}



int main(){

    TApplication app("app",NULL,NULL);

//inizializzazione generatore tra 0 e 1
    TRandom3 rnd;
    rnd.SetSeed(123456789);

//larghezza griglia
    const int L = 2;

//parametri
    int N_particles = L*L/2;

//inizializzazione griglia
    int ** matrix = new int*[L];

    for (int i=0; i<L; i++){
        matrix[i]= new int[L];
    }

//inizializzazione valori
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            matrix[i][j] = 0;
        }
    }

// variabili coordinate
    int x,y;

//variabile contatore
    int N_acc = 0;

//riempimento griglia
    while(N_acc<N_particles) {
        x=rnd.Integer(L);
        y=rnd.Integer(L);

        if (matrix[x][y]==0){
            matrix[x][y] = 1;
            N_acc++;
        }
    }

//checking matrix
    check(matrix,L);

//numero di step di montecarlo

int NMC = 100;
double E_i, E_f, delta, n;
int x_f, y_f;

for (int i=0; i<NMC; i++){
    x = rnd.Integer(L);
    y = rnd.Integer(L);
    x_f = x;
    y_f = y;

    if(matrix[x][y]==0){
        continue;
    } else{
        E_i = Energy(matrix,L,x,y);
        n = rnd.Rndm();

        if (n<0.25){
            y_f=abs(y+1)%L;
        } else if (n<0.5){
            y_f=abs(y-1)%L;
        } else if (n<0.75){
            x_f=abs(x+1)%L;
        } else {
            x_f=abs(x-1)%L;
        }

        if (matrix[x_f][y_f]==1){
            continue;
        } else{
            E_f = Energy(matrix, L, x_f, y_f);
            delta = E_f - E_i;
        }


    }

}

//plotting
    
    TGraph* g1 = new TGraph();
    TGraph* g2 = new TGraph();

    int marker_size = 1;


    g1->SetMarkerStyle(20);
    g1->SetMarkerSize(marker_size);

    g2->SetTitle("Gas reticolare");
    g2->SetMarkerStyle(24);
    g2->SetMarkerSize(marker_size);

    int c = 0;
    int d = 0;

    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            if (matrix[i][j]==1){
                g1->SetPoint(c, i+1, j+1);
                c++;
            }  else{
                g2->SetPoint(d, i+1, j+1);
                d++; 
             
            }
        }
    }


    g2->Draw("AP");
    g1->Draw("P");


    app.Run(true);

//deleting matrix
    for (int i=0; i<L; i++){
        delete [] matrix[i];
    }

    delete [] matrix;

    return 0;
}