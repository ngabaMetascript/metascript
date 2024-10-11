#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
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
