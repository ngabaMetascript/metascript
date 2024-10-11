#ifndef SCENE_H
#define SCENE_H


#include <string>
#include <vector>

using namespace std;

class Scene{
};

class WebScene : public Scene{
	protected:
		string title;
		vector<string> meta_links;
		//vector<string> head_links;
		
		vector<string> css_sheets;
		//vector<string> js_scripts_header;
		vector<string> js_scripts;
	public:
		WebScene();
		//WebScene(void (*config)() );
		~WebScene();
		void setMetaLinks(string);
		void setMetaLinks(string, string...);
		vector<string> getMetaLinks();
		
		void setCssLinks(string);
		void setCssLinks(string, string...);
		void setCssLinks(std::vector<string>);
		vector<string> getCssSheets();
		
		void setJsScripts(string);
		void setJsScripts(string, string...);
		void setJsScripts(std::vector<string>);
		vector<string> getJsScripts();
		
};

class PhaserScene : public WebScene {

};

#endif
