#pragma once
#include"Document.h"
#include<iostream>

class Notes : public Document
{
public:

	Notes();
	static Notes load(std::istream &);
	Notes(const Notes &other) = delete;
	Notes(Notes && other) = default;
	Notes& operator=(Notes && other) = default;
	std::string get_title() override;
	std::string get_documentType() override;
	std::string get_content() override;
	std::string get_topic();

	std::string get_otherStringInformation() override;
	int get_otherIntInformation() override;



private:

	std::string m_title;
	std::string m_content;

	std::string m_topic;




};
