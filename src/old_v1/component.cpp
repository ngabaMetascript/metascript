#include "component.h"

// COMPONENTS METHODS=================================================
Component :: Component (){

}

Component :: Component (string arg){
	name = arg;
}

Component* Component :: getParent(){
	return parent;
}

string Component :: getName(){
	return name;
}

vector<DataAttribute> Component :: getDataAttributes()
{
	return dataAttributes;
}


void Component :: setScene(Scene* arg){
	scene = arg;
}

// GEOMETRIC METHODS=================================================
Geometric :: Geometric (){

}

Geometric :: Geometric (string arg){
	name = arg;
}

Geometric :: ~Geometric (){

}

// GEOMETRIC2D METHODS=================================================
Geometric2D :: Geometric2D (){
	
}

Geometric2D :: Geometric2D (string arg){
	name = arg;
}

Geometric2D :: ~Geometric2D(){

}

Rectangle :: Rectangle(){
	
}

Rectangle :: Rectangle(int a, int b){
	width = a;
	height = b;
}

Rectangle :: ~Rectangle(){

}


