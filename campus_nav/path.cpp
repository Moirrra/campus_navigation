#include "path.h"

/*
 * @brief Path::Path
 * @author ts
 */
Path::Path()
{
    length = MAXINT;
    congestion = 1;
    ifBike = 1;
}

/*
 * @brief Path::Path
 * @param len 路径长度
 * @param cong 拥挤度
 * @param t 自行车能否通行
 * @author ts
 */
Path::Path(int len, float cong, int t)
{
    length = len;
    congestion = cong;
    ifBike = t;
}

Path::~Path()
{}
