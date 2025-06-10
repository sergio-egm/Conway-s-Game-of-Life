CXXFLAGS:= -Wall -pedantic -MMD -MP

CXX  := g++
SRC  := stat.cpp ../simulation/Life.cpp
OBJ  := $(SRC:.cpp=.o)
DEPS := $(OBJ:.o=.d) $(B36OBJ:.o=.d)
BIN  := bin/stat.x

B36BIN := bin/b36s23.x
B36SRC := stat.cpp B36S23/Life.cpp
B36OBJ := $(B36SRC:.cpp=.o)

ARGS := INPUT.dat

RED := \033[1;31m
NC  := \033[0m

all: ${BIN} ${B36BIN}


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

${B36BIN}: ${B36OBJ} | bin
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
