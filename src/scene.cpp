#include <string>
#include "scene.h"
#include "dataStructure.h"
// Links Setter

using namespace linkedList;
WebScene::WebScene()
{

}

WebScene::~WebScene()
{

}

void WebScene::setMetaLinks(std::string meta)
{
	meta_links.insertAtBeginning("<meta "+meta+" >");
}

void WebScene::setMetaLinks(string meta, string args...)
{
	meta_links.insertAtBeginning(meta);
	setMetaLinks(args);
}

void WebScene::setMetaLinks(LinkedList<string> links){
	meta_links = links;
}


void WebScene::setCssSheets(string css)
{
	css_sheets.insertAtBeginning("<link rel='stylesheet' href='"+css+"'>");
}

void WebScene::setCssSheets(string css, string args...)
{
	WebScene::setCssSheets(css);
	WebScene::setCssSheets(args);
}

void WebScene::setCssSheets(LinkedList<string> sheets){
	css_sheets = sheets;
}


void WebScene::setJsScripts(string js)
{
	js_scripts.insertAtBeginning("<script src='"+js+"'>");
}

void WebScene::setJsScripts(string js, string args...)
{
	WebScene::setJsScripts(js);
	WebScene::setJsScripts(args);
}

void WebScene::setJsScripts(LinkedList<std::string> scripts)
{
	
	js_scripts = scripts;
	
}

/*


std::vector<std::string> WebScene::getMetaLinks()
{
	return meta_links;
}




/*
string WebScene::renderer(){
	webRenderer::renderer(this);
};

*/
LinkedList<string> WebScene::getCssSheets(){
	return css_sheets;
}

LinkedList<std::string> WebScene::getJsScripts()
{
	return js_scripts;
}

// Doc Tappamo : 6 75 84 52 88 / 6 99 67 40 23
