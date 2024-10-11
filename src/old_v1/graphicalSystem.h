#ifndef SCENE_H
#define SCENE_F

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "renderer.h"

// A - The WebScene
struct WebConfig{
	string field;
	string value;
};   
std::vector <webRenderer::ComponentRenderer*> sceneComponents;
map<std::string, std::vector<std::string> > webConfigs;

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
				webConfigs[field].push_back(line);			
			}
		}
	}
	else {
		std::cout << "Couldn't open file\n";
	}
} 

webRenderer::SceneRenderer* webSceneInitializer(){
	WebScene WEBSCENE_MAIN = WebScene();
	readConfigs();
	WEBSCENE_MAIN.setCssLinks(webConfigs["#css"]);
	WEBSCENE_MAIN.setJsScripts(webConfigs["#js"]);
	webRenderer::SceneRenderer* WEBSCENE_RENDERER = new webRenderer::SceneRenderer(&WEBSCENE_MAIN);

	std::string scene_name = "scene";
	Geometric2D scene = Geometric2D(scene_name);
	scene.setScene(&WEBSCENE_MAIN);
	
	webRenderer::Geometric2DRenderer sceneRenderer = webRenderer::Geometric2DRenderer(&scene);
	//sceneComponents.push_back(&sceneRenderer);
	
	// Par Defaut Creer un Composant de type Scene
	return WEBSCENE_RENDERER;
}

// WEBSCENE_MAIN.setMetaLinks(string);
// WEBSCENE_MAIN.setCssLinks();
// WEBSCENE_MAIN.setJsScript();

#endif
