#include <iostream>
#include <random>
#include <TApplication.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TGraph.h>

using namespace std;

double Energy(int L, int matrix){
    int N_acc =0;
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            if (matrix[i][j]==1){
                N_acc++;
            }
        }
    }
}


int main(){

    TApplication app("app",NULL,NULL);

//inizializzazione generatore tra 0 e 1
    TRandom3 rnd;
    rnd.SetSeed(123456789);
//larghezza griglia
    const int L = 8;

//parametri
    int N_particles = L*L/2;

//inizializzazione generatori di interi
    default_random_engine gen;
    gen.seed(1234567890);
    uniform_int_distribution range(0,L-1);    

//inizializzazione griglia
    int matrix[L][L]={};

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

//parametri fisici del problema

/* double T = 300;
const double kb = 1.38*10e-23;
double J = 10e-3;

//numero di step di montecarlo

int NMC = 1000;

for (int i=0; i<NMC; i++){
    x = range(gen);
    y = range(gen);

    if(matrix[x][y]==0){
        continue;
    } else{

    }



}
 */

cout << Energy(matrix,L) << endl;













//plotting

    TGraph* g1 = new TGraph();
    TGraph* g2 = new TGraph();

    int marker_size = 2;


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
 
    return 0;
}

