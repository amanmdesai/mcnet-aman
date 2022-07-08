#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main(int argc, char* argv[]){

    Pythia pythia;
    //pythia.readString("Top:gg2ttbar=on") ; // process
    //pythia.readString("Top:qqbar2ttbar=on") ; // process
    //pythia.readString("Beams:eCM = 13000"); //energy 6.5+6.5*1000 GeV
    //pythia.readString("Next:numberShowEvent = 5"); //energy 6.5+6.5*1000 GeV
    pythia.readFile(argv[1]);
    pythia.init(); // pp is default 
    for(int event=0; event < 5; event++){
    
        pythia.next(); // generate an event.

        for (int i = 0; i < pythia.event.size(); ++i) {
            cout << "i = " << i << ", id = "<< pythia.event[i].id() << endl;
        }
    }
    pythia.stat(); // statistics
    return 0;

}