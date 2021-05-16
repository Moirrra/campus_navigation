#ifndef PATH_H
#define PATH_H

#include <string>

using namespace std;

#define MAXINT 32767

class Path
{
public:
    int length;
    float congestion; //拥挤度<=1
    int ifBike; //允许自行车通行
    Path();
    Path(int len, float cong = 1, int t = 1);
    ~Path();
};

#endif // PATH_H
