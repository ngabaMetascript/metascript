#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>
#include "component.h"
#include "scene.h"

namespace webRenderer
{
	std::string rendererAttribute(DataAttribute dta_arg,std::string elt_arg);

	class ComponentRenderer{
		protected:
			Component* component;	
		public:
			ComponentRenderer(){}
			ComponentRenderer(Component* arg):component(arg){}
			virtual Component* getComponent(){return component;};
			virtual std::string renderer();
	};
	

	class InfoRenderer : public ComponentRenderer{
		public:
			InfoRenderer(){}
			virtual std::string renderer();
	};

	class ImageInfoRenderer : public InfoRenderer{
		protected:
			ImageInfo* component;
		public:
			std::string renderer();
	};
	
	class AudioInfoRenderer : public InfoRenderer{
		protected:
			AudioInfo* component;
		public:
			std::string renderer();
	};
	
	class TextInfoRenderer : public InfoRenderer{
		protected:
			TextInfo* component;	
		public:
			TextInfoRenderer(TextInfo* arg){component=arg;}
			std::string renderer();
	};
	
	class VideoInfoRenderer : public InfoRenderer{
		protected:
			VideoInfo* component;	
		public:
			std::string renderer();
	};

	class Geometric2DRenderer : public ComponentRenderer{
		protected:
			Geometric2D* component;
		public:
			Geometric2DRenderer(){}
			Geometric2DRenderer(Geometric2D* arg){
				component = arg;
			};
			virtual std::string renderer();
	};
	
	class RectangleRenderer : public Geometric2DRenderer{
		protected:
			Rectangle* component;
		public:
			RectangleRenderer(){};
			RectangleRenderer(Rectangle* arg){
				component = arg;
			}
			virtual std::string renderer();

	};
	
	class CircleRenderer : public Geometric2DRenderer{
		protected:
			Circle* component;
		public:
			virtual std::string renderer();

	};


	class SceneRenderer {
		protected:
			WebScene* scene;	
		public:
			SceneRenderer(){}//:component(arg){}
			SceneRenderer(WebScene* arg):scene(arg){};
			virtual std::string renderer(LinkedList<ComponentRenderer*> components);
	};
	
}
#endif 
