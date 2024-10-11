#ifndef SCENE_DIMENSIONS_MODE
#define SCENE_DIMENSIONS_MODE

enum SCENE_DIMENSION { scene2D, scene3D };

#endif

#ifndef RENDERER_ENVIRONMENT
#define RENDERER_ENVIRONMENT

enum RENDERER_ENVIRONMENT { Web, Mobile, Desktop, Hologram }

#endif

/*
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;
*/

class Renderer {
	protected :
		const RENDERER_ENVIRONMENT renderer_environment;
	public:
		Renderer();
		~Renderer();
};

class Component{
	public:
		Component();
		~Component();
};

class Geometric: public Component{
	protected:
		const SCENE_DIMENSION scene_dimension;

};

class Polygon :  public Geometric{
};

class Rectangle : public Polygon{
	private:
		int width;
		int height;
	public:
		Rectangle(int=0,int=0);
		~Rectangle();
};

class GeometricGraphic : public Component{
	private:
		Geometric* core;
	public:
		void set_borders(char**);
		void set_bacground(char*,void*):
		void set_position(int,int,int=0);
		void set_padding(int*);
		void set_margin(int*)

};

class WebRenderer :  public Renderer{
	private:
		GeometricGraphic* graphic;
	public:
		WebRenderer();
};


WebRenderer::WebRenderer(){

}

int main(){

	return 0;
}