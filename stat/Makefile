CXXFLAGS:= -Wall -pedantic -MMD -MP

CXX  := g++
SRC  := stat.cpp ../simulation/Life.cpp
OBJ  := $(SRC:.cpp=.o)
DEPS := $(OBJ:.o=.d)
BIN  := bin/stat.x

ARGS := INPUT.dat

RED := \033[1;31m
NC  := \033[0m

all: ${BIN}


clean:
	rm -f ${BIN} ${DEPS} ${OBJ}

run: ${BIN} | .log data
	@./$< ${ARGS} 2> .log/errors.log; RET=$$? ; \
	if [ $$RET -eq 0 ]; then \
		echo "Simulation finished without any error!"; \
	elif [ $$RET -eq 1 ]; then \
		echo "${RED}ERROR $$RET:${NC} Invalid arguments: ./$< {input file}"; \
	elif [ $$RET -eq 2 ]; then \
		echo "${RED}ERROR $$RET:${NC} Invalid input file"; \
	else \
		echo "${RED}ERROR $$RET:${NC} Not implemented error!"; \
	fi

${BIN}: ${OBJ} | bin
	${CXX} ${CXXFLAGS} $^ -o $@

%.o: %.cpp
	${CXX} ${CXXFLAGS} $< -c -o $@

bin:
	mkdir bin

.log:
	mkdir .log

data:
	mkdir data

-include ${DEPS}
