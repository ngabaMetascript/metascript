#ifndef ELT_H
#define ELT_H

#include <string>
#include "dataStructure.h"
using namespace std;

struct NumericValue{
	float value;
	string unit="px";
};    

struct DataAttribute {
	string field;
	string value;
};

class Elt{
	protected:
		bool visible;
	public:
		Elt();
};

// Informations Elements
class EltInfo :: Elt{

}

class TextInfo :: EltInfo {

}

class AudioInfo :: EltInfo {

}

class ImageInfo :: EltInfo{

}

class VideoInfo :: EltInfo{

}

class MediaInfo::EltInfo{
	vector<EltInfo*> medias;
	string order_play;
}

namespace c2D{
	class Point2D :: public Elt{
		protected:
			float x,y;
			string color;
	};
	class Shape :: public Elt{
	
	};
	class Line :: public Shape {
	
	};
	class Rectangle :: public Shape {
	
	};
	class Circle :: public Shape{
	
	};
	class Triangle :: public Shape{
	
	};
	class Polygon :: public Shape {
	
	};
	class ShapeGroup :: public Elt{
		protected:
			vector<Shape*> shapes;
	};
	class Component :: public Elt{
		protected:
			vector<ShapeGroup*> groups;	
	}
}


namespace c3D{
	class Point2D :: public Elt{
		protected:
			float x,y,z;
			string color;
	};
}

#endif
