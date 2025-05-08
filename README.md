# Conway's Game of Life

This repository provides an implementation of __Conway's Game of Life__.
The game takes place on an _n × n_ grid where each cell is either __dead__ (_0_) or __alive__ (_1_).
The next generation of the system is determined based on the state of each cell's neighbors in the previous generation.
__Neighbors__ are the cells adjacent both laterally and diagonally.

## Rules

The rules of the game are as follows:

- A cell with __fewer than 2__ living neighbors __dies__ due to _underpopulation_.
- A cell with __more than 3__ living neighbors __dies__ due to _overpopulation_.
- A cell with __exactly 2__ living neighbors remains in its __current state__.
- A dead cell with __exactly 3__ living neighbors becomes __alive__ (_reproduction_).

## Repository

The files [Life.h](Life.h) and [Life.cpp](Life.cpp) define the __class__ used for the simulation.
The file [life.cpp](life.cpp) is used to __test__ the basic components of the class.

## License

This project is licensed under the _GNU General Public License v3.0_.

See the [LICENSE](LICENSE) file for more details.
