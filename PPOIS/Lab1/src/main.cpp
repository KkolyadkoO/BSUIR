#include <iostream>
#include "../inc/cube.h"
#include <vector>
using namespace std;

int main()
{   int action;
    char choice;
    cout << "load cube(y/n)";
    cin >> choice;
    Cube cube(choice,"input.txt");
    do
    {
        cout << "1-rotate_the_top_edge_clockwise\n2-rotate_the_left_edge_clockwise\n3-rotate_the_front_edge_clockwise\n4-rotate_the_right_edge_clockwise\n5-rotate_the_back_edge_clockwise\n6-rotate_the_bottom_edge_clockwise\n7-rotate_the_top_edge_counter_clockwise\n8-rotate_the_left_edge_counter_clockwise\n9-rotate_the_front_edge_counter_clockwise\n10-rotate_the_right_edge_counter_clockwise\n11-rotate_the_back_edge_counter_clockwise\n12-rotate_the_bottom_edge_counter_clockwise\n0-exit";
        cube.print_cube();
        cin >> action;
        switch (action)
        {
        case 1:
            cube.rotate_the_top_edge_clockwise();
            break;
        case 2:
            cube.rotate_the_left_edge_clockwise();
            break;
        case 3:
            cube.rotate_the_front_edge_clockwise();
            break;
        case 4:
            cube.rotate_the_right_edge_clockwise();
            break;
        case 5:
            cube.rotate_the_back_edge_clockwise();
            break;
        case 6:
            cube.rotate_the_bottom_edge_clockwise();
            break;
        case 7:
            cube.rotate_the_top_edge_counter_clockwise();
            break;
        case 8:
            cube.rotate_the_left_edge_counter_clockwise();
            break;
        case 9:
            cube.rotate_the_front_edge_counter_clockwise();
            break;
        case 10:
            cube.rotate_the_right_edge_counter_clockwise();
            break;
        case 11:
            cube.rotate_the_back_edge_counter_clockwise();
            break;
        case 12:
            cube.rotate_the_bottom_edge_counter_clockwise();
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
        //system("clear");
    } while (!cube.win_check());
    cout << "WIN!!!!!!!!!";
    

    return 0;

}