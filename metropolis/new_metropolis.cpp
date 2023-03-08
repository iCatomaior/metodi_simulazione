#include <iostream>
#include <random>
#include "TMath.h"
#include <TApplication.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TGraph.h>

using namespace std;

//parametri fisici del problema
double J = 5;

//inizializzazione generatore tra 0 e 1
TRandom3 rnd(123456789);

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


int **Evolve (int **matrix, int L, int x, int y){
        int x_f=x;  int y_f=y;
        double E_f, p;
        double E_i = Energy(matrix,L,x,y);
        int n = rnd.Rndm();

        if (n<0.25){
            y_f=abs(y+1)%L;

        } else if (n<0.5){
            y_f=abs(y-1)%L;
        
        } else if (n<0.75){
            x_f=abs(x+1)%L;
        
        } else {
            x_f=abs(x-1)%L;
        
        }

        if (matrix[x_f][y_f]==0){
               
            E_f = Energy(matrix, L, x_f, y_f);
            p   = TMath::Exp(E_i-E_f);
            n   = rnd.Rndm();

            if(n<p){
                matrix[x][y]=0;
                matrix[x_f][y_f]=1;
            }
        }

        return matrix;
}


int main(){

    TApplication app("app",NULL,NULL);

    const int L = 16;           //larghezza griglia
    int N_particles = L*L/2;    //numero di particelle

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

    int x,y;        // variabili coordinate
    int N_acc = 0;  //variabile contatore

//riempimento griglia
    while(N_acc<N_particles) {
        x=rnd.Integer(L);
        y=rnd.Integer(L);

        if (matrix[x][y] == 0){
            
            matrix[x][y] = 1;
            N_acc++;
        }
    }

//checking matrix
    check(matrix,L);


int NMC = 1000000;    //numero di step di montecarlo

for (int i=0; i<NMC; i++){
    x = rnd.Integer(L);
    y = rnd.Integer(L);

    if(matrix[x][y]==0){
        continue;
    
    } else{
        matrix = Evolve(matrix,L,x,y);
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