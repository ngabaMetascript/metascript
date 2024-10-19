#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Scene.h"
#include "Renderer.h"
#include "MetaScene.h"

int main()
{
	//std::ofstream kll("tesFile.txt");
	//kll<<"Bonjour \nEuil!!";
	//kll.close();
	WebScene *scene = new WebScene();
	scene->setName("index");
	scene->setCssSheets("bootstrap.min.css","fontaweome.min.css");
	scene->setJsScripts("jquery.min.css","slider.js");
	

	c2D::Point2D *a = new c2D::Point2D(1,1), *b = new c2D::Point2D(3,1),*c = new c2D::Point2D(3,0);
	c2D::Line *l1 = new c2D::Line(a,b), *l2 = new c2D::Line(b,c);
	c2D::Rectangle* r1 = new c2D::Rectangle(l1,l2);	
	r1->setName("recky");
	r1->addInfos(new TextInfo("Bonjour Tout le Monde"));

	MetaScene* meta_scene = new MetaScene();	
	meta_scene->addElt(r1);
	meta_scene->setScene(scene);	
	meta_scene->generate();
	return 0; 
} 
