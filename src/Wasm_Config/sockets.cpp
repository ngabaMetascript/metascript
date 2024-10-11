#include <iostream>
#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>


using namespace std;

int main() {
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	
	bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
	
	listen(serverSocket,5);
	
	int clientSocket = accept(serverSocket, nullptr, nullptr);
	char buffer[1024] = {0};
	recv(clientSocket, buffer, sizeof(buffer), 0);
	cout<<buffer<<" Message "<<endl;
	
	cout << serverSocket << endl;
	if(system(nullptr)){
		cout<<"Yes Command Processor is present";
		system("ls");
	}
	else{
		cout<<"No Command Processor is not present";
	}
	//system("pause");
	return 0;
}

/*
int execvp (const char *file, char *const argv[]);

    file: points to the file name associated with the file being executed. 
    argv:  is a null terminated array of character pointers.
    Let us see a small example to show how to use execvp() function in C. We will have two .C files , EXEC.c and execDemo.c and we will replace the execDemo.c with EXEC.c by calling execvp() function in execDemo.c .

*/
