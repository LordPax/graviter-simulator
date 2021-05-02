CXX=g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
FLAGS=-W -Wall -ansi -pedantic -std=gnu++11
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=graviter

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CXX) $^ -o $@ $(LIBS)

%.o : %.cpp
	$(CXX) -c $< -o $@ $(FLAGS)

clean :
	rm -rf src/*.o

mrproper : clean
	rm -rf $(EXEC)

# $@ ref cible
# $< ref premiere dependance
# $^ ref listes dependances

# main.o : main.cpp
# 	$(CXX) -c main.cpp