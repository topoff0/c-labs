#pragma once

#include "Config.h"

struct StringEquals
{
    std::string target;

    StringEquals(const std::string &s) : target(s) {}

    bool operator()(const std::string &s) const
    {
        return s == target;
    }
};
