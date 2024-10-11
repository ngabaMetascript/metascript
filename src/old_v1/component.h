#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>
#include "scene.h"
using namespace std;

struct Value{
	int value;
	string unit="px";
};    

struct DataAttribute {
	string field;
	string value;
};

class Component{
	protected:
		bool visible;
		string name="";
		string display;
		string position;
		vector<DataAttribute> dataAttributes;
		Component* parent= nullptr;
		Scene* scene;
	public:
		Component();
		Component(string);
		Component* getParent(void);
		string getName();
		vector<DataAttribute> getDataAttributes(void);
		void setParent(Component*);
		void setScene(Scene*);

};

// ================================================================
class InfoComponent : public Component{
	protected:
		char value;
};

class TextInfo : public InfoComponent{

};

class ImageInfo : public InfoComponent{

};

class VideoInfo : public InfoComponent{

};

class AudioInfo : public InfoComponent{

};


// ================================================================
class Geometric : public Component{
	protected:
		vector<DataAttribute> dataAtributes;
	public:
		Geometric();
		Geometric(string);
		~Geometric();
};

class Geometric2D : public Geometric{
	protected:
		InfoComponent* background=nullptr;
		InfoComponent** content=nullptr;
		string padding="";
		string margin="";	
		string border="";
		string boxShadow="";	
	public:
		Geometric2D();
		Geometric2D(string);
		~Geometric2D();
		string getPadding(){return padding;}
		string getMargin(){return margin;}
		string getBorder(){return border;}
		string getBoxShadow(){return boxShadow;}
		
};

class Rectangle : public Geometric2D {
	private:
		int width=0,height=0;
	public:
		Rectangle();
		Rectangle(int,int);
		~Rectangle();
		int getWidth(){return width;}
		int getHeight(){return height;}
		
};

class RectangleInput : public Rectangle {

};

class RectangleCheckBox : public Rectangle {

};

class RectangleSelect : public Rectangle {

};

class Circle : public Geometric2D {
	private:
		int radius=0;
	public:
		Circle(int);
		~Circle();
		int getRadius(){return radius;}
};

class CircleCheckBox : public Circle {
	//#radio_mode
};

class Triangle : public Geometric2D {

};

class Polygon : public Geometric2D {

};

#endif
