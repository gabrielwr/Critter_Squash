#include<iostream>
#include <ctime>
//#include <stdio.h>
#include <iomanip>
#include "grid.hpp"

using std::cout;
using std::cin;
using std::endl;

Grid::Grid()
{
    field = NULL;
}

Grid::Grid(int x, int y)
{
    fill = '-';
    critter = 'C';
    x_sz = x;
    y_sz = y;
    curr_x = 0;
    curr_y = 0;
    field = new char *[x_sz];
    for (int i = 0; i < x_sz; i++)
        field[i] = new char[y_sz];

    for (int i=0; i < x_sz; i++)
    {
        for (int j=0; j < y_sz; j++)
        {
            field[i][j] = fill;
        }
    }
}

Grid::~Grid(){
    for (int i=0; i < x_sz; i++)
        delete [] field[i];
    delete [] field;
}

void Grid::printGrid()
{
    cout << "\n";
    for (int i=0; i < x_sz; i++)
    {
        for (int j=0; j < y_sz; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
}
void Grid::updateLocation(int x, int y)
{
    //save old position to reinitialize
    int old_x = curr_x;
    int old_y = curr_y;

    curr_x = x;
    curr_y = y;

    //redash old location on grid
    field[old_x][old_y] = fill;
    //draw new bug on new location
    field[x][y] = critter;

}
