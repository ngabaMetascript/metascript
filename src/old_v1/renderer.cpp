#include <vector>
#include <string>
#include <iostream>
#include "renderer.h"

#define GET_VARIABLE_NAME(variable) (#variable)

using namespace std;
namespace webRenderer
{

	Geometric2DRenderer::Geometric2DRenderer(Geometric2D* arg){
		component = arg;
	}

	SceneRenderer::	SceneRenderer(WebScene* arg){
		scene = arg;
	}

	// Renderers
	string ComponentRenderer::renderer(){
		string result = "asas";
		return result;
	}

	string ImageInfoRenderer::renderer(){
	
	}
	
	
	string AudioInfoRenderer::renderer(){
	
	}
	
	
	string TextInfoRenderer::renderer(){
	
	}
	
	
	string VideoInfoRenderer::renderer(){
	
	}


	string Geometric2DRenderer::renderer(){
		vector<string> instructions;
		Geometric2D* geom = component; 
		string name = geom->getName();
		
		
		instructions.push_back( name+" = document.createElement("+"div"+")" );
		
		instructions.push_back( name+".setAttribute('id','"+name+"')");
		instructions.push_back( name+".style.border = "+geom->getBorder() );
		instructions.push_back( name+".style.boxShadow = "+geom->getBoxShadow() );
		instructions.push_back( name+".style.margin = "+geom->getMargin() );
		instructions.push_back( name+".style.padding = "+geom->getPadding() );
		
		cout<<name<<endl;
		
		instructions.push_back(name+".setAttribute('id','"+name+"')");
		for ( DataAttribute da : geom->getDataAttributes()){
			if (da.field == "data-class"){
				instructions.push_back(name+".setAttribute('class','"+da.value+"')");
			}
			else if(da.field == "data-component->getName()"){
				instructions.push_back(name+".setAttribute('component->getName()','"+da.value+"')");
			}
			else{
				instructions.push_back(name+".setAttribute('"+da.field+"','"+da.value+"')");
			}
		}
		
		if ( geom->getParent() == nullptr){
			instructions.push_back("document.appendChild("+name+")");
		}
		else{
			string parent_name = GET_VARIABLE_NAME(geom->getParent());
			instructions.push_back(parent_name+".appendChild("+name+")");
		}	
		
		string result;
		for (string inst : instructions){
			result += inst+";\n";
		}
		
		return result;
	}

	string RectangleRenderer::renderer(){
		vector<string> instructions;
		Rectangle* rect = component; 
		instructions.push_back( component->getName()+".style.width = "+to_string(rect->getWidth()) );
		instructions.push_back( component->getName()+".style.height = "+to_string(rect->getHeight()) );
		/*
		/content parcours
		*/
		string result = dynamic_cast<Geometric2DRenderer*>(this)->renderer();
		for (string inst : instructions){
			result += inst+"\n";
		}
		
		return result;
	}

	
	string CircleRenderer::renderer(){
		vector<string> instructions;
		Circle* circ = component;
		instructions.push_back( component->getName()+".style.width = "+to_string(circ->getRadius()) );
		instructions.push_back( component->getName()+".style.height = "+to_string(circ->getRadius()) );
		instructions.push_back( component->getName()+".style.borderRadius = 100%");
		/*
		/content parcours
		*/
		string result = dynamic_cast<Geometric2DRenderer*>(this)->renderer();
		for (string inst : instructions){
			result += inst+"\n";
		}
		
		return result;
	}

	// string renderer(Triangle tria){}

	// string renderer(Polygon poly){}
	
	
	string SceneRenderer::renderer( vector<ComponentRenderer*> components){
		vector<string> lines;
		vector<string> tests;
		string result="";
		cout<<"sssss"<<endl;

		lines.push_back("<!-- graphical WebScene rendered in MetaScript -->\n");
		lines.push_back("!DOCTYPE<HTML>\n<html>");
		lines.push_back("<head>");
		/*
		for ( string meta_link : scene->getMetaLinks()){
			lines.push_back( meta_link );
		}
		
		for ( string css_sheet : scene->getCssSheets()){
			lines.push_back( css_sheet );
		}
		*/
		cout<<"sssss"<<endl;
		lines.push_back("</head>");
		lines.push_back("<body> <div id='scene'> </div> </body>");
		for ( string js_script : scene->getJsScripts()){
			lines.push_back( js_script );
		}
		lines.push_back("<script>");		
		
		/*for ( ComponentRenderer* compo : components){
			lines.push_back(compo->renderer());//renderer(compo));
		}*/
		
		lines.push_back("</script></html>");
		
		for (string line : lines){
			result += line+"\n";
		}
		return result;
	}
}

//namespace phaserRenderer
namespace phaserRenderer
{

}
