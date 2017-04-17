#ifndef TILEUTILS_H
#define TILEUTILS_H

struct bbox {
    double minX;
    double minY;
    double maxX;
    double maxY;
};

double tile2lon(int x, int z);
double tile2lat(int y, int z);
bbox makeBBox(int x, int y, int z);

#endif // TILEUTILS_H
