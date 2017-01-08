#include "logger.h"

int main()
{
    LOGSETFILENAME("c:/temp/logger.log")
    LOGLINE << "Hello world 1 " << 3 + 2;
    LOGLINE << "Hello world 2" << 3 + 2;
    return 0;
}