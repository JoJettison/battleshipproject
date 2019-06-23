#include "grid.hpp"

namespace bsp
{

  //   std::string battlegrid[11][15] =
  // //  UN    1    2    3    4    5    6    7    8    9    10   11   12   13   14
  //  {{ "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //UN
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //A
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //B
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //C
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //D
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //E
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //F
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //G
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //H
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //I
  //   { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }  //J
  //  };

   //Grid numbers for horizontal axis
   const int horizgrid[15] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
   //Grid letters for vertical axis
   const std::string vertgrid[11] ={"","A","B","C","D","E","F","G","H","I","J"};
   //Define the grid size and intial values
   Grid::Grid(): battlegrid{
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //UN
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //A
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //B
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //C
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //D
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //E
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //F
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //G
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //H
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }, //I
     { "0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" ,"0" }}  //J
     {
     }




  /*
  Displays the status of a single grid
  @Param dispmode [int] used to indicate public or private view (0 = Private/Personal view, 1 = Public/Global view)
  */
  void Grid::display(int dispmode)
    {
      std::cout<<"*****************"<<"CURRENTGRID"<<"******************"<<std::endl;

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

      if(dispmode == 0)   //Personal Grid display
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
  @Params firstXCoord(int) firstYCoord(int)[The 1st coordinate of x & y] secondXCoord(int), secondYCoord(int)[The 2nd coordinate of x & y]
  USAGE: addShip(2,3,2,6) places ship from (2,3) to (2,6) horizontally
  //TODO Make easier to read, add error handling
  */
  void Grid::addShip(int firstXCoord, int firstYCoord, int secondXCoord, int secondYCoord)
  {
    if( firstXCoord == secondXCoord )
    {
      for(int i=firstYCoord; i<=secondYCoord; i++)
      {
        battlegrid[firstXCoord][i] ="1";
      }
    }
    else if( firstYCoord == secondYCoord )
    {
      for(int i=firstXCoord; i<=secondXCoord; i++)
      {
        battlegrid[i][firstYCoord] ="1";
      }
    }
    else
    {
      return;
    }
  }

  /*
  Fire a shot (repesented by X's atm) on the Grid
  @Params xcoord(int) [The X coordinate to shoot at], ycoord(int)[The Y coordinate to shoot at]
  USAGE: Fire(2,6) Fires at (2,6) and returns 1 if hit, 0 if missed
  */
  int Grid::fire(int xcoord, int ycoord){

    if(battlegrid[xcoord][ycoord] == "1" || battlegrid[xcoord][ycoord] == "X"){  // Check if space is occupied by a ship or the space is marked as hit
        battlegrid[xcoord][ycoord] = "X";   // Mark the space as hit
        return 1;
    }
    else if(battlegrid[xcoord][ycoord] == "0"){ // If not occupied
        battlegrid[xcoord][ycoord] = "!";  // Mark the space as missed
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
        case 'a':
          return 1;
        case 'b':
        case 'B':
          return 2;
        case 'c':
        case 'C':
          return 3;
        case 'd':
        case 'D':
          return 4;
        case 'e':
        case 'E':
          return 5;
        case 'f':
        case 'F':
          return 6;
        case 'g':
        case 'G':
          return 7;
        case 'h':
        case 'H':
          return 8;
        case 'i':
        case 'I':
          return 9;
        case 'j':
        case 'J':
          return 10;
        default:
          return 0;
      }
    }
/*
Checks if any ships are left on the grid, returns >0 if so
 */
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

 /*
 Fires a shot at every space on the grid,  instantly ending the game (Used for Surrender only)
  */
  void Grid::nuke() {
    for(int i=1; i<11; i++)
    {
      for(int j=1; j<15; j++)
      {
        battlegrid[i][j] = "X";
      }
    }
  }

  int Grid::loadGrid(std::string code) {
    //TODO Grid loading logic for auto config
  }


}
