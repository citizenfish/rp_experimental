#include "tileutils.h"
#include <math.h>

double tile2lon(int x, int z){

    return (x / pow(2.0, z) * 360.0) - 180;
}

double tile2lat(int y, int z){

    double n = M_PI - (2.0 * M_PI * y) / pow(2.0, z);
    return 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));

}

bbox makeBBox(int x, int y, int z) {

    bbox retBbox;

    retBbox.minX = tile2lon(x,z);
    retBbox.minY = tile2lat(y,z);
    retBbox.maxX = tile2lon(x + 1,z);
    retBbox.maxY = tile2lat(y + 1, z);

    return retBbox;
}

