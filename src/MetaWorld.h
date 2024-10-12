#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include <string>

using namespace std;
using namespace linkedList;

enum ServerName {Node, Nodemon, WebAssembly, MetaServer};

namespace worldSetuper{
	struct Server {
		ServerName name;
		int port;
		string ip;
		int serverPID;
		int startServer(){
		
		} // Launch the server and return the PID
		void stopServer(){
		
		}
	};
	
	struct DataBase {
		string name;
		int port
		string ip;
		int dBPID;
	};
	
	struct Router {
	
	};
	
	struct Socket {
	
	};
}

class MetaWorld{
	
}

class WebMetaWorld : public MetaWorld{
	Server* server;
	DataBase* db;
	Router* rt;
	vector<Socket*> scks;

	vector<SceneElt*> scenes;
	//webRenderer::WebSceneRenderer* world_renderer;
}

#endif
