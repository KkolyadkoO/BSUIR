#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h> 
#include <time.h> 
/**
 * @brief Класс кубик рубика
 * 
 */
class Cube
{
    private:
    /**
     * @brief Класс грань
     * 
     */
    class Edge
        {
            public:
            /**
             * @brief Вектор клеток на грани
             * 
             */
            std::vector<char> cells;
            /**
             * @brief Поворот стороны кубика по часавой стрелке
             * 
             */
            void rotate_edge();
            /**
             * @brief Замена соседних раней 
             * 
             * @param to_rotate три клетки с прошлой грани
             * @param cell_1 номер клетки 1
             * @param cell_2 номер клетки 2
             * @param cell_3 номер клетки 3
             * @return std::vector<char> вектор содержащий три клетки которые заменили
             */
            std::vector<char> rotation_of_adjacent_edge(std::vector<char> to_rotate, int cell_1,int cell_2, int cell_3);

        };
    /**
     * @brief Вектор в котором хранятся грани кубика
     * 
     */
    std::vector<Edge> cube;//0-y 1-r 2-b 3-o 4-g 5-w
    /**
     * @brief Запись кубика
     * 
     * @param str строка с комбинацией
     */
    void write_cube(std::string str);
    public:
    /**
     * @brief рандомит кубик
     * 
     * @details кубик получается 100% собираемым
     */
    void generation_cube();
    
    /**
     * @brief Конструктор кубика рубика
     * @details Необходим, если мы генерируем кубик
     */
    Cube(char choice,std::string filename);
    /**
     * @brief Конструктор кубика рубика
     * @details Необходим, если мы загружаем кубик
     * @param cube_inp комбинация кубика
     */
    Cube(std::string cube_inp);
    void load_cube(std::string filename);
    /**
     * @brief Выводит кубик
     * 
     */
    void print_cube();
    /**
     * @brief Поворот верхей грани по часовой
     * 
     */
    void rotate_the_top_edge_clockwise();
    /**
     * @brief Поворот левой грани по часовой
     * 
     */
    void rotate_the_left_edge_clockwise();
    /**
     * @brief Поворот передней грани по часавой
     * 
     */
    void rotate_the_front_edge_clockwise();
    /**
     * @brief Поворот правой грани по часавой
     * 
     */
    void rotate_the_right_edge_clockwise();
    /**
     * @brief Поворот задней грани по часавой
     * 
     */
    void rotate_the_back_edge_clockwise();
    /**
     * @brief Поворот нижней грани по часавой
     * 
     */
    void rotate_the_bottom_edge_clockwise();
    /**
     * @brief Оператор сравнения
     * 
     * @param c куб для сравнения
     * @return true 
     * @return false 
     */
    bool operator ==(const Cube &c);
    /**
     * @brief поворот верхней грани против часавой 
     * 
     */
    void rotate_the_top_edge_counter_clockwise();
    /**
     * @brief поворот левой грани против часавой 
     * 
     */
    void rotate_the_left_edge_counter_clockwise();
    /**
     * @brief поворот передней грани против часавой 
     * 
     */
    void rotate_the_front_edge_counter_clockwise();
    /**
     * @brief поворот правой грани против часавой 
     * 
     */
    void rotate_the_right_edge_counter_clockwise();
    /**
     * @brief поворот задней грани против часавой 
     * 
     */
    void rotate_the_back_edge_counter_clockwise();
    /**
     * @brief поворот нижней грани против часавой 
     * 
     */
    void rotate_the_bottom_edge_counter_clockwise();
    /**
     * @brief Проверка собран ли куб
     * 
     * @return true 
     * @return false 
     */
    bool win_check();

};