#include "Logger.h"
#include <cerrno>

using namespace wfrest;

int main()
{
//    LOGGER(DEBUG, "log.txt");

    LOG_TRACE << "trace ...";
    LOG_DEBUG << "debug ...";
    LOG_INFO << "info ...";
    LOG_WARN << "warn ...";
    LOG_ERROR << "error ...";
    //LOG_FATAL<<"fatal ...";
    errno = 13;
    LOG_SYSERR << "syserr ...";
    //LOG_SYSFATAL<<"sysfatal ...";

    return 0;
}