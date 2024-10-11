#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "dataStructure.h"
//#include "scene.h"
using namespace std;

struct NumericValue{
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
		string display="";
		string position="";
		linkedList::LinkedList<DataAttribute*> dataAttributes;
		Component* parent= nullptr;
		// Scene* scene;

	public:
		Component();
		Component(string);
		Component* getParent(void);
		
		virtual string getName();
		linkedList::LinkedList<DataAttribute*> getDataAttributes(void);
		void setParent(Component*);
		// void setScene(Scene*);
		virtual void setName(string);
		virtual void setAttributes(DataAttribute*);
		virtual void setAttributes(DataAttribute*, DataAttribute*...);
		virtual void setAttributes(linkedList::LinkedList<DataAttribute*>);
};


// ================================================================================
class InfoComponent : public Component {
	protected:
		string value;
	public:
		InfoComponent(){}
		InfoComponent(string arg){value=arg;}
		virtual string getValue(){return value;}
};

class TextInfo : public InfoComponent{
	public:
		TextInfo(string arg){value=arg;}
};

class ImageInfo : public InfoComponent{

};

class VideoInfo : public InfoComponent{

};

class AudioInfo : public InfoComponent{

};

// ================================================================================
class Geometric : public Component{
	protected:
		linkedList::LinkedList<InfoComponent*> infos;
	public:
		Geometric();
		Geometric(string);
		~Geometric();
		void setInfos(InfoComponent*);
		void setInfos(InfoComponent*, InfoComponent* ...);
		void setInfos(linkedList::LinkedList<InfoComponent*>);
		
		linkedList::LinkedList<InfoComponent*> getInfos();
};

class Geometric2D : public Geometric{
	protected:
		//InfoComponent* background=nullptr;
		//InfoComponent** content=nullptr;
		
		std::string padding="";
		std::string margin="";	
		std::string border="";
		string boxShadow="";	
	public:
		Geometric2D();
		Geometric2D(std::string);
		~Geometric2D();
		string getName();
		string getPadding(){return padding;}
		string getMargin(){return margin;}
		std::string getBorder(){return border;}
		string getBoxShadow(){return boxShadow;}
};

class Rectangle : public Geometric2D {
	protected:
		int width=0,height=0;
	public:
		Rectangle();
		Rectangle(int,int);
		Rectangle(string);
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
