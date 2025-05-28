#include "Life.h"
#include <random>

Life::Life(int size , double prob , int seed , int generations , bool save):
    size(size),
    generations(generations),
    save(save),
    T0(0)
{
    matrix = new int* [size];

    srand(seed);

    int** rowPtr = matrix;
    int** rowEnd = matrix + size;

    while (rowPtr < rowEnd){
        *rowPtr = new int[size];

        int* colPtr = *rowPtr;
        int* colEnd = *rowPtr + size;

        while (colPtr < colEnd){
            *colPtr++ = (static_cast<double>(std::rand()) / RAND_MAX) < prob;
        }

        rowPtr++;
    }

    std::cout << "Grid size:  ( " << size << " x " << size << " )" << std::endl;
    std::cout << "# Gens:     " << generations << std::endl;
    std::cout << "Alive prob: " << prob << std::endl;
    std::cout << "Seed:       " << seed << std::endl;
    std::cout << (this->save ? "It will save the final config." : "It won't save the final config.") << std::endl; 
    std::cout << std::endl;
}

Life::Life(const std::string &file_name){
    bool get_config;

    std::ifstream fin(file_name);

    if(!fin.is_open())
        exit(2);

    fin >> get_config;
    fin >> generations;
    fin >> save;

    if(get_config){
        std::ifstream config("save/config.dat");

        if(!config.is_open()){
            std::cerr << "ERROR: 'save/config.dat' doesn't exist!" << std::endl;
            config.close();

            config.open(".bckup/initial.dat");
            if(!config.is_open())
                exit(3);
        }

        config >> size;
        config >> T0;

        generations += T0;

        matrix = new int*[size];

        int** rowPtr = matrix;
        int** rowEnd = matrix + size;

        int space;

        config >> space;

        while(rowPtr < rowEnd){
            *rowPtr = new int[size];

            int* colPtr = *rowPtr;
            int* colEnd = *rowPtr + size;

            while(colPtr < colEnd){
                config >> *colPtr;
                colPtr++;
            }

            rowPtr++;
        }

        config.close();

        std::cout << "Initial generation: " << T0 << std::endl;
    }
    else{
        double prob;
        int    seed;
        fin >> size;
        fin >> prob;
        fin >> seed;

        fin.close();
    
        matrix = new int* [size];

        srand(seed);

        int** rowPtr = matrix;
        int** rowEnd = matrix + size;

        while (rowPtr < rowEnd){
            *rowPtr = new int[size];

            int* colPtr = *rowPtr;
            int* colEnd = *rowPtr + size;

            while (colPtr < colEnd){
                *colPtr++ = (static_cast<double>(std::rand()) / RAND_MAX) < prob;
            }

            rowPtr++;
        }


    std::cout << "Alive prob: " << prob << std::endl;
    std::cout << "Seed:       " << seed << std::endl;
    }


    std::cout << "Grid size:  ( " << size << " x " << size << " )" << std::endl;
    std::cout << "# Gens:     " << generations << std::endl;
    std::cout << (save ? "It will save the final config." : "It won't save the final config.") << std::endl;
    std::cout << std::endl;
}

Life::Life(int size, int **matrix):size(size){
    this->matrix = new int* [this->size];

    int** rowIn  = matrix;
    int** rowOut = this->matrix;
    int** rowEnd = matrix + size;

    while(rowIn < rowEnd){
        *rowOut = new int[this->size];

        int* colIn  = *rowIn;
        int* colOut = *rowOut;
        int* colEnd = *rowIn+size;

        while(colIn < colEnd){
            *colOut++ = *colIn++;
        }

        rowIn++;
        rowOut++;
    }
}

Life::~Life(){
    int** ind = matrix;
    int** end = matrix+size;

    while(ind < end){
        delete[] *ind;

        ind++;
    }

    delete[] matrix;
}

void Life::print(std::ostream &os) const{
    int** rowPtr = matrix;
    int** rowEnd = matrix + size;

    os << size << ' ' << generations << ' ' << T0 << std::endl;

    while(rowPtr < rowEnd){
        int* colPtr = *rowPtr;
        int* colEnd = *rowPtr + size;

        while(colPtr < colEnd){
            os << *colPtr << ' ';

            colPtr++;
        }

        os << std::endl;

        rowPtr++;
    }
}

void Life::save_binary(const std::string &fileName) const{
    std::ofstream fout(fileName , std::ios::binary);

    int** rowPtr = matrix;
    int** rowEnd = matrix + size;

    while(rowPtr < rowEnd){
        int* colPtr = *rowPtr;
        int* colEnd = *rowPtr + size;

        while(colPtr < colEnd){
            unsigned char value = static_cast<unsigned char>(*colPtr);

            fout.write(reinterpret_cast<const char*>(&value),1);

            colPtr++;
        }

        rowPtr++;
    }

    fout.close();
}

int Life::get(unsigned int i, unsigned int j) const{
    return matrix[(i+size) % size][(j+size) % size];
}

void Life::set(unsigned int i, unsigned int j, int val){
    matrix[(i+size) % size][(j+size) % size] = val;
}

int Life::operator()(int i, int j) const{
    return matrix[(i+size) % size][(j+size) % size];
}

Life Life::copy(void) const{
    return Life(size , matrix);
}

void Life::update(void){
    Life tmp = copy();

    int val = 0;

    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            val = tmp(i-1,j+1) + tmp(i,j+1) + tmp(i+1 , j+1);
            val += tmp(i-1,j-1) + tmp(i,j-1) + tmp(i+1 , j-1);

            val += tmp(i-1,j) + tmp(i+1 , j);

            set(i , j , (val == 3) || (val == 2 && tmp(i,j) == 1));
        }
    }
}

int Life::run(const std::string &saveFile){
    std::string fileName = "data/frame";
    std::string dataType = ".bin";

    int count = 0;

    save_binary(fileName + std::to_string(T0) + dataType);

    std::cout << "Running Game of Life." << std::endl;

    std::cout << "[";

    for(int i = T0+1 ; i <= generations ; i++){
        update();
        save_binary(fileName + std::to_string(i) + dataType);

        if(i*100/generations > count){
            std::cout << "=";
            std::cout.flush();
            count += 5;
        }
    }

    std::cout << "]" << std::endl;

    if(this->save){
        std::ofstream fout(saveFile);

        print(fout);

        fout << "\t>> Size ; Number of generation ; T0" << std::endl;
        fout << "\t>> Initial lactice" << std::endl;

        fout.close();
    }

    return 0;
}
