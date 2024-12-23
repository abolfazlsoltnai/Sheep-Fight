CXX = g++ -g -std=c++20
FILES = build/methods.o build/live.o build/Player.o build/SheepConfigs.o build/InGame.o build/main.o 
EXE = a

all: $(EXE)


build/methods.o: src/methods.cpp 
	$(CXX) -c $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system

build/SheepConfigs.o: src/SheepConfigs.cpp src/SheepConfigs.hpp 
	$(CXX) -c $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system

build/live.o: src/live.cpp src/live.hpp 
	$(CXX) -c $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system


build/Player.o: src/Player.cpp src/Player.hpp 
	$(CXX) -c $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system


build/InGame.o: src/InGame.cpp src/GameMenu.hpp src/header.hpp src/arrowPointers.hpp
	$(CXX) -c $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system


build/main.o: src/main.cpp src/header.hpp src/buttons.hpp src/GameMenu.hpp src/arrowPointers.hpp	
	$(CXX) -c $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system



$(EXE): $(FILES)
	$(CXX) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system
