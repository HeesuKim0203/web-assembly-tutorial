#include <iostream>
#include <string>

using namespace std ;

class Multiple
{
    public :
        void setNum(int argNum) {
            num = argNum ;
        }

        void displayResult() {
            for( int i = 0 ; i < 9 ; i++ ) {
                printf("%d * %d = %d\n", num, i + 1, num * (i + 1)) ;
            }
        }

    private :
        int num ;
} ;

int main()
{
    Multiple multiple ;

    multiple.setNum(7) ;
    multiple.displayResult() ;

    return 1 ;
}