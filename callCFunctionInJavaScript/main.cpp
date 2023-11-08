#include <emscripten/bind.h>

using namespace emscripten ;

float my_analysis(float a, float b, float c) 
{
    return( a + b ) * c ;
}

// Bind function names between HTML and C++ 
EMSCRIPTEN_BINDINGS(my_module) 
{
    emscripten::function("cFunction", &my_analysis) ;
}

