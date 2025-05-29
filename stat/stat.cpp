#include<iostream>
#include<fstream>
#include"../simulation/Life.h"
#include<vector>

using namespace std;

int main(int argc , char** argv){
    //Check input arguments
    if(argc < 1){
        cerr << "Invalid arguments!" << endl;
        return 1;
    }

    //Get initialization data from file
    ifstream fin(argv[1]);

    if(!fin.is_open()){
        cerr << "Invalid input file \"" << argv[1] << "\"" << endl;
        return 2;
    }
    int gens , size , seed , nsamples;
    double prob;
    
    fin >> gens;
    fin >> size;
    fin >> prob;
    fin >> seed;
    fin >> nsamples;

    fin.close();

    vector<Life*> sample;
    
    ofstream fout("data/totalVStime.dat");

    for(int i = 0 ; i < nsamples ; i++){
        sample.push_back(new Life(size , prob , seed+i , gens , false , false));

        fout << sample[i]->get_total() << ' ';
    }
    fout << endl;

    for(int i = 0 ; i <= gens ; i++){
        for(auto &s : sample){
            s->update();
            
            fout << s->get_total() << ' ';
        }
        fout << endl;
    }

    fout.close();

    return 0;
}