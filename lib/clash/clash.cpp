#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <clash/surface.hpp>

#define nullptr   __null

using namespace sf;

namespace clash {
	Surface::Surface (int w, int h, bool fs) {
		VideoMode* mode = new VideoMode(w, h, 32);
		int style = fs ? Style::Fullscreen : Style::Default;
		this->window = new Window(*mode, "SFML OpenGL", style);
		
		// Set color and depth clear value
		glClearDepth(1.f);
		glClearColor(0.f, 0.f, 0.3f, 0.f);

		// Enable Z-buffer read and write
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);

		// Setup a perspective projection
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90.f, 0.9f, 1.f, 500.f);
		glViewport(0, 0, 400, 400);
	}
	
	void Surface::stop () {
		this->window->close();
	}
	
	void Surface::setScene (Scene* scene) {
		this->scene = scene;
	}
	
	bool Surface::run () {
		Event event;
		while(this->window->pollEvent(event)){
			if (event.type == Event::Closed)
				this->stop();
			
			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
				this->stop();
        }
        this->window->setActive();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		this->scene->render();		
				
		this->window->display();
		return this->window->isOpen();
	}
	
	void Scene::render () {
		for (int i=0 ; i<this->meshes.size() ; i++) {
			this->meshes[i]->draw();
		}
	}
	
	void Scene::append (Mesh* mesh) {
		this->meshes.push_back(mesh);
	}
}
