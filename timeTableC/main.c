#include <stdio.h>

void multiple(int num)
{
    for( int i = 0 ; i < 9 ; i++ ) {
        printf("%d * %d = %d\n", num, i + 1, num * (i + 1)) ;
    }
}

int main(int argc, char **argv)
{
    multiple(2) ;
	return 1 ;
}
