#include "Life.h"

using namespace std;

int main(int argc , char** argv){
    int    size = 5;
    double prob = .5;

    if(argc > 1)
        size = atoi(argv[1]);
    if(argc > 2)
        prob = atof(argv[2]);

    Life life(size , prob);

    life.print();
    cout << endl;

    life.update();
    life.print();
    
    life.save_binary("data/frame.bin");

    return 0;
}
