#pragma once

#include<iostream>
#include<fstream>
#include<string>

class Life{
    public:
        Life(int size , double prob = .5 , int seed = 0 , int generations = 1);
        Life(const std::string& file_name);         // Input parameter form a file
        Life(int size , int** matrix);              // Initial configuration fixed
        ~Life();

        void print(std::ostream &os = std::cout) const;
        void save_binary(const std::string& fileName) const;    // Save the configutation in a binary file

        int  get(unsigned int i , unsigned int j) const;
        void set(unsigned int i , unsigned int j , int val);
        int  shape(void) const{return size;}

        int operator()(int i , int j) const;    // Return the state of the (i , j) matrix element

        Life copy(void) const;
        void update(void);      // Generate next generation

        int run(void);          // Run the simulation for the fixed time
    private:
        int size;           // Lentght of the side of the square lactice
        int generations;    // Numbar of generations of the simulation
        int** matrix;       // Lactice
};
