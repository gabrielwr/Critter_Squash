/*********************************************************************
 ** Author: Gabriel Rowe
 ** Date: 03/28/15
 ** Description: Mod A Main
 *********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "grid.hpp"
#include "critter.hpp"

using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int x;
    int y;
    int curr_bug_x = 0;
    int curr_bug_y = 0;
    srand(time(0));// seed in main
    
    cout<< "Please enter the number of rows you would like in the grid" << endl;
    cin >> x;
    
    cout<< "Please enter the number of columns you would like in the grid" << endl;
    cin >> y;
    
    //validation
    while (x <=  0 || y <= 0)
    {
        cout<< "Please make sure the x and y coordinates are greater than 0"<< endl;
        
        cout<< "Please enter the number of rows you would like in the grid" << endl;
        cin >> x;
        
        cout<< "Please enter the number of columns you would like in the grid" << endl;
        cin >> y;
    }
    
    //instantiate objects
    Grid g(x, y);
    Critter bug(x, y);//constructor sets first position
    
    bug.get_current(&curr_bug_x, &curr_bug_y);//get first position
    g.updateLocation(curr_bug_x, curr_bug_y); //load first postition
    g.printGrid(); //print initial grid

    while(!bug.new_position())
    {
        bug.get_current(&curr_bug_x, &curr_bug_y);
        x = curr_bug_x;
        y = curr_bug_y;
        g.updateLocation(curr_bug_x, curr_bug_y);
        g.printGrid();
        cout << endl;
    }
    return 0;
}