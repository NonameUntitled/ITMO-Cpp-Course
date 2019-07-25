CXX = g++
PROJECT_NAME = homework_11

OBJ_FLAGS = -c -fPIC
EXEC_FLAGS = -o

FOLDER_NAME = BadFromStringException

all: $(FOLDER_NAME).o main.o
	$(CXX) $^ $(EXEC_FLAGS) $(PROJECT_NAME)

$(FOLDER_NAME).o: $(FOLDER_NAME)/$(FOLDER_NAME).cpp
	$(CXX) $(OBJ_FLAGS) $<

main.o: main.cpp
	$(CXX) $(OBJ_FLAGS) $<

clean:
	rm -rfv *.o ./$(PROJECT_NAME)
