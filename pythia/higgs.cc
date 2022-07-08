#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main(){

    Pythia pythia;
    pythia.readString("HiggsSM:gg2H=on") ; // process
    pythia.readString("Beams:eCM = 13000"); //energy 6.5+6.5*1000 GeV
    pythia.readString("Next:numberShowEvent = 5"); //energy 6.5+6.5*1000 GeV
    pythia.readString("PartonLevel:all=OFF"); // only hard process generation
    pythia.readString("25:onMode=OFF"); // no other processes
    pythia.readString("25:onifMatch=23 23"); // no other processes
    pythia.init(); // pp is default '
    int iH;
    for(int event=0; event < 5; event++){
    
        pythia.next(); // generate an event.

        for (int i = 0; i < pythia.event.size(); ++i) {
            cout << "i = " << i << ", id = "<< pythia.event[i].id() << endl;
        
            if (pythia.event[i].id() == 25) iH = i;

        }

        int iDau1 = pythia.event[iH].daughter1();
        int iDau2 = pythia.event[iH].daughter2();

    }
    pythia.stat(); // statistics
    return 0;

}