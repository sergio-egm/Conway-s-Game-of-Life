#include "Life.h"

using namespace std;

int main(int argc , char** argv){
    if(argc < 2)
        return 1;
    
    Life life(argv[1]);

    return life.run();
}
