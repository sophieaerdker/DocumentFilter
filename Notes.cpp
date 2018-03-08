#include "Notes.h"
#include <string>
#include <vector>

Notes::Notes() {



}

Notes Notes::load(std::istream & file) {

	Notes R;
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
		else if (fileLine.find("Content:") < fileLine.length())
		{
			fileLine = fileLine.substr(8);
			R.m_content = fileLine;
		}
		else if (fileLine.find("Topic:") < fileLine.length()) {

			fileLine = fileLine.substr(6);
			R.m_topic = fileLine;
		}
	}
	return R;

}

std::string Notes::get_content() {

	return m_content;

}
std::string Notes::get_documentType() {
	return "Notes";
}
std::string Notes::get_otherStringInformation(){
	return get_topic();
}

int Notes::get_otherIntInformation(){
	return -1;
}

std::string Notes::get_title() {
	return m_title;
}
std::string Notes::get_topic() {
	return m_topic;
}
