#include "TH1D.h"
#include "TRandom3.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (){

    TApplication app("app",NULL,NULL);

    TH1D *h = new TH1D("h","Esempio",20,0,1);
    TRandom3 rnd(123456789);

    int N = 100;

    for (int i=0; i<N; i++){
        h->Fill(rnd.Rndm());
        h->Draw();
        gPad->Update();

    }

    app.Run(true);

}