#pragma once
#include<string>
#include<iostream>

 class Document {

public:
	Document() {}
	Document(std::istream &) {}
	Document(const Document & doc) = delete;
	Document & operator=(const Document & doc) = delete;
	Document(Document && other) = default;
	Document& operator=(Document && other) = default;
	virtual std::string get_title() = 0;
	virtual std::string get_documentType() = 0;
	virtual std::string get_content() = 0;
  virtual std::string get_otherStringInformation() = 0;
  virtual int get_otherIntInformation() = 0;
};
