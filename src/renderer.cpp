#include <vector>
#include <string>
#include <iostream>
#include "renderer.h"

#define GET_VARIABLE_NAME(variable) (#variable)

namespace webRenderer
{
	std::string rendererAttribute(DataAttribute dta_arg,std::string elt_arg){
		std::string result = "";
		if (dta_arg.field == "data-tag") result = elt_arg+"tagName = "+dta_arg.value;
		return result;
	}

	// Renderers
	std::string ComponentRenderer::renderer(){
		std::string result = "";
		return result;
	}

	std::string InfoRenderer::renderer(){
		string instructions="";
		return instructions;
	}

	std::string ImageInfoRenderer::renderer(){
		string instructions="";
		string name = component->getName();
		
		instructions += name+" = document.createElement("+"img"+");" ;
		instructions += name+".setAttribute('id','"+name+"');";
		instructions += name+".setAttribute('src'," + component->getValue()+ ");";
		return instructions;
	}

	std::string AudioInfoRenderer::renderer(){
		string instructions="";
		string name = component->getName();
		
		instructions += name+" = document.createElement("+"iframe"+");" ;
		instructions += name+".setAttribute('id','"+name+"');";
		instructions += name+".setAttribute('src'," + component->getValue()+ ");";
		return instructions;
	}

	std::string TextInfoRenderer::renderer(){
		string instructions;
		string name = component->getName();

		instructions += name+" = document.createElement("+"span"+");" ;
		instructions += name+".setAttribute('id','"+name+"');";
		instructions += name+".innerHTML =" + component->getValue()+");";
		return instructions;
	}

	std::string VideoInfoRenderer::renderer(){
		string instructions="";
		string name = component->getName();
		
		instructions += name+" = document.createElement("+"iframe"+");" ;
		instructions += name+".setAttribute('id','"+name+"');";
		instructions += name+".setAttribute('src'," + component->getValue()+ ");";
		return instructions;
	}

	std::string Geometric2DRenderer::renderer(){
		std::string instructions="";	
		std::string name = component->getName();
		
		instructions += name+" = document.createElement("+"div"+")" +";";
		instructions += name+".setAttribute('id','"+name+"')" +";";

		if ( component->getBoxShadow() != "") { instructions += name+".style.border = "+component->getBorder() +";"; }
		if ( component->getMargin() != "" ) { instructions += name+".style.margin = "+component->getMargin() +";" ; }
		if ( component->getPadding() != "" ) { instructions += name+".style.padding = "+component->getPadding() +";"; }
		
		instructions += name+".setAttribute('id','"+name+"')" +";";
		
		Node<DataAttribute*>* da = component->getDataAttributes().getValue();	
		while( da != nullptr){
			if (da->data->field == "data-class"){
				instructions += name+".setAttribute('class','"+da->data->value+"')" ;
			}
			else if(da->data->field == "data-name"){
				instructions += name+".setAttribute('name','"+da->data->value+"')" ;
			}
			else if(da->data->field == "data-id"){
				instructions += name+".setAttribute('id','"+da->data->value+"')" ;
			}
			else{
				instructions += name+".setAttribute('"+da->data->field+"','"+da->data->value+"')";
			}
			da = da->next;
		}
		
		Node<InfoComponent*>* info = component->getInfos().getValue();	
		while( info != nullptr){
			// instructions += info->data->renderer("WEB");
			info = info->next;
		}

		/*
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
		*/

		if ( component->getParent() == nullptr){
			instructions += "document.appendChild("+name+") ;";
		}
		else{
			Component* parent = component->getParent();
			instructions += parent->getName()+".appendChild("+name+") ;";
		}	
		return instructions;
	}

	string RectangleRenderer::renderer(){
		//return component->getName();
		Geometric2D* arg_component = component;
		Geometric2DRenderer* geoRenderer = new Geometric2DRenderer(arg_component);
		
		string instructions =  geoRenderer->renderer(); "Geometric2DRenderer::renderer();";
		if ( component->getWidth() != 0) { instructions += component->getName()+".style.width = "+to_string(component->getWidth()) +";"; }
		if ( component->getHeight() != 0) { instructions += component->getName()+".style.height = "+to_string(component->getHeight())+";"; }
		/*
		/content parcours
		*/
		return instructions;
	}

	std::string SceneRenderer::renderer( LinkedList<ComponentRenderer*> components){	
		string instructions = "<!-- graphical WebScene rendered in MetaScript -->\n";
		instructions += "!DOCTYPE<HTML>\n<html>";
		instructions += "<head>";

		Node<string>* css = scene->getCssSheets().getValue();
		while (css != nullptr ){
			instructions += "<link rel='stylesheet' href='"+css->data+"' >";//arg_component->getName();
			css = css->next;
		}

		/*
		for ( string meta_link : scene->getMetaLinks()){
			lines.push_back( meta_link );
		}
		
		for ( string css_sheet : scene->getCssSheets()){
			lines.push_back( css_sheet );
		}
		*/
		instructions += "</head>";
		instructions += "<body> <div id='scene'> </div> </body>";

		Node<string>* js = scene->getJsScripts().getValue();
		while (css != nullptr ){
			instructions += "<script src='"+js->data+"' >";//arg_component->getName();
			js = js->next;
		}

		instructions += "<script>";	

		Node<ComponentRenderer*>* compo = components.getValue();	
		if (compo){
			while(compo != nullptr && compo->data != nullptr){
				instructions += compo->data->renderer();//arg_component->getName();
				compo = compo->next;
			}
		}

		/*for ( ComponentRenderer* compo : components){
			lines.push_back(compo->renderer());//renderer(compo));
		}*/
		
		instructions += "</script></html>";
		return instructions;
	}

}

//namespace phaserRenderer
namespace phaserRenderer
{

}
