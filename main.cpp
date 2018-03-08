#include "listFilesInDirectory.h"
#include "Document.h"
#include "Recipe.h"
#include "Notes.h"
#include "NoteFilter.h"
#include "RecipeFilter.h"
#include "Filter.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <typeinfo>


int main() {

	// TODO: getline delete \r!
	
	std::vector<Document*> DocumentStorage;
	std::vector<std::string> fileList;
	fileList = listFilesInDirectory("files_recipe_note");

	for (int i = 0; i < fileList.size(); ++i) {

		std::string fileName = fileList[i];
		std::fstream file;
		file.open(fileName.c_str(), std::ios::in);
		std::string fileLine;

		//get first line:
		getline(file, fileLine);

		//search for "class":
		if (fileLine.find("class") < fileLine.length()) {

			if (fileLine.find("Recipe") < fileLine.length()) {


				DocumentStorage.push_back(new Recipe(Recipe::load(file)));
			}
			else if (fileLine.find("Note") < fileLine.length()) {

				DocumentStorage.push_back(new Notes(Notes::load(file)));
			}
		}

	}


//print all documents:
	for (int i = 0; i < DocumentStorage.size(); ++i) {

		std::cout << DocumentStorage[i]->get_documentType() << "\t" << DocumentStorage[i]->get_title() << std::endl;
	}


try{
for(int i = 0; i < DocumentStorage.size(); ++i){

	if(DocumentStorage[i]->get_documentType() == "Recipe"){

	RecipeFilter Filter("time", "10", "is");


	if(Filter.eval(*DocumentStorage[i]))
	{
		std::cout <<  DocumentStorage[i]->get_documentType() << '\n' <<DocumentStorage[i]->get_title() <<"\n True!\n";
	}
	else{
		std::cout <<  DocumentStorage[i]->get_documentType() << '\n' << DocumentStorage[i]->get_title() <<"\n False...\n";
	}
}else if(DocumentStorage[i]->get_documentType() == "Notes"){

	NoteFilter Filter("title", "Brot", "is");

	if(Filter.eval(*DocumentStorage[i]))
	{
		std::cout << DocumentStorage[i]->get_documentType() << '\n' << DocumentStorage[i]->get_title() << "\n True!\n";
	}
	else{
		std::cout << DocumentStorage[i]->get_documentType() << '\n' << DocumentStorage[i]->get_title() << "\n False...\n";
	}
}
}
}catch(const std::invalid_argument &e){
	std::cout << "Search terminated:" << e.what() << std::endl;
}



for(int i= 0; i < DocumentStorage.size(); ++i){

	delete DocumentStorage[i];
}
return 0;
}
