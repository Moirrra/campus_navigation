#ifndef PATH_H
#define PATH_H

#include <string>

using namespace std;

#define MAXINT 32767
enum TOOL_TYPE
{
    foot,
    bike,
    bus
};

class Path
{
public:
    int length;
    float congestion;//拥挤度<=1
    TOOL_TYPE tool;
    Path();
    Path(int len, float cong, TOOL_TYPE t);
    ~Path();
};

#endif // PATH_H
