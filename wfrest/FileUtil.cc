#include <sys/stat.h>

#include "wfrest/FileUtil.h"
#include "wfrest/Logger.h"

using namespace wfrest;

int FileUtil::size(const std::string &path, OUT size_t *size)
{
    // https://linux.die.net/man/2/stat
    struct stat st;
    memset(&st, 0, sizeof st);
    int ret = stat(path.c_str(), &st);
    if(ret == -1)
    {
        *size = 0;
        LOG_SYSERR << "stat error ," << " path = " << path;
    } else 
    {
        *size = st.st_size;
    }
    return ret;
}

