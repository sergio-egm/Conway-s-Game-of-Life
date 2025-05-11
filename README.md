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

![GoL GIF](https://github.com/sergio-egm/Conway-s-Game-of-Life/life.gif)

## Repository

The repository is organized as follows:

- [Makefile](Makefile): used to __build__ and __run__ the simulation code.
- [INPUT.dat](INPUT.dat): contains the __input values__ of the simulation.
- [simulation](simulation): contains the code used for the _simulation_, written in __C++__.
- [animation](animation): contains the code used to create the _animation_, written in __Julia__.
- [data](data): stores the _output_ of the simulation in binaries files (`.bin`).
- [.bckup](.bckup): contains copies of:
  - __INPUT.dat__.
  - __initial.dat__: sets initial configuration. (Not yet!)

## Run

It's possible to set personalized parametes modifing the file `INPUT.dat`, then, run the simulation and get the animation thought the comand:

```bash
make run
```

## License

This project is licensed under the _GNU General Public License v3.0_.

See the [LICENSE](LICENSE) file for more details.
