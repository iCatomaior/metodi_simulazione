#include <iostream>
#include <cmath>
#include <TMath.h>
#include <TRandom3.h>
#include <TH1D.h>
#include <TApplication.h>

using namespace std;

int main(){

    TApplication app("app",NULL,NULL);
    //generatore
    TRandom3 rnd;
    rnd.SetSeed(123456789);
    rnd.Rndm();

    //parameters
    int N_points = 1000;
    int n_bins = 30;
    float eta = 0;
    float x = 0;
    float y = 0;

    //histogram
    TH1D *h = new TH1D("h","Gaussian distribution",n_bins,-4,4);

    for (int i=0; i<N_points; i++){
        eta = rnd.Rndm();
        x = sqrt(2*exp(1)/M_PI)*TMath::Log(eta);
        y = x*rnd.Rndm();

        if (y<TMath::Gaus(x)){
            if (rnd.Rndm()>0.5){
                h->Fill(x);
            } else {
                h->Fill(-x);
            }
        }
    }    
    
    h->Draw();
    app.Run(true);
    return 0;
}