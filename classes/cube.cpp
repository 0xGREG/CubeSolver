#include "cube.h"

cube::cube(int _size){
    size = _size;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            tiles[i][j] = 0;
        }
    }
}