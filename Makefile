clash.o:src/clash.cpp
	g++ -c src/clash.cpp -o clash.o -I include

clash:clash.o
	g++ clash.o -o clash -Wl,-rpath,lib -L lib -lsfml-system -lsfml-window -lsfml-network -lsfml-graphics -lsfml-audio -lGLEW
