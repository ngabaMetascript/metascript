#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>
#include "component.h"
#include "scene.h"

namespace webRenderer
{

	class ComponentRenderer{
		protected:
			Component* component;	
		public:
			virtual std::string renderer();
	};
	
	class ImageInfoRenderer : public ComponentRenderer{
		protected:
			ImageInfo* component;
		public:
			virtual std::string renderer();
		
	};
	
	
	class AudioInfoRenderer : public ComponentRenderer{
		protected:
			AudioInfo* component;
		public:
			virtual std::string renderer();
				
	};
	
	
	class TextInfoRenderer : public ComponentRenderer{
		protected:
			TextInfo* component;	
		public:
			virtual std::string renderer();

	};
	
	
	class VideoInfoRenderer : public ComponentRenderer{
		protected:
			VideoInfo* component;	
		public:
			virtual std::string renderer();

	};
	
	class Geometric2DRenderer : public ComponentRenderer{
		protected:
			Geometric2D* component;
		public:
			Geometric2DRenderer(){};
			Geometric2DRenderer(Geometric2D* arg){component = arg;};
			virtual std::string renderer();

	};
	
	class RectangleRenderer : public Geometric2DRenderer{
		protected:
			Rectangle* component;
		public:
			RectangleRenderer();
			RectangleRenderer(Rectangle* arg){component=arg;}
			virtual std::string renderer();

	};
	
	class CircleRenderer : public Geometric2DRenderer{
		protected:
			Circle* component;
		public:
			virtual std::string renderer();

	};
	
	class SceneRenderer{
		protected:
			WebScene* scene;
		public:
			SceneRenderer(WebScene*);
			std::string renderer(vector<ComponentRenderer*>);
	
	};
	
}
#endif 
