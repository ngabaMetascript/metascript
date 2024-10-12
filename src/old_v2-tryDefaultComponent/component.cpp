#include "component.h"

// COMPONENTS METHODS =================================================
Component :: Component (){

}

Component :: Component (std::string arg){
	name = arg;
}

Component* Component :: getParent(){
	return parent;
}

std::string Component :: getName(){
	return name;
}

linkedList::LinkedList<DataAttribute*> Component :: getDataAttributes(void){
	return dataAttributes;
}



void Component :: setName (std::string arg){
	name = arg;
}

void Component :: setParent(Component* arg){
	parent = arg;
}

void Component :: setAttributes(DataAttribute* arg){
	dataAttributes.insertAtEnd(arg);
}

void Component :: setAttributes(DataAttribute* arg, DataAttribute* args...){
	dataAttributes.insertAtEnd(arg);
	setAttributes(args);
}

void Component:: setAttributes(linkedList::LinkedList<DataAttribute*> arg){

}




// GEOMETRIC METHODS=================================================
Geometric :: Geometric (){

}

Geometric :: Geometric (std::string arg){
	name = arg;
}

Geometric :: ~Geometric (){

}

void Geometric :: setInfos(InfoComponent* arg){
	infos.insertAtEnd(arg);
}

void Geometric :: setInfos(InfoComponent* arg, InfoComponent* args... ){
	setInfos(arg);
	setInfos(args);
}

void Geometric :: setInfos(linkedList::LinkedList<InfoComponent*> arg){
	infos = arg;
}

linkedList::LinkedList<InfoComponent*> Geometric :: getInfos(){
	return infos;
}


// GEOMETRIC2D METHODS=================================================
Geometric2D :: Geometric2D (){
	
}

Geometric2D :: Geometric2D (std::string arg){
	name = arg;
}

Geometric2D :: ~Geometric2D(){

}

string Geometric2D :: getName(){
	return name;
}

Rectangle::Rectangle(){
	
}

Rectangle::Rectangle(std::string arg){
	name = arg;
}

Rectangle :: Rectangle(int a, int b){
	width = a;
	height = b;
}

Rectangle :: ~Rectangle(){

}


