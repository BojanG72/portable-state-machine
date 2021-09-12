#include "common.h"

//////////////////////////////////////////////////
/// COMMON FUNCTIONS
//////////////////////////////////////////////////
void printTime( void )
{  
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%02d:%02d:%02d  ", tm.tm_hour, tm.tm_min, tm.tm_sec);
}