#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../src/Scene.h"
#include "../src/Renderer.h"
#include "../src/MetaScene.h"

int main()
{
	//std::ofstream kll("tesFile.txt");
	//kll<<"Bonjour \nEuil!!";
	//kll.close();
	WebScene *scene = new WebScene();
	scene->setName("index");
	scena->setMetaLinks("utf='charset-utf8'","name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'");
	scene->setCssSheets("bootstrap.min.css","fontaweome.min.css");
	scene->setJsScripts("jquery.min.css","slider.js");
	scene->setHeadLinks("rel='preconnect' href='https://fonts.googleapis.com' ");
	
	c2D::Rectangle* navbar = new Rectangle(new c2D::Line(100,0,"vw"), new c2D::Line(0,40,"px")) 
	navbar->setName("navbar");
	navbar->addAttribute(new DataAttribute("data-class","navbar navbar-dark navbar-responsive py-3 px-2 d-flex");
	navbar->addAttribute(new DataAttribute("data-id","navbar");
	navbar->addInfo(new TextInfo("<b> Bybit Triangular Arbitrage </b>") );

	c2D::Rectangle* filterbar = new Rectangle(new c2D::Line(100,0,"vw"), new c2D::Line(0,40,"px")) 
	for (QuerySet* query in queries["filters"]){
	
	}


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
