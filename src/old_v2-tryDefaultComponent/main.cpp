// Note to Myself, in C++ Philosoy, dont use functions to the rendrer system but methods where the polymorphism is better represented

 #include "graphicalSystem.h"

#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdarg>


/*
template <typename T>
void func(T t) 
{
    std::cout << t << std::endl ;
}

template<typename T, typename... Args>
void func(T t, Args... args) // recursive variadic function
{
    std::cout << t <<std::endl ;

    func(args...) ;
}

template <class T>
void func2( std::initializer_list<T> list )
{
    for( auto elem : list )
    {
        std::cout << elem << std::endl ;
    }
}
*/

void setStr(std::string, std::string ...);

void setStr(std::string T){
	std::cout << T << std::endl ;
}

void setStr(std::string T, std::string args...){
	std::cout << T <<std::endl ;
	setStr(args) ;
}

int main()
{

    webRenderer::SceneRenderer* webSceneRenderer; 
    webSceneRenderer = webSceneInitializer();
    std::cout<<webSceneRenderer->renderer(sceneComponents);
    pid_t p;
    p = fork();
    if ( p == 0 )
    {
	   if(system(nullptr)){
		cout<<"Yes Command Processor is present";
		system("nodemon server.js &");
	   }
	   else
	   {
		cout<<"No Command Processor is not present";
	   }
     }
  /*
  std::string
        str1( "Hello" ),
        str2( "world" );

    func(1,2.5,'a',str1);
    func2( {10, 20, 30, 40 }) ;
    func2( {str1, str2 } ) ;
  */
  
  /*
  std::string a1="skjjkjks",a2="llkl";
  setStr(a1,a2); 
  */ 
} 
