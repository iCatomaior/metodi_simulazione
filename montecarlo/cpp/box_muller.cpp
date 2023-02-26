#include <iostream>
#include <TApplication.h>
#include <TMath.h>
#include <TRandom3.h>
#include <TH1D.h>
#include <cmath>

using namespace std;

int main(){

    TApplication app("app",NULL,NULL);

    //generator
    TRandom3 rnd;
    rnd.SetSeed(123456789);

    //parameters
    int N_points = 1000000;
    int n_bins  = 40;
    float eta_1;
    float eta_2;
    float x;

    //histogram
    TH1D *h = new TH1D("h","Gaussian distribution",n_bins,-4,4);

    for (int i=0; i<N_points; i++){
        eta_1 = rnd.Rndm();
        eta_2 = rnd.Rndm();

        x=sqrt(-2*TMath::Log(eta_1))*TMath::Cos(2*M_PI*eta_2);
        h->Fill(x);
    }

    h->Draw();
    app.Run(true);
    return 0;
}