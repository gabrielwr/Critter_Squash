/*********************************************************************
 ** Author: Gabriel Rowe
 ** Date: 03/28/15
 ** Description: Critter.cpp
 *********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
private:
    int x_sz, y_sz;
    int curr_x, curr_y;//current location of critter
    int move_count;
public:
    Critter();
    Critter(int, int);
    bool new_position();
    void get_current(int*, int*);
};

#endif