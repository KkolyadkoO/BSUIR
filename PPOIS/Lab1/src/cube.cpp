#include "../inc/cube.h"

Cube::Cube(char choice,std::string filename)
{
}
void Cube::load_cube(std::string filename)
{
    std::string buff;
        std::ifstream input(filename);
        if (!input.is_open()) 
            std::cout << "Файл не может быть открыт!\n"; 
        else
        {
            input >> buff; // считали расстановку кубика из файла
            input.close(); // закрываем файл
        }
        
        write_cube(buff);

}
Cube::Cube(std::string cube_inp)
{
    write_cube(cube_inp);
}
void Cube::generation_cube()
{
    write_cube("yyyyyyyyyrrrrrrrrrbbbbbbbbbooooooooogggggggggwwwwwwwww");
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        switch (1 + rand() % 6)
        {
        case 1:
            rotate_the_back_edge_clockwise();
            break;
        case 2:
            rotate_the_top_edge_clockwise();
            break;
        case 3:
            rotate_the_front_edge_clockwise();
            break;
        case 4:
            rotate_the_bottom_edge_clockwise();
            break;
        case 5:
            rotate_the_left_edge_clockwise();
            break;
        case 6:
            rotate_the_right_edge_clockwise();
            break;    
        }
    }
}
void Cube::write_cube(std::string str)
{
    Edge buff_edge;
    int s=0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            buff_edge.cells.push_back(str[s]);
            s++;
        }
        cube.push_back(buff_edge);
        buff_edge.cells.clear();
    }
}
bool Cube::operator ==(const Cube &c)
{
    bool buff=true;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(cube[i].cells[j]!=c.cube[i].cells[j])
            buff=false;
        }
        
    }
    return buff;
}


void Cube::print_cube()
{
    std::cout << "                      top edge           " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "                   | "<< cube[0].cells[0] <<" | "<< cube[0].cells[1] <<" | "<< cube[0].cells[2] <<" |          " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "                   | "<< cube[0].cells[3] <<" | "<< cube[0].cells[4] <<" | "<< cube[0].cells[5] <<" |          " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "                   | "<< cube[0].cells[6] <<" | "<< cube[0].cells[7] <<" | "<< cube[0].cells[8] <<" |          " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "        left edge    front edge   right edge   back edge  " << std::endl;
    std::cout << "      ----------------------------------------------------" << std::endl;
    std::cout << "      | "<< cube[1].cells[0] <<" | "<< cube[1].cells[1] <<" | "<< cube[1].cells[2] <<" || "<< cube[2].cells[0] <<" | "<< cube[2].cells[1] <<" | "<< cube[2].cells[2] <<" || "<< cube[3].cells[0] <<" | "<< cube[3].cells[1] <<" | "<< cube[3].cells[2] <<" || "<< cube[4].cells[0] <<" | "<< cube[4].cells[1] <<" | "<< cube[4].cells[2] <<" |" << std::endl;
    std::cout << "      ----------------------------------------------------" << std::endl;
    std::cout << "      | "<< cube[1].cells[3] <<" | "<< cube[1].cells[4] <<" | "<< cube[1].cells[5] <<" || "<< cube[2].cells[3] <<" | "<< cube[2].cells[4] <<" | "<< cube[2].cells[5] <<" || "<< cube[3].cells[3] <<" | "<< cube[3].cells[4] <<" | "<< cube[3].cells[5] <<" || "<< cube[4].cells[3] <<" | "<< cube[4].cells[4] <<" | "<< cube[4].cells[5] <<" |" << std::endl;
    std::cout << "      ----------------------------------------------------" << std::endl;
    std::cout << "      | "<< cube[1].cells[6] <<" | "<< cube[1].cells[7] <<" | "<< cube[1].cells[8] <<" || "<< cube[2].cells[6] <<" | "<< cube[2].cells[7] <<" | "<< cube[2].cells[8] <<" || "<< cube[3].cells[6] <<" | "<< cube[3].cells[7] <<" | "<< cube[3].cells[8] <<" || "<< cube[4].cells[6] <<" | "<< cube[4].cells[7] <<" | "<< cube[4].cells[8] <<" |" << std::endl;
    std::cout << "      ----------------------------------------------------" << std::endl;
    std::cout << "                    bottom edge           " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "                   | "<< cube[5].cells[0] <<" | "<< cube[5].cells[1] <<" | "<< cube[5].cells[2] <<" |          " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "                   | "<< cube[5].cells[3] <<" | "<< cube[5].cells[4] <<" | "<< cube[5].cells[5] <<" |          " << std::endl;
    std::cout << "                   -------------          " << std::endl;
    std::cout << "                   | "<< cube[5].cells[6] <<" | "<< cube[5].cells[7] <<" | "<< cube[5].cells[8] <<" |          " << std::endl;
    std::cout << "                   -------------          " << std::endl;  
}
void Cube::Edge::rotate_edge()
{
    std::swap(cells[0],cells[2]);
    std::swap(cells[0],cells[8]);
    std::swap(cells[0],cells[6]);
    std::swap(cells[1],cells[5]);
    std::swap(cells[1],cells[7]);
    std::swap(cells[1],cells[3]);
}
std::vector<char> Cube::Edge::rotation_of_adjacent_edge(std::vector<char> to_rotate, int cell_1,int cell_2, int cell_3)
{
    std::vector<char> buf;
    buf.push_back(cells[cell_1]);
    buf.push_back(cells[cell_2]);
    buf.push_back(cells[cell_3]);
    cells[cell_1]=to_rotate[0];
    cells[cell_2]=to_rotate[1];
    cells[cell_3]=to_rotate[2];
    return buf;
}
bool Cube::win_check()
{
    bool win=true;
    for(int i=0; i<6; i++)
    {
        for(int j=1; j<9; j++)
        {
            if(cube[i].cells[j]!=cube[i].cells[j-1])
            win=false;
        }
    }
    return win;
}
void Cube::rotate_the_top_edge_clockwise()
{
    cube[0].rotate_edge();
    std::vector<char> buf;
    buf.push_back(cube[1].cells[0]);
    buf.push_back(cube[1].cells[1]);
    buf.push_back(cube[1].cells[2]);
    buf = cube[4].rotation_of_adjacent_edge(buf,0,1,2);
    buf = cube[3].rotation_of_adjacent_edge(buf,0,1,2);
    buf = cube[2].rotation_of_adjacent_edge(buf,0,1,2);
    buf = cube[1].rotation_of_adjacent_edge(buf,0,1,2);
}
void Cube::rotate_the_left_edge_clockwise()
{
    cube[1].rotate_edge();
    std::vector<char> buf;
    buf.push_back(cube[2].cells[0]);
    buf.push_back(cube[2].cells[3]);
    buf.push_back(cube[2].cells[6]);
    buf = cube[5].rotation_of_adjacent_edge(buf,0,3,6);
    buf = cube[4].rotation_of_adjacent_edge(buf,8,5,2);
    buf = cube[0].rotation_of_adjacent_edge(buf,0,3,6);
    buf = cube[2].rotation_of_adjacent_edge(buf,0,3,6);
}
void Cube::rotate_the_front_edge_clockwise()
{
    cube[2].rotate_edge();
    std::vector<char> buf;
    buf.push_back(cube[0].cells[6]);
    buf.push_back(cube[0].cells[7]);
    buf.push_back(cube[0].cells[8]);
    buf = cube[3].rotation_of_adjacent_edge(buf,0,3,6);
    buf = cube[5].rotation_of_adjacent_edge(buf,0,1,2);
    buf = cube[1].rotation_of_adjacent_edge(buf,2,5,8);
    buf = cube[0].rotation_of_adjacent_edge(buf,6,7,8);
}
void Cube::rotate_the_right_edge_clockwise()
{
    cube[3].rotate_edge();
    std::vector<char> buf;
    buf.push_back(cube[0].cells[2]);
    buf.push_back(cube[0].cells[5]);
    buf.push_back(cube[0].cells[8]);
    buf = cube[4].rotation_of_adjacent_edge(buf,6,3,0);
    buf = cube[5].rotation_of_adjacent_edge(buf,2,5,8);
    buf = cube[2].rotation_of_adjacent_edge(buf,2,5,8);
    buf = cube[0].rotation_of_adjacent_edge(buf,2,5,8);
}
void Cube::rotate_the_back_edge_clockwise()
{
    cube[4].rotate_edge();
    std::vector<char> buf;
    buf.push_back(cube[0].cells[0]);
    buf.push_back(cube[0].cells[1]);
    buf.push_back(cube[0].cells[2]);
    buf = cube[1].rotation_of_adjacent_edge(buf,0,3,6);
    buf = cube[5].rotation_of_adjacent_edge(buf,6,7,8);
    buf = cube[3].rotation_of_adjacent_edge(buf,2,5,8);
    buf = cube[0].rotation_of_adjacent_edge(buf,0,1,2);
}
void Cube::rotate_the_bottom_edge_clockwise()
{
    cube[5].rotate_edge();
    std::vector<char> buf;
    buf.push_back(cube[4].cells[6]);
    buf.push_back(cube[4].cells[7]);
    buf.push_back(cube[4].cells[8]);
    buf = cube[1].rotation_of_adjacent_edge(buf,6, 7, 8);
    buf = cube[2].rotation_of_adjacent_edge(buf,6, 7, 8);
    buf = cube[3].rotation_of_adjacent_edge(buf,6, 7, 8);
    buf = cube[4].rotation_of_adjacent_edge(buf,6, 7, 8);
}

void Cube::rotate_the_back_edge_counter_clockwise()
{
    rotate_the_back_edge_clockwise();
    rotate_the_back_edge_clockwise();
    rotate_the_back_edge_clockwise();
}
void Cube::rotate_the_bottom_edge_counter_clockwise()
{
    rotate_the_bottom_edge_clockwise();
    rotate_the_bottom_edge_clockwise();
    rotate_the_bottom_edge_clockwise();
}
void Cube::rotate_the_front_edge_counter_clockwise()
{
    rotate_the_front_edge_clockwise();
    rotate_the_front_edge_clockwise();
    rotate_the_front_edge_clockwise();
}
void Cube::rotate_the_left_edge_counter_clockwise()
{
    rotate_the_left_edge_clockwise();
    rotate_the_left_edge_clockwise();
    rotate_the_left_edge_clockwise();
}
void Cube::rotate_the_right_edge_counter_clockwise()
{
    rotate_the_right_edge_clockwise();
    rotate_the_right_edge_clockwise();
    rotate_the_right_edge_clockwise();
}
void Cube::rotate_the_top_edge_counter_clockwise()
{
    rotate_the_top_edge_clockwise();
    rotate_the_top_edge_clockwise();
    rotate_the_top_edge_clockwise();
}