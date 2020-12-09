#pragma once
#include "Object.h"
#include "Array.h"
#include "String.h"
#include "Bool.h"

namespace JSON {
    Object Load(const std::string& filename);
}