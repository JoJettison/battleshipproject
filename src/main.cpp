#include "grid.hpp"

void typedPrint(std::string msg){

  for(int i =0; i< msg.length(); i++){
    std::cout<<msg[i]<<std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  std::cout <<'\n';

}


int main()
{
  bool gameRun = true, ply1 = true, ply2 = true;
  bool movemade = false;
  int playsel =1, modesel =1;
  std::string configsel ="C";
  std::string movesel = " ";
  std::string configcode= "A3";
  std::string Coord1= "", Coord2= "", tarCord= "";
  bsp::Grid P1grid;
  bsp::Grid P2grid;

  //std::cout << (gameRun ? "This is true": "this is false") << '\n';

   while (gameRun) {
     typedPrint("Remote terminal activated, input number of players");
     std::cin >> playsel;
     if(playsel == 1){  //1 Player game
       std::cin.sync();
       typedPrint("Single player is currently unsupported. System will terminate before game start");
       std::cout <<'\n';
       std::cout << "1 Player mission selected." << '\n';
       typedPrint("Satellite link established, input game option");
       std::cout <<'\n';
       typedPrint("1: Classic Mission");
       typedPrint("2: Bonus Mission");
       typedPrint("3: Salvo Mission");
       typedPrint("4: Advanced Mission");
       std::cout <<'\n';
       switch (modesel) { // Game type selection
         case 1: typedPrint("Classic Mission Selected."); break;
         case 2: typedPrint("Bonus Mission Selected."); break;
         case 3: typedPrint("Salvo Mission Selected."); break;
         case 4: typedPrint("Advanced Mission Selected."); break;
       }
      typedPrint("Player 1, enter fleet configuration. A/C? ");
       std::cin >> configsel;
        if (configsel =="A" || configsel == "a") {
          typedPrint("Auto Configuration Selected. Enter configuration code.");
          std::cin >> configcode;
          //TODO Logic for loading specifed grid
        }
        else if(configsel == "C" || configsel == "c"){
          typedPrint("Custom Configuration Selected");
          std::cout << '\n';
          for(int i =0; i <5; i++){
            P1grid.display(0);   //Display of the current grid
              switch (i) {    //Message showing which ship is being entered
                case 0 : typedPrint("Aircraft Carrier Reporting! [5 Spaces] Enter Coordinates: "); break;
                case 1 : typedPrint("Battleship Reporting! [4 Spaces] Enter Coordinates: "); break;
                case 2 : typedPrint("Destroyer Reporting! [3 Spaces] Enter Coordinates: "); break;
                case 3 : typedPrint("Submarine Reporting! [3 Spaces] Enter Coordinates: "); break;
                case 4 : typedPrint("Patrol Boat Reporting! [2 Spaces] Enter Coordinates: "); break;
              }

          std::cin >>Coord1 >> Coord2;
          char Crd1x =  Coord1[0];
          std::string Crd1y =  Coord1.substr(1);
          char Crd2x =  Coord2[0];
          std::string Crd2y =  Coord2.substr(1);
          std::cout<< '\n';
          P1grid.addShip(P1grid.alphConvert(Crd1x), atoi(Crd1y.c_str()), P1grid.alphConvert(Crd2x), atoi(Crd2y.c_str()));
        }
       }
       else{
         std::cout << configsel;
         std::cerr << "INVALID INPUT" << '\n';
       }
       typedPrint("General quarters! General quarters! man your battlestations! This is NOT a drill! ");
       typedPrint("REPEAT: This is NOT a drill");
       P1grid.display(0);
       //GAME START
       //TODO Single player AI... Will take a bit
       bsp::Grid CPGrid;

       std::cout << "Single player is currently unsupported, check back later" << '\n';
       gameRun = false;
       break;

     }
     else if (playsel == 2 ){
       std::cin.sync();
       typedPrint("2 Player mission selected.");
       typedPrint("Satellite link established, input game option");
       typedPrint("1: Classic Mission");
       typedPrint("2: Bonus Mission");
       typedPrint("3: Salvo Mission");
       typedPrint("4: Advanced Mission");
       switch (modesel) { // Game type selection
         case 1: typedPrint("Classic Mission Selected."); break;
         case 2: typedPrint("Bonus Mission Selected."); break;
         case 3: typedPrint("Salvo Mission Selected."); break;
         case 4: typedPrint("Advanced Mission Selected."); break;
       }
       typedPrint("Player 1, enter fleet configuration. A/C? ");
       std::cin >> configsel;
        if (configsel =="A" || configsel == "a") {
          typedPrint("Auto Configuration Selected. Enter configuration code.");
          std::cin >> configcode;
          //TODO Logic for loading specifed grid
        }
        else if(configsel == "C" || configsel =="c" ){
          std::cout << "  Custom Configuration Selected" << '\n' << '\n';
          for(int i =0; i <5; i++){
            P1grid.display(0);   //Display of the current grid
              switch (i) {    //Message showing which ship is being entered
                case 0 : typedPrint("Aircraft Carrier Reporting! [5 Spaces] Enter Coordinates: "); break;
                case 1 : typedPrint("Battleship Reporting! [4 Spaces] Enter Coordinates: "); break;
                case 2 : typedPrint("Destroyer Reporting! [3 Spaces] Enter Coordinates: "); break;
                case 3 : typedPrint("Submarine Reporting! [3 Spaces] Enter Coordinates: "); break;
                case 4 : typedPrint("Patrol Boat Reporting! [2 Spaces] Enter Coordinates: "); break;
              }

          std::cin >>Coord1 >> Coord2;
          char Crd1x =  Coord1[0];
          std::string Crd1y =  Coord1.substr(1);
          char Crd2x =  Coord2[0];
          std::string Crd2y =  Coord2.substr(1);
          std::cout<< '\n';
          P1grid.addShip(P1grid.alphConvert(Crd1x), atoi(Crd1y.c_str()), P1grid.alphConvert(Crd2x), atoi(Crd2y.c_str()));
        }
       }
       else{
         std::cout << configsel;
         std::cerr << "INVALID INPUT" << '\n';
     }

     typedPrint("Player 2, enter fleet configuration. A/C? ");
     std::cin >> configsel;
      if (configsel =="A") {
        typedPrint("Auto Configuration Selected. Enter configuration code.");
        std::cin >> configcode;
        //TODO Logic for loading specifed grid
      }
      else if(configsel == "C" || configsel == "c"){
        std::cout << "  Custom Configuration Selected" << '\n' << '\n';
        for(int i =0; i <5; i++){
          P2grid.display(0);   //Display of the current grid
            switch (i) {    //Message showing which ship is being entered
              case 0 : typedPrint("Aircraft Carrier Reporting! [5 Spaces] Enter Coordinates: "); break;
              case 1 : typedPrint("Battleship Reporting! [4 Spaces] Enter Coordinates: "); break;
              case 2 : typedPrint("Destroyer Reporting! [3 Spaces] Enter Coordinates: "); break;
              case 3 : typedPrint("Submarine Reporting! [3 Spaces] Enter Coordinates: "); break;
              case 4 : typedPrint("Patrol Boat Reporting! [2 Spaces] Enter Coordinates: "); break;
            }

        std::cin >>Coord1 >> Coord2;
        char Crd1x =  Coord1[0];
        std::string Crd1y =  Coord1.substr(1);
        char Crd2x =  Coord2[0];
        std::string Crd2y =  Coord2.substr(1);
        std::cout<< '\n';
        P2grid.addShip(P2grid.alphConvert(Crd1x), atoi(Crd1y.c_str()), P2grid.alphConvert(Crd2x), atoi(Crd2y.c_str()));
        }
      }
    }
    /***********************************************************
     * ------------G A M E S T A R T-------------------------
     ***********************************************************/

     //Playloop
     do {
       if (ply1) {
         while (!movemade) {
         std::cout << "Awaiting orders from Player 1" << '\n';
         std::cout << "F: Fire\n" <<"R: Repeat\n" <<"D: Display Ship Status\n"<<"Q: Surrender\n" << '\n';
         std::cin >> movesel;
              if (movesel == "F" || movesel== "f") {
                  std::cout << "Enter Coordinates: ";
                  std::cin >> tarCord;
                  char trcX = tarCord[0];
                  std::string trcY = tarCord.substr(1);
                  P2grid.fire(P2grid.alphConvert(trcX), atoi(trcY.c_str()));
                  std::cout << "\n\n";
                  P2grid.display(1);
                  movemade =true;
              } else if(movesel == "D" || movesel == "d") {
                  P1grid.display(0);
              } else if (movesel == "Q" || movesel == "q") {
                P1grid.nuke();
                movemade = true;
              } else{
                std::cout << "INVALID INPUT" << '\n';
              }
         }
         movemade = false;
         ply1= false;
         ply2= true;
       }
       else if(ply2){ //ply2
         while (!movemade) {
         std::cout << "Awaiting orders from Player 2" << '\n';
         std::cout << "F: Fire\n" <<"R: Repeat\n" <<"D: Display Ship Status\n"<<"Q: Surrender\n" << '\n';
         std::cin >> movesel;
          if (movesel == "F" || movesel== "f") {
              std::cout << "Enter Coordinates: ";
              std::cin >> tarCord;
              char trcX = tarCord[0];
              std::string trcY = tarCord.substr(1);
              P1grid.fire(P1grid.alphConvert(trcX), atoi(trcY.c_str()));
              std::cout << "\n\n";
              P1grid.display(1);
              movemade = true;
           } else if(movesel == "D" || movesel == "d") {
                P2grid.display(0);
           } else if (movesel == "Q" || movesel == "q") {
                P2grid.nuke();
                movemade = true;
           } else{
              std::cout << "INVALID INPUT" << '\n';
          }
         }
         movemade = false;
         ply1 = true;
         ply2 =false;
       }
       else{
         break;
       }

     } while(P1grid.gameactive() != 0 && P2grid.gameactive() !=0 );

     if (P1grid.gameactive() == 0) {
       typedPrint("Player 1's fleet destroyed. Congratulations, Admiral.");
       std::cout<< '\n';
       P1grid.display(0);
       gameRun = false;
     }
     else{
       typedPrint("Player 2's fleet destroyed. Congratulations, Admiral.");
       std::cout << '\n';
       P2grid.display(0);
       gameRun = false;
     }

  }
  return 0;
}
