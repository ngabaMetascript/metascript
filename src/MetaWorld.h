#ifndef SCENE_H
#define SCENE_H

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

enum ServerName {Node, Nodemon, WebAssembly, MetaServer};
enum SGBDName {MySQL, PostGreSQL, MongoDB, Casandra, SQLite};

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
		SGBDName SGBD;
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
	Server* server=nullptr;
	DataBase* db=nullptr;
	Router* rt=nullptr;
	vector<Socket*> scks;

	vector<MetaScene*> scenes;
}

#endif
