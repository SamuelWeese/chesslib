#include <iostream>
#include <string>
using namespace std;

#define DEF_VALID_PIECES {'K', 'k', 'Q', 'q', 'R', 'r', 'N', 'n', 'B', 'b', 'P', 'p'}

class board {
    char boardState[8][8];
    bool whiteMove;
    bool checkLegality(string aMove, board &aBoard);
    bool makeMove(string aStr);
    void makeSafeMove(); // not sure on return type, may need to change to bool later
    void print();
    string generateFEN();
}
