#include "grid.hpp"
#include <iostream>

namespace bsp
{
    //Define the grid size and intial values
    std::string battlegrid[11][15] =
  //  UN    1    2    3    4    5    6    7    8    9    10   11   12   13   14
   {{ "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //UN
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //A
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //B
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //C
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //D
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //E
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //F
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //G
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //H
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //I
    { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }  //J
   };

   //Grid numbers for horizontal axis
   int horizgrid[15] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
   //Grid letters for vertical axis
   std::string vertgrid[11] ={"","A","B","C","D","E","F","G","H","I","J"};


  /*
  Displays the status of a single grid
  */
  void Grid::display(int mode)
    {
      std::cout<<"   ************"<<"CURRENTGRID"<<"***************"<<std::endl;

      for(int e=1; e<15; e++)
      {
        if(e==1)
        {
          std::cout<<"   "<<horizgrid[e];
        }
        else if(e>=10)
        {
          std::cout<<" "<<horizgrid[e];
        }
        else
        {
          std::cout<<"  "<<horizgrid[e];
        }
      }
      std::cout<<std::endl;

      if(mode == 0)   //Personal Grid display
      {
        for(int i=1; i<11; i++)
        {
          std::cout<<vertgrid[i];
          for(int j=1; j<15; j++)
          {
            std::cout<<"  "<<battlegrid[i][j];
          }
          std::cout<<"  "<<vertgrid[i]<<std::endl;
        }
      }
      else
      {           //Public Grid display
        for(int i=1; i<11; i++)
        {
          std::cout<<vertgrid[i];
          for(int j=1; j<15; j++)
          {
            if(battlegrid[i][j] == "1"){
                std::cout<<"  "<<"0";
            }
            else{
              std::cout<<"  "<<battlegrid[i][j];
            }
          }
          std::cout<<"  "<<vertgrid[i]<<std::endl;
        }
      }
      for(int f=1; f<15; f++)
      {
        if(f==1)
        {
          std::cout<<"   "<<horizgrid[f];
        }
        else if(f>=10)
        {
          std::cout<<" "<<horizgrid[f];
        }
        else
        {
          std::cout<<"  "<<horizgrid[f];
        }
      }
      std::cout<<std::endl;
    }

  /*
  Add a ship (repesented by 1's atm) to the Grid
  @Params fcordx(int) fcordy(int)[The 1st coordinate of x & y] ecordx(int), ecordy(int)[The 2nd coordinate of x & y]
  USAGE: addShip(2,3,2,6) places ship from (2,3) to (2,6) horizontally
  //TODO Make easier to read, add error handling
  */
  void Grid::addShip(int fcordx, int fcordy, int ecordx, int ecordy)
  {
    if( fcordx == ecordx )
    {
      for(int i=fcordy; i<=ecordy; i++)
      {
        battlegrid[fcordx][i] ="1";
      }
    }
    else if( fcordy == ecordy )
    {
      for(int i=fcordx; i<=ecordx; i++)
      {
        battlegrid[i][fcordy] ="1";
      }
    }
    else
    {
      return;
    }
  }


  int Grid::fire(int xcord, int ycord){

    if(battlegrid[xcord][ycord] == "1" || battlegrid[xcord][ycord] == "X"){  // Check if space is occupied by a ship or the space is marked as hit
        battlegrid[xcord][ycord] = "X";   // Mark the space as hit
        return 1;
    }
    else if(battlegrid[xcord][ycord] == "0"){ // If not occupied
        battlegrid[xcord][ycord] = "!";  // Mark the space as missed
        return 0;
    }
    else{
       return -1;
    }
  }
    /*
    Converts an alphabetic character to its numeric equivalent
    @Params alph(char)
    @Return int representing the character
    //TODO Maybe just use an enum?
    */
    int Grid::alphConvert(char alph)
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

    int Grid::gameactive(){
      int count = 0;
      for(int i=1; i<11; i++)
      {
        for(int j=1; j<15; j++)
        {
          if(battlegrid[i][j] == "1")
          {
          count++;
          }
        }
    }
    return count;
 }
  void Grid::nuke() {
    for(int i=1; i<11; i++)
    {
      for(int j=1; j<15; j++)
      {
        battlegrid[i][j] == "X";
      }
    }
  }


}
