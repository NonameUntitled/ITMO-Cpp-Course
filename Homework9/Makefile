CXX = g++
PROJECT_NAME = homework_9

OBJ_FLAGS = -c -fPIC
EXEC_FLAGS = -o

all: Array.o main.o
	$(CXX) $^ $(EXEC_FLAGS) $(PROJECT_NAME)

Array.o: SecondTask/Array.cpp
	$(CXX) $(OBJ_FLAGS) $<

main.o: main.cpp
	$(CXX) $(OBJ_FLAGS) $<

clean:
	rm -rfv *.o ./$(PROJECT_NAME)


