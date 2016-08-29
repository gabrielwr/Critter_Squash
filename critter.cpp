#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "critter.hpp"

using std::cout;
using std::cin;
using std::endl;

Critter::Critter(int x, int y)
{
    x_sz = x;
    y_sz = y;
    move_count = 1;
    //initalize a position
    srand(time(0));
    curr_x = rand() % x_sz;
    curr_y = rand() % y_sz;
}
bool Critter::new_position()
{
    //get new coords
    bool squashed = false;
    int move = rand() % 4 + 1;
    if(move == 1)
    {   //move up
        cout << "Moving up...\n";
        curr_x -= 1;
        if (curr_x < 0)
            squashed = true;
    }
    else if(move == 2)
    {   //move down
        cout << "Moving down...\n";
        curr_x += 1;
        if (curr_x >= x_sz)
            squashed = true;
    }
    else if(move == 3)
    {   //move "left"
        cout << "Moving left...\n";
        curr_y -= 1;
        if (curr_y < 0)
            squashed = true;
    }
    else if(move == 4)
    {   //move "right"
        cout << "Moving right...\n";
        curr_y += 1;
        if (curr_y >= y_sz)
            squashed = true;
    }
    if(squashed)
    {
        cout << "\nCritter is Squashed!!!\n";
        cout << "That took " << move_count << " move(s)!!\n\n";
    }
    else
        move_count++;
    return squashed;
}

void Critter::get_current(int *x, int *y)
{
    *x = curr_x;
    *y = curr_y;
}