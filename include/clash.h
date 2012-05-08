#include<SFML/Graphics.hpp>

namespace clash {
	class Mesh {
		public:
			virtual void draw()=0;
	};
	
	class Scene {
		private:
			std::vector<Mesh*> meshes;
		public:
			void render();
			void append(Mesh*);
	};
	
	class Surface {
		private:
			sf::Window* window;
			Scene* scene;
		public:
			Surface(int, int, bool);
			void stop();
			void setScene(Scene*);
//			Scene* getScene();
//			void destroyScene();
			bool run();
	};
}
