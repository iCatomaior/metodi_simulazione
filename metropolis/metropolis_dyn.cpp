#include <iostream>
#include <random>
#include <TApplication.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TGraph.h>

using namespace std;

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

int main(){

    TApplication app("app",NULL,NULL);

//inizializzazione generatore tra 0 e 1
    TRandom3 rnd;
    rnd.SetSeed(123456789);

//larghezza griglia
    const int L = 32;

//parametri
    int N_particles = L*L/2;

//inizializzazione generatori di interi
    default_random_engine gen;
    gen.seed(1234567890);
    uniform_int_distribution range(0,L-1);    

//inizializzazione griglia
    //int matrix[L][L]={};
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
        x=range(gen);
        y=range(gen);

        if (matrix[x][y]==0){
            matrix[x][y] = 1;
            N_acc++;
        }
    }

//checking matrix
    check(matrix,L);

//plotting

    TGraph* g1 = new TGraph();
    TGraph* g2 = new TGraph();

    int marker_size = 1;

    g2->SetTitle("Gas reticolare");

    int c = 0;

    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            if (matrix[i][j]==1){
                g1->SetMarkerStyle(20);
                g1->SetMarkerSize(marker_size);
                g1->SetPoint(c, i+1, j+1);
                c++;
            }  else{
                g2->SetMarkerStyle(24);
                g2->SetMarkerSize(marker_size);
                g2->SetPoint(c, i+1, j+1);
                c++; 
             
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