#include <vector>
#include <string>
#include "Scene.h"
#include "Renderer.h"
// Links Setter

using namespace std;

Scene::Scene(){

}

Scene::~Scene(){

}

string Scene::getName(){
	return name;
}

void Scene::setName(string arg){
	name = arg;
}

string Scene::render(){
	string result = "";
	return result;
}

WebScene::WebScene()
{

}

WebScene::~WebScene()
{

}

// ============================================================
void WebScene::setMetaLinks(string meta)
{
	meta_links.push_back("<meta "+meta+" >");
}

void WebScene::setMetaLinks(string meta, string args...)
{
	setMetaLinks(meta);
	setMetaLinks(args);
}

void WebScene::setMetaLinks(vector<string> links){
	meta_links = links;
}


// ==============================================================
void WebScene::setHeadLinks(string head){
	head_links.push_back("<link "+head+" >");
}
		
void WebScene::setHeadLinks(string meta, string args...){
	setHeadLinks(meta);
	setHeadLinks(args);
}
		
void WebScene::setHeadLinks(vector<string> links){
	head_links = links;
}

		
// ==============================================================
void WebScene::setCssSheets(string css)
{
	css_sheets.push_back("<link rel='stylesheet' href='"+css+"'>");
}

void WebScene::setCssSheets(string css, string args...)
{
	setCssSheets(css);
	setCssSheets(args);
}

void WebScene::setCssSheets(vector<string> sheets){
	css_sheets = sheets;
}


// ==============================================================
void WebScene::setJsScriptsHeader(string js){
	js_scripts_header.push_back("<script src='"+js+"' ></script>");
}
		
void WebScene::setJsScriptsHeader(string js, string args...){
	setJsScriptsHeader(js);
	setJsScriptsHeader(args);

}
		
void WebScene::setJsScriptsHeader(vector<string> js_header){
	js_scripts_header = js_header;
}

// ===============================================================
void WebScene::setJsScripts(string js)
{
	js_scripts.push_back("<script src='"+js+"'></script>");
}

void WebScene::setJsScripts(string js, string args...)
{
	setJsScripts(js);
	setJsScripts(args);
}

void WebScene::setJsScripts(vector<string> scripts)
{
	
	js_scripts = scripts;
	
}



// ==============================================================
vector<string> WebScene::getMetaLinks()
{
	return meta_links;
}

vector<string> WebScene::getHeadLinks()
{
	return head_links;
}

vector<string> WebScene::getCssSheets(){
	return css_sheets;
}

vector<string> WebScene::getJsScriptsHeader()
{
	return js_scripts_header;
}

vector<string> WebScene::getJsScripts()
{
	return js_scripts;
}


// ==================================================================
string WebScene::render(){
	string result = "";
	result = webRenderer::rendererScene(this);
	return result;
}
