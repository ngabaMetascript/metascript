#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include <string>
#include "dataStructure.h"
#include "renderer.h"

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

class WebMetaWorld{
	Server* server;
	DataBase* db;
	webRenderer::WebSceneRenderer* world;
}

#endif
