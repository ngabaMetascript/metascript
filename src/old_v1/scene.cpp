#include "scene.h"
// Links Setter

WebScene::WebScene()
{

}

WebScene::~WebScene()
{

}

void WebScene::setMetaLinks(string meta)
{
	meta_links.push_back(meta);
}

void WebScene::setMetaLinks(string meta, string args...)
{
	meta_links.push_back(meta);
	setMetaLinks(args);
}



void WebScene::setCssLinks(string css)
{
	css_sheets.push_back("<link rel='stylesheet' href='"+css+"'>");
}

void WebScene::setCssLinks(string css, string args...)
{
	WebScene::setCssLinks(css);
	WebScene::setCssLinks(args);
}

void WebScene::setCssLinks(std::vector<std::string> links){
	for ( std::string link : links){
		WebScene::setCssLinks(link);
	}
}


void WebScene::setJsScripts(string js)
{
	js_scripts.push_back("<script src='"+js+"'>");
}

void WebScene::setJsScripts(string js, string args...)
{
	WebScene::setJsScripts(js);
	WebScene::setJsScripts(args);
}

void WebScene::setJsScripts(std::vector<std::string> scripts)
{
	
	for ( std::string script : scripts){
		WebScene::setJsScripts(script);
	}
	
}

std::vector<std::string> WebScene::getMetaLinks()
{
	return meta_links;
}

std::vector<std::string> WebScene::getCssSheets(){
	return css_sheets;
}

std::vector<std::string> WebScene::getJsScripts()
{
	return js_scripts;
}

/*
string WebScene::renderer(){
	webRenderer::renderer(this);
};
*/


Doc Tappamo : 6 75 84 52 88 / 6 99 67 40 23
