#pragma once

#include "Filter.h"
#include "Notes.h"

class NoteFilter : public Filter
{
    public:
        NoteFilter(std::string what, std::string content, std::string relation);
        bool eval(Document &doc) override;
};
