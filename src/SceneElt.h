#ifndef SCENE_H
#define SCENE_H


#include <string>
#include <map>
#include <vector>

struct QuerySet{
	string name;
	string query;
	map<string, string> result;
};

class MetaScene{
	Scene* scene;
	vector<Elt*> elts;
	vector<QuerySet*> queries;
}

#endif
