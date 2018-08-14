#ifndef __GRID_HPP__
#define __GRID_HPP__

namespace bsp
{
    class Grid
    {
    public:
      void display();
      void addShip(int fcordx, int fcordy, int ecordx, int ecordy);
      int alphConvert(char alph);
    };
  }

#endif
