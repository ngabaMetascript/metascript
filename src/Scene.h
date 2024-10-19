#ifndef SCENE_H
#define SCENE_H


#include <string>
#include <vector>
#include <fstream>
#include "TimerProcess.h"
using namespace std;



class Scene{
	protected:
		// time is naturally configured
		// space is naturally configured
		string name;
		string corpus;
		vector<TimerProcess> timers;
	public:
		Scene();
		~Scene();
		string getName();
		void setName(string);
		
		virtual string render();
		ofstream generate(string, string);
};

class WebScene : public Scene{
	protected:
		vector<string> meta_links;
		vector<string> head_links;
		vector<string> css_sheets;		
		vector<string> js_scripts_header;
		vector<string> js_scripts;
		//vector<string> static_urls;

	public:
		WebScene();
		~WebScene();		
		
		void setMetaLinks(string);
		void setMetaLinks(string, string...);
		void setMetaLinks(vector<string>);
		vector<string> getMetaLinks();
		
		void setHeadLinks(string);
		void setHeadLinks(string, string...);
		void setHeadLinks(vector<string>);
		vector<string> getHeadLinks();
				
		void setCssSheets(string);
		void setCssSheets(string, string...);
		void setCssSheets(vector<string>);
		vector<string> getCssSheets();

		void setJsScriptsHeader(string);
		void setJsScriptsHeader(string, string...);
		void setJsScriptsHeader(vector<string>);
		vector<string> getJsScriptsHeader();

		void setJsScripts(string);
		void setJsScripts(string, string...);
		void setJsScripts(vector<string>);
		vector<string> getJsScripts();
		
		virtual string render();
};

class PhaserScene : public WebScene {

};

#endif
