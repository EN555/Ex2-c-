#include "doctest.h"
#include <iostream>
#include "Board.hpp"
#include <cmath>
#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;


TEST_CASE("Horizontal"){
    Board board;    //create an object on the stack
    //without spaces
    board.post(0,0,Direction::Horizontal,"eviatar");
    CHECK(board.read(0,0,Direction::Horizontal,0)==" ");       //need to check what need to return
    CHECK(board.read(0,0,Direction::Horizontal,3)=="evi");
    CHECK(board.read(0,0,Direction::Horizontal,5)=="eviat");
    CHECK(board.read(0,0,Direction::Horizontal,7)=="eviatar");
    //with spaces
    CHECK(board.read(0,6,Direction::Horizontal,4)=="r___");       //need to check what need to return
    CHECK(board.read(0,7,Direction::Horizontal,3)=="___");
    CHECK(board.read(0,8,Direction::Horizontal,3)=="___");
}

TEST_CASE("Vertical"){
    Board board;    //create an object on the stack
    //without spaces
    board.post(0,0,Direction::Vertical,"eviatar");
    CHECK(board.read(0,0,Direction::Vertical,0)==" ");       //need to check what need to return
    CHECK(board.read(0,0,Direction::Vertical,3)=="evi");
    CHECK(board.read(0,0,Direction::Vertical,5)=="eviat");
    CHECK(board.read(0,0,Direction::Vertical,7)=="eviatar");
    //with spaces
    CHECK(board.read(6,0,Direction::Vertical,3)=="r__");
    CHECK(board.read(0,7,Direction::Vertical,3)=="___");
    CHECK(board.read(0,8,Direction::Vertical,3)=="___");
}

TEST_CASE("StringsOnStrings"){
    Board board;    //create an object on the stack
    board.post(0,0,Direction::Horizontal,"eviatar");
    board.post(0,0,Direction::Horizontal,"talia");
    CHECK(board.read(0,0,Direction::Horizontal,5)=="talia");
    CHECK(board.read(0,5,Direction::Horizontal,2)== "ar");
    CHECK(board.read(0,5,Direction::Horizontal,2)== "ar");
    CHECK(board.read(0,7,Direction::Horizontal,2)== "__");

}

//TEST_CASE("BigBoard & BigStrings"){
//    Board board;    //create an object on the stack
//    unsigned int row = rand()%1000 + 1;
//    unsigned int col = rand()%1000 + 1;
//    std::string s(100, 'A');
//    CHECK_NOTHROW(board.post(row,col,Direction::Horizontal,s));
//    CHECK_NOTHROW(board.post(row,col,Direction::Vertical,s));
//}

TEST_CASE("Empty Board"){
    Board board;   //create an empty board on the stack and check the flexibility
    unsigned int row = rand()%10000 + 1;
    unsigned int col = rand()%10000 + 1;
    unsigned int str_len = rand()%10000 + 1;
    std::string s(str_len,'_');     //create string "______ ..." in str_len length
    CHECK(board.read(row,col,Direction::Horizontal,str_len)== s);
    CHECK(board.read(row,col,Direction::Vertical,str_len)== s);
}

TEST_CASE("strangeStrings"){
    Board board;    //create an object on the stack
    board.post(0,0,Direction::Horizontal,"@#$%^&*()*&^%$#@%^*&^%$#@!@%#^&");
    CHECK(board.read(0,0,Direction::Horizontal,5)=="@#$%^");
    CHECK(board.read(0,5,Direction::Horizontal,2)== "&*");
    CHECK(board.read(0,7,Direction::Horizontal,2)== "()");
}

