# Simulation in C++

In this directory are avviable the scripts in C++ used to build the numerical simulation.

Inside this directory are avviable the following scripts:

- __Life.h__ and __Life.cpp__ used to define the `class Life()`.
- __life.cpp__ main code for the simulation containing the function `int main()`.

## Class Life

Class that define the lactice and the updating rules.

```c++
class Life{
    public:
        Life(int size , double prob = .5 , int seed = 0 , int generations = 1 , bool save = false);
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
```

## Simulation

It gets the parameter for the initialization of the system form __INPUT.dat__ and run the simulation.
