#ifndef __GRID_HPP__
#define __GRID_HPP__

#include "val.hpp"
#include <iostream>
#include <thread>
#include <chrono>
namespace bsp
{
    class Grid
    {
    public:
      Grid();
      void display(int dispmode);
      void addShip(int firstXCoord, int firstYCoord, int secondXCoord, int secondYCoord);
      int fire(int xcoord, int ycoord);
      int alphConvert(char alph);
      int gameactive();
      void nuke();
      int loadGrid(std::string code);
    private:
        std::string battlegrid[11][15];
    };
}

#endif
