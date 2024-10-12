#ifndef GRAPHICALSCENE_H
#define GRAPHICALSCENE_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "dataStructure.h"
#include "renderer.h"
#include "scene.h"

// A - The WebScene
struct WebConfig{
	string field;
	string value;
};   

linkedList::LinkedList <webRenderer::ComponentRenderer*> sceneComponents;
map<std::string, linkedList::LinkedList<std::string> > webConfigs;
WebScene WEBSCENE_MAIN = WebScene();

void readConfigs(){ // #
	// std::vector<WebConfig> webConfigs;
	std::ifstream myfile;
	myfile.open ("WEBSCENE_CONFIG.cnf", std::ios::in);
	std::string line, field;
	WebConfig config;
	
	if ( myfile.is_open() ) {
		while ( myfile ) {
			std::getline (myfile, line);
			if ( line[0] == '#'){
				field = line;			
			}
			else{
				webConfigs[field].insertAtBeginning(line);			
			}
		}
	}
	else {
		std::cout << "Couldn't open file\n";
	}
} 

void createWebscene(){	
	readConfigs();
	WEBSCENE_MAIN.setMetaLinks(webConfigs["#meta"]);
	WEBSCENE_MAIN.setCssSheets(webConfigs["#css"]);
	WEBSCENE_MAIN.setJsScripts(webConfigs["#js"]);
}


webRenderer::SceneRenderer* webSceneInitializer(){
	createWebscene();
	webRenderer::SceneRenderer* WEBSCENE_RENDERER = new webRenderer::SceneRenderer(&WEBSCENE_MAIN);

	std::string scene_name = "scene";
	Geometric2D* scene2D = new Geometric2D(scene_name);
	
	
	Rectangle* stupid_thing = new Rectangle(scene_name+"rectangle");
	stupid_thing->setParent(scene2D);
		
	TextInfo* text_info = new TextInfo("<div><b> Bonjour tout le Monde </b></div>");
	stupid_thing->setInfos(text_info);
	
	webRenderer::Geometric2DRenderer* sceneRenderer = new webRenderer::Geometric2DRenderer(scene2D);
	webRenderer::RectangleRenderer* rectangleRenderer = new webRenderer::RectangleRenderer(stupid_thing);
	
	sceneComponents.insertAtBeginning(sceneRenderer);
	sceneComponents.insertAtEnd(rectangleRenderer);
	
	// Par Defaut Creer un Composant de type Scene
	return WEBSCENE_RENDERER;
}

// WEBSCENE_MAIN.setMetaLinks(string);
// WEBSCENE_MAIN.setCssLinks();
// WEBSCENE_MAIN.setJsScript();

#endif
