#include "Recipe.h"
#include <string>
#include <vector>

Recipe::Recipe() {



}

 Recipe Recipe::load(std::istream & file) {

		Recipe R;
	 std::string fileLine;
	 std::string Numbers = "0123456789";

	 int i = 0;
	 while (!file.eof())
	 {
		 getline(file, fileLine);

		 if (fileLine.find("Title:") < fileLine.length())
		 {
			 fileLine = fileLine.substr(6);
			 R.m_title = fileLine;
		 }
		 else if(fileLine.find("Content:") < fileLine.length())
		 {
			 fileLine = fileLine.substr(8);
			 R.m_content = fileLine;
		 }
		 else if (fileLine.find("Time:") < fileLine.length())
		 {
			 fileLine = fileLine.substr(5);
			 std::string::iterator it;
			 for (it = fileLine.begin(); it != fileLine.end(); ++it)
			 {
				 //search for other symbols and replace them:
				 if (Numbers.find(*it) > Numbers.length())
				 {
					 *it = ' ';
				 }
			 }

			 R.m_time = stoi(fileLine);
		 }
		 else if (fileLine.find("Flags:") < fileLine.length()) {

			 fileLine = fileLine.substr(6);
			 R.m_flags = fileLine;
		 }
	 }
	 return R;

}
std::string Recipe::get_otherStringInformation(){
	return get_flags();
}

int Recipe::get_otherIntInformation(){
	return get_time();
}


std::string Recipe::get_content() {

	return m_content;

}
std::string Recipe::get_documentType() {
	return "Recipe";
}
std::string Recipe::get_flags() {
	return m_flags;
}
std::string Recipe::get_title() {
	return m_title;
}
int Recipe::get_time() {
	return m_time;
}
