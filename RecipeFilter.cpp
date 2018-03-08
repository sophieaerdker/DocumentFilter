#include "RecipeFilter.h"

RecipeFilter::RecipeFilter(std::string what, std::string content, std::string relation)

{
	//in what we search -> category (title, content, relation)
	// what we search -> content
	// how we search

m_what = toLowercase(what);
m_content = toLowercase(content);
m_relation = relation;
}

bool RecipeFilter::eval(Document &doc)
{
    bool returnValue;

    if (m_relation == "isin")
        returnValue = false;
    else if (m_relation == "isnot")
        returnValue = true;

    if (m_what == "title")
    {
      if( !(m_relation == "isin" || m_relation == "isnot" || m_relation == "is")){

        throw std::invalid_argument("No valid relation!");
      }

        std::string titleContent = toLowercase(doc.get_title());
        std::cout << titleContent;

        if (m_relation == "is")
            return (titleContent == m_content);

        if (titleContent.find(m_content) == std::string::npos)
            return returnValue;
        return !returnValue;
    }

    else if (m_what == "content")
    {
      if( !(m_relation == "isin" || m_relation == "isnot" || m_relation == "is")){

        throw std::invalid_argument("No valid relation!");
      }

        std::string content = toLowercase(doc.get_content());

        if (m_relation == "is")
            return (content == m_content);

        if (content.find(m_content) == std::string::npos)
            return returnValue;
        return !returnValue;
    }
    else if(m_what == "time"){

      std::string Numbers = "0123456789";
      std::string::iterator it;
      for (it = m_content.begin(); it != m_content.end(); ++it)
      {
        //search for other symbols in m_content
        if (Numbers.find(*it) > Numbers.length())
        {
          throw std::invalid_argument("No valid time!");
        }
      }
      int m_time = stoi(m_content);
      int time = doc.get_otherIntInformation();
      if(m_relation == "equal"){
        return (time == m_time);
      }
      else if(m_relation == "shorter"){
        return (time < m_time);
      }
      else if(m_relation == "longer"){
        return (time > m_time);
      }
      else{
        throw std::invalid_argument("No valid relation!");
      }
    }
    else if(m_what == "flag"){

      if( !(m_relation == "yes" || m_relation == "no")){

        throw std::invalid_argument("No valid relation!");
      }
      std::string content = doc.get_otherStringInformation();
      int co = stol(content, nullptr, 2);

      bool yes;
      if(m_relation == "yes"){
         yes = true;
      }else yes == false;
      //compare:
      if(m_content == "vegan"){
        return (co & 32 && yes);
      }else if(m_content == "vegetarisch"){
        return (co & 16 && yes);
      }
      else if(m_content == "suppe"){
        return (co & 8 && yes);
      }else if(m_content == "vorspeise"){
        return (co & 4 && yes);
      }
      else if(m_content == "hauptspeise"){
        return (co &2 && yes);
      }
      else if(m_content == "dessert")
      {
        return (co & 1 && yes);
      }
      else{
        throw std::invalid_argument("No valid flag!");
      }
    }else{
      throw std::invalid_argument("No valid key!");
    }
    }

    // duration
    // flags
