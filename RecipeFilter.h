#pragma once

#include "Filter.h"
#include "Recipe.h"

class RecipeFilter : public Filter
{
    public:
        RecipeFilter(std::string what, std::string content, std::string relation);
        bool eval(Document &doc) override;

};
