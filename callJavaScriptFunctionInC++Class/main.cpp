#include <iostream>
#include <string>

#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten ;

EM_JS(void, call_js, (
    const char *subject, int len_subject,
    const char *msg, int len_msg
), {
    jsFunction( 
        UTF8ToString(subject, len_subject),
        UTF8ToString(msg, len_msg)
    )
}) ;

class Test {
    public :
        void write() {
            call_js(getSubject().c_str(), getSubject().length(),
                    getMsg().c_str(), getMsg().length()) ;
        }

        std::string getSubject() { return subject ; }
        std::string getMsg()     { return msg ; }
        
    private : 
        std::string subject = "Hellow JS!" ;
        std::string msg = "I love JS!" ;
} ;

EMSCRIPTEN_BINDINGS(module)
{
    class_<Test>("Test")
        .constructor()
        .function("getSubject", &Test::getSubject) 
        .function("getMsg", &Test::getMsg) 
        .function("write", &Test::write) ;
}