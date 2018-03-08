#pragma once

#include "Document.h"
#include <string>
#include <algorithm>
#include <cctype>

class Filter
{
    public:
        virtual bool eval(Document &doc) = 0;
        friend std::string toLowercase(std::string input);

    protected:
        std::string m_what;
        std::string m_content;
        std::string m_relation;
};


inline std::string toLowercase(std::string input)
{
    std::string result = input;
    std::transform(input.begin(), input.end(), result.begin(), ::tolower);
    return result;
}
