CXX = g++
PROJECT_NAME = homework_8

OBJ_FLAGS = -c -fPIC
EXEC_FLAGS = -o

OBJ_FILES = Unit.o Animal.o Man.o Bear.o Pig.o ManBearPig.o main.o

all: $(OBJ_FILES)
	$(CXX) $^ $(EXEC_FLAGS) $(PROJECT_NAME)

Unit.o: FirstTask/Unit/Unit.cpp
	$(CXX) $(OBJ_FLAGS) $<

Animal.o: FirstTask/Animal/Animal.cpp
	$(CXX) $(OBJ_FLAGS) $<

Man.o: FirstTask/Man/Man.cpp
	$(CXX) $(OBJ_FLAGS) $<

Bear.o: FirstTask/Bear/Bear.cpp
	$(CXX) $(OBJ_FLAGS) $<

Pig.o: FirstTask/Pig/Pig.cpp
	$(CXX) $(OBJ_FLAGS) $<

ManBearPig.o: FirstTask/ManBearPig/ManBearPig.cpp
	$(CXX) $(OBJ_FLAGS) $<

main.o: main.cpp
	$(CXX) $(OBJ_FLAGS) $<

clean:
	rm -rfv *.o ./$(PROJECT_NAME)
