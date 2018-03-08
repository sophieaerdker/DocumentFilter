#pragma once
#include"Document.h"
#include<iostream>

class Recipe : public Document
{
public:

	Recipe();
	static Recipe load(std::istream &);
	Recipe(const Recipe &other) = delete;
	Recipe(Recipe && other) = default;
	Recipe& operator=(Recipe && other) = default;
	std::string get_title() override;
	std::string get_documentType() override;
	std::string get_content() override;

	std::string get_otherStringInformation() override;
  int get_otherIntInformation() override;

	int get_time();
	std::string get_flags();

private:

	std::string m_title;
	std::string m_content;

	int m_time;
	std::string m_flags;


};
