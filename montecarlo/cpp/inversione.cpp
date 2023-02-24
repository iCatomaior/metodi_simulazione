#include <iostream>
#include <TRandom3.h>
#include <TGraphErrors.h>
#include <TH1D.h>
#include <TApplication.h>
#include <TMath.h>
#include <TGraphErrors.h>

using namespace std;

int main(){
    
    TApplication app ("app",NULL,NULL);

//setting parameters
    int N_points = 10000;
    int n_bins   = 20;
    float eta = 0;
    float x   = 0;
    float alpha = 3;

//setting number generator    
    TRandom3 rnd;
    rnd.SetSeed(123456789);

//setting histograms
    TH1D *h = new TH1D("h","",n_bins,0,2);
    
    for (int i=0; i<N_points; i++){
        eta = rnd.Rndm();
        x = -(1/alpha)*TMath::Log(eta);
        h->Fill(x);
    }

    h->Draw();

    app.Run(true);

    return 0;
}