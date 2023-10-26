game: main.cpp node.cpp cube.cpp axis.cpp -lsfml-graphics -lsfml-window -lsfml-system
	g++ main.cpp node.cpp cube.cpp axis.cpp -lsfml-graphics -lsfml-window -lsfml-system

make test: game
	./a.out
