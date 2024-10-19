#ifndef METASCENE_H
#define METASCENE_H


#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Scene.h"
#include "Elt.h"

using namespace std;
struct QuerySet{
	string name;
	string query;
	map<string, string> result;
};

class MetaScene{
	string nature="WEB";// WEB , PHASER
	Scene* scene;
	vector<Elt*> elts;
	vector<QuerySet*> queries;
	public:
		MetaScene();
		~MetaScene();
		Scene* getScene();
		
		void addElt(Elt*);
		void setScene(Scene*);
		string render();
		void generate();
};

#endif
