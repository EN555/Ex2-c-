//
// Created by eviat on 3/21/2021.
//
#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>

using namespace ariel;
using namespace std;
int main(){

    Board board;
    board.post(0,0,Direction::Horizontal,"eviatar");
    board.post(0,0,Direction::Horizontal,"talia");
  // CHECK(board.read(0,5,Direction::Vertical,2)== "ar");
    board.show();
    return 0;
}