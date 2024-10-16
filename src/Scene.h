#ifndef SCENE_H
#define SCENE_H


#include <string>
#include <vector>
using namespace std;

class Scene{
	protected:
		// time is naturally configured
		// space is naturally configured
		string name;
		string corpus;
		vector<TimerProcess> timers;
	public:
		virtual string render();
};

class WebScene : public Scene{
	protected:
		vector<string> meta_links;
		vector<string> head_links;
		vector<string> css_sheets;
		
		vector<string> js_scripts_header;
		vector<string> js_scripts;

		

	public:
		WebScene();
		~WebScene();
		void setMetaLinks(string);
		void setMetaLinks(string, string...);
		void setMetaLinks(vector<string>);
		vector<string> getMetaLinks();
		
		void setCssSheets(string);
		void setCssSheets(string, string...);
		void setCssSheets(vector<string>);
		vector<string> getCssSheets();
		
		void setJsScripts(string);
		void setJsScripts(string, string...);
		void setJsScripts(vector<string>);
		vector<string> getJsScripts();
		
};

class PhaserScene : public WebScene {

};

#endif
