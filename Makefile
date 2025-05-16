CXXFLAGS:= -Wall -pedantic -MMD -MP

CXX  := g++
SRC  := simulation/Life.cpp simulation/life.cpp
OBJ  := $(SRC:.cpp=.o)
BIN  := bin/life.x
DEPS := $(OBJ:.o=.d)

${BIN}: ${OBJ} | bin
	${CXX} ${CXXFLAGS} $^ -o $@

%.o: %.cpp
	${CXX} ${CXXFLAGS} $< -c -o $@

bin:
	mkdir -p bin

data:
	mkdir -p data

save:
	mkdir -p save

INPUT.dat: .bckup/INPUT.dat
	cp $^ .

clean:
	rm -f ${OBJ} ${DEPS} ${BIN}

remove:
	rm -f data/*.bin

run: ${BIN} data INPUT.dat animation/animation.jl save
	@./${BIN} INPUT.dat; RET=$$?; \
	if [ $$RET -eq 0 ]; then \
	    echo "Simulation compleated without any problem!"; \
		julia animation/animation.jl; \
	elif [ $$RET -eq 1 ];then \
	    echo "ERROR: Not specified input file: './bin/life.x {input_file_name}'"; \
	elif [ $$RET -eq 2 ]; then \
	    echo "ERROR: Invalid input file name!"; \
	elif [ $$RET -eq 3 ]; then \
	    echo "ERROR: Initial configuration file not found!"; \
	else \
	    echo "ERROR: Not implemented error return $$RET"; \
	fi

-include ${DEPS}
