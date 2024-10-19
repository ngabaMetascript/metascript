# include "Elt.h"
# include "Renderer.h"
using namespace std;

// =======================================================================

Elt::Elt(){

}

string Elt :: render(string arg){
	string result = "";
	if ( arg == "WEB"){ result = webRenderer :: rendererElt(this); }
	return result;
}

void Elt::setAttributes(DataAttribute* arg){
	attributes.push_back(arg);
}

void Elt::setAttributes(DataAttribute* arg, DataAttribute* args...){
	Elt::setAttributes(arg);
	Elt::setAttributes(args);
}

void Elt::setAttributes(vector<DataAttribute*> args){
	attributes = args;
}


// EltInfo ================================================================

EltInfo :: EltInfo(){


}

EltInfo :: EltInfo(string arg){
	value = arg;
}

EltInfo :: ~EltInfo(){

}

string EltInfo :: render(string arg){
	string result = "";
	if ( arg == "WEB"){ result = webRenderer :: rendererElt(this); }
	return result;
}


TextInfo :: TextInfo(){

}

TextInfo :: TextInfo(string arg){
	value = arg;
}
		
TextInfo :: ~TextInfo(){

}

string TextInfo :: render(string arg){
	string result = "";
	if ( arg == "WEB"){ result = webRenderer :: rendererText(this); }
	return result;
}



namespace c2D{
	Point2D :: Point2D(){
	
	}
	Point2D :: Point2D(int arg1, int arg2){
		x = arg1;
		y = arg2;
	}

	void Shape::addInfos(EltInfo* arg){
		infos.push_back(arg);
	}

	void Shape::addInfos(EltInfo* arg, EltInfo* args...){
		infos.push_back(arg);
		Shape::addInfos(arg);
	}
	void Shape::addInfos(vector<EltInfo*> arg){
		infos = arg;
	}	
	
	Line :: Line(){
	
	}
	
	Line :: Line(Point2D* arg1, Point2D* arg2){
		a = arg1;
		b = arg2;
	}
	
	string Line :: render(string arg="WEB"){
		string result = "";
		if ( arg == "WEB"){ result = webRenderer :: rendererLine(this); }
		return result;
	}

	
	Rectangle :: Rectangle(){
	
	}
	
	Rectangle :: Rectangle(Line* arg1, Line* arg2){
		width = arg1;
		height = arg2;
	}

	string Rectangle :: render(string arg){
		string result = "";
		if ( arg == "WEB"){ result = webRenderer :: rendererRectangle(this); }
		return result;
	}


	Circle :: Circle(){
	
	}
	
	Circle :: Circle(Point2D* arg1, float arg2){
		center = arg1;
		radius - arg2;
	}

}

