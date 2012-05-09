#include <clash/surface.hpp>
#include <fstream>
#include <iostream>
#include "SFML/OpenGL.hpp"
using namespace clash;

class Box : public Mesh {
	public: void draw () {
		glTranslatef(0.f, 0.f, -200.f);
		glBegin(GL_QUADS);
			glVertex3f(-50.f, -50.f, -50.f);
			glVertex3f(-50.f,  50.f, -50.f);
			glVertex3f( 50.f,  50.f, -50.f);
			glVertex3f( 50.f, -50.f, -50.f);
		glEnd();
	}
};

int main () {
	std::ifstream config("./game.conf");
	int width, height; bool fullscreen;
	config >> width >> height >> fullscreen;
	
	Surface game (width, height, fullscreen);
	
	Scene* scene = new Scene();
	scene->append(new Box());
	
	game.setScene(scene);
	
	do {} while (game.run());
	
	return 0;
}
