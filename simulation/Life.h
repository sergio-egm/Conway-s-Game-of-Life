#pragma once

#include<iostream>
#include<fstream>
#include<string>

class Life{
    public:
        Life(int size , double prob = .5 , int seed = 0);
        Life(const std::string& file_name);
        Life(int size , int** matrix);
        ~Life();

        void print(std::ostream &os = std::cout) const;
        void save_binary(const std::string& fileName) const;

        int  get(unsigned int i , unsigned int j) const;
        void set(unsigned int i , unsigned int j , int val);
        int  shape(void) const{return size;}

        int operator()(int i , int j) const;

        Life copy(void) const;
        void update(void);
    private:
        int size;
        int** matrix;
};
