#include "path.h"

Path::Path()
{
    length = MAXINT;
    congestion = 1;
    tool = foot;
}

Path::Path(int len, float cong, TOOL_TYPE t)
{
    length = len;
    congestion = cong;
    tool = t;
}
