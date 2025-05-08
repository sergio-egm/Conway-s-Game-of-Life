SETS:= -Wall -pedantic
CODE:= life.x #sudoku-test 


compila: ${CODE}


#sudoku-test: $@.o sudoku-test/Solutore.o
#	g++ ${SETS} $^ -o $@

%.x: Life.o %.cpp
	g++ ${SETS} $^ -o $@

%.o: %.cpp %.h
	g++ ${SETS} $< -c

