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
		vector<TimerProcess> timers;
};

class WebScene : public Scene{
	protected:
		LinkedList<string> meta_links;
		LinkedList<string> head_links;
		LinkedList<string> css_sheets;
		
		LinkedList<string> js_scripts_header;
		LinkedList<string> js_scripts;

	public:
		WebScene();
		~WebScene();
		void setMetaLinks(string);
		void setMetaLinks(string, string...);
		void setMetaLinks(LinkedList<string>);
		LinkedList<string> getMetaLinks();
		
		void setCssSheets(string);
		void setCssSheets(string, string...);
		void setCssSheets(LinkedList<string>);
		LinkedList<string> getCssSheets();
		
		void setJsScripts(string);
		void setJsScripts(string, string...);
		void setJsScripts(LinkedList<string>);
		LinkedList<string> getJsScripts();
		
};

class PhaserScene : public WebScene {

};

#endif
