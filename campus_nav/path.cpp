#include "path.h"

Path::Path()
{
    length = MAXINT;
    congestion = 1;
    ifBike = 1;
}

Path::Path(int len, float cong, int t)
{
    length = len;
    congestion = cong;
    ifBike = t;
}

Path::~Path()
{}
