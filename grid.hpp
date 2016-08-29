/*********************************************************************
 ** Author: Gabriel Rowe
 ** Date: 03/28/15
 ** Description: Grid.hpp
 *********************************************************************/

#ifndef GRID_HPP
#define GRID_HPP

class Critter;

class Grid
{
private:
    char critter;
    char fill;
    char **field;
    int x_sz, y_sz;//original sizes for grid
    int curr_x, curr_y;//current position
public:
    Grid();
    Grid(int,int);
    ~Grid();
    void updateLocation(int, int);
    void printGrid();
};

#endif