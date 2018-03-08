#include "NoteFilter.h"

NoteFilter::NoteFilter(std::string what, std::string content, std::string relation)
     {m_what = toLowercase(what);
       m_content = toLowercase(content);
        m_relation = relation;
      }

bool NoteFilter::eval(Document &doc)
{
    bool returnValue;

    if( !(m_relation == "isin" || m_relation == "isnot" || m_relation == "is")){

      throw std::invalid_argument("No valid relation!");
    }

    if (m_relation == "isin")
        returnValue = false;
    else if (m_relation == "isnot")
        returnValue = true;

    if (m_what == "title")
    {

        std::string titleContent = toLowercase(doc.get_title());

        if (m_relation == "is")
            return (titleContent == m_content);

        if (titleContent.find(m_content) == std::string::npos)
            return returnValue;
        return !returnValue;
    }else if(m_what == "topic"){

    std::string topicContent = toLowercase(doc.get_otherStringInformation());

    if (m_relation == "is")
        return (topicContent == m_content);

    if (topicContent.find(m_content) == std::string::npos)
        return returnValue;
    return !returnValue;
}
    else if (m_what == "content")
    {
        std::string content = toLowercase(doc.get_content());

        if (m_relation == "is")
            return (content == m_content);

        if (content.find(m_content) == std::string::npos)
            return returnValue;
        return !returnValue;
    }
    else{
      throw std::invalid_argument("No valid key!");
    }
}
