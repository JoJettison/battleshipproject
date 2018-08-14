#include "grid.hpp"
#include <iostream>

namespace bsp
{

    int battlegrid[11][15] =
  // UN  1  2  3  4  5  6  7  8  9  10 11 12 13 14
   {{ 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //UN
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //A
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //B
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //C
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //D
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //E
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //F
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //G
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //H
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 }, //I
    { 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 } //J
   };

  void display()
    {
      std::cout<<"************"<<"CURRENTGRID"<<"***************"<<std::endl;
      for(int i=1; i<12; i++)
      {
        for(int j=1; j<16; j++)
        {
          std::cout<<battlegrid[i][j]<<std::endl;
        }
      }
    }

  void addShip(int fcordx, int fcordy, int ecordx, int ecordy)
  {
    if( fcordx == ecordx )
    {
      for(int i=fcordy; i<=ecordy; i++)
      {
        battlegrid[fcordx][i] =1;
      }
    }
    else if( fcordy == ecordy )
    {
      for(int i=fcordx; i<=ecordx; i++)
      {
        battlegrid[i][fcordy] =1;
      }
    }
    else
    {
      return;
    }
  }

    int alphConvert(char alph)
    {
      switch(alph)
      {
        case 'A':
          return 1;
        case 'B':
          return 2;
        case 'C':
          return 3;
        case 'D':
          return 4;
        case 'E':
          return 5;
        case 'F':
          return 6;
        case 'G':
          return 7;
        case 'H':
          return 8;
        case 'I':
          return 9;
        case 'J':
          return 10;
        default:
          return 0;
      }
    }

 }
