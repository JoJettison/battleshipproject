#include "grid.hpp"
#include <iostream>

int main()
{
  bsp::Grid agrid;

  agrid.display();
  agrid.addShip(2,2,2,5);
  agrid.display();
  agrid.addShip(agrid.alphConvert('B'),7, agrid.alphConvert('F'),7);
  agrid.display();
  agrid.fire(agrid.alphConvert('E'),7);
  agrid.fire(agrid.alphConvert('B'),7);
  agrid.fire(agrid.alphConvert('C'),7);
  agrid.fire(agrid.alphConvert('D'),7);
  agrid.fire(agrid.alphConvert('F'),7);
  agrid.fire(agrid.alphConvert('A'),7);
  agrid.fire(2,5);

  agrid.display();

  return 0;
}
