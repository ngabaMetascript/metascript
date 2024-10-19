#include "MetaScene.h"

using namespace std;

MetaScene::MetaScene(){

}

MetaScene::~MetaScene(){

}

Scene* MetaScene::getScene(){
	return scene;
}

void MetaScene::setScene(Scene* arg){
	scene = arg;
}

void MetaScene::addElt(Elt* arg){
	elts.push_back(arg);
}

string MetaScene::render(){
	string result = "<!DOCTYPE HTML>\n<html>";
	// Scene
	result += scene->render();
	// Components
	result += "<script>";
	for ( Elt* elt : elts){
		result += elt->render(nature); 
	}
	result += "</script></html>";
	return result;
}

void MetaScene::generate(){
	string file_name = scene->getName();
	ofstream file_result(file_name+".html");
	file_result<<render();
}


