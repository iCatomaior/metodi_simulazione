#include <iostream>
#include <TApplication.h>
#include <TRandom3.h>
#include <TH1D.h>
#include <TMath.h>

using namespace std;

int main(){
    TApplication app("app",NULL,NULL);
    TRandom3 rnd;
    rnd.SetSeed(123456789);

    //Setting parameters
    int N_points = 100000;
    int n_bins   = 70;
    int nacc = 0;

    //Setting variables
    float x = 0;
    float y = 0;
    
    TH1D *h = new TH1D("h","Reiezione",n_bins,0,2*M_PI);

    for (int i=0; i<N_points; i++){
        x = 2*M_PI*rnd.Rndm();
        y =rnd.Rndm();

        if (y<abs(TMath::Cos(x))){
            nacc += 1;
            h->Fill(x);
        }
    }

    //calcolo integrale
    float area =  2*M_PI*float(nacc)/float(N_points);

    cout << area << endl;

    h->Draw();
    app.Run(true);

    return 0;
}