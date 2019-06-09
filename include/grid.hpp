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
      void display(int mode);
      void addShip(int fcordx, int fcordy, int ecordx, int ecordy);
      int fire(int xcord, int ycord);
      int alphConvert(char alph);
      int gameactive();
      void nuke();
    private:
        std::string battlegrid[11][15];
    };
}

#endif
