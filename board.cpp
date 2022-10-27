/* the idea behind this is that K is white and k is black

Q q
B b
N n
R r
P p
*/

board::board()
{
    for (int iIter = 0; iIter < 8; iIter++)
    {
        for (int jIter = 0; jIter < 8; jIter++)
        {
            this->boardState[iIter][jIter] = ' ';
        }
    }
    this->boardState[0][0] = R;
    this->boardState[0][7] = R;
    this->boardState[7][0] = r;
    this->boardState[7][7] = r;
    this->boardState[0][1] = N;
    this->boardState[0][6] = N;
    this->boardState[7][1] = n;
    this->boardState[7][6] = n;
    this->boardState[0][2] = B;
    this->boardState[0][5] = B;
    this->boardState[7][2] = b;
    this->boardState[7][5] = b;
    this->boardState[0][3] = Q;
    this->boardState[0][4] = K;
    this->boardState[7][3] = q;
    this->boardState[7][4] = k;

    for (int iIter = 0; iIter < 8 iIter++)
    {
        boardState[1][iIter] = P;
        boardState[6][iIter] = p;
    }

}

bool safetyCheck(int xPlace, int yPlace, char badPiece)
{
    if (xPlace < 8 && xPlace > -1 && yPlace < 8 && yPlace > -1)
    {
        if (aBoard[xPlace][yPlace] == badPiece)
        {
            return false;
        }
    }
    return true;
}
bool rookCheck(xIter, yIter, char[][] &aBoard, char badPiece)
{
    int xPlace, yPlace;
    for ()
}
bool knightCheck(xIter, yIter, char[][] &aBoard, char badPiece)
{
    int xPlace, yPlace;
    for (int adderIter = -2; adderIter < 4; adderIter += 2)
    {
        for (int singleIter = -1; singleIter < 2; singleIter++)
        {
            xPlace = xIter + adderIter;
            yPlace = yIter + singleIter;
            if (!safetyCheck(xPlace, yPlace, badPiece))
            {
                return false;
            }
            xPlace = xIter + singleIter;
            yPlace = yIter + adderIter;
            if (!safetyCheck(xPlace, yPlace, badPiece))
            {
                return false;
            }
        }
    }
    return true;
}

bool pawnCheck(xIter, yIter, char[][] &aBoard, char badPiece, whiteMove)
{
    int distance = 1;
    int xPlace, yPlace;
    if (whiteMove) { distance *= -1;}
    for (int doubleIter = -1; doubleIter < 2; doubleIter += 2)
    {
        xPlace = xIter + doubleIter;
        yPlace = yIter + 1;
        if (xPlace < 8 && xPlace > -1 && yPlace < 8 && yPlace > -1)
        {
            if (aBoard[xPlace][yPlace] == badPiece)
            {
                return false;
            }
        }
    }
    return true;
}


bool board::checkLegality(char[][] &aBoard = this->boardState, bool whiteMove = this->whiteMove)
{
    bool whiteKing = false;
    bool blackKing = false;

    if (whiteMove)
    {
        for (int xIter = 0; xIter < 8; xIter++)
        {
            for (int yIter = 0; yIter < 8; yIter++)
            {
                if (aBoard[xIter][yIter] == 'K')
                {

                    // bishop / queen checking
                    counterX = 1;
                    while (counterX + xIter < 8 && counterX + yIter < 8)
                    {
                        if (aBoard[counterX+xIter][counterX+yIter] == 'b' || aBoard[counterX+xIter][counterX+yIter] == 'q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][counterX+yIter] == ' ')
                        {
                            break;
                        }
                        counterX++;
                    }
                    counterX = 1;
                    counterY = -1
                    while (counterX + xIter < 8 && counterY + yIter > 0)
                    {
                        if (aBoard[counterX+xIter][yIter+counterY] == 'b' || aBoard[counterX+xIter][counterY+yIter] == 'q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][yIter+counterY] == ' ')
                        {
                            break;
                        }
                        counterX++;
                        counterY--;
                    }
                    counterX = -1;
                    counterY = 1
                    while (counterX + xIter > 0 && counterY + yIter < 8)
                    {
                        if (aBoard[counterX+xIter][yIter+counterY] == 'b' || aBoard[counterX+xIter][counterY+yIter] == 'q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][yIter+counterY] == ' ')
                        {
                            break;
                        }
                        counterX--;
                        counterY++;
                    }
                    counterX = -1;
                    counterY = -1
                    while (counterX + xIter > 0 && counterY + yIter > 0)
                    {
                        if (aBoard[counterX+xIter][yIter+counterY] == 'b' || aBoard[counterX+xIter][counterY+yIter] == 'q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][yIter+counterY] == ' ')
                        {
                            break;
                        }
                        counterX--;
                        counterY--;
                    }
                    if (!knightCheck(xIter, yIter, aBoard, 'n'))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    if (!whiteMove)
    {
        for (int xIter = 0; xIter < 8; xIter++)
        {
            for (int yIter = 0; yIter < 8; yIter++)
            {
                if (aBoard[xIter][yIter] == 'k')
                {
                    // rook/queen check
                    int counterX = -1;
                    int counterY = -1;
                    while (counterX + xIter > 0)
                    {
                        if (aBoard[xIter + counterX][yIter] == 'R' || aBoard[xIter + counterX][yIter] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[xIter + counterX][yIter] != ' ')
                        {
                            break;
                        }
                        counterX--;
                    }
                    while (counterY + yIter > 0)
                    {
                        if (aBoard[xIter][yIter+counterY] == 'R' || aBoard[xIter][yIter+counterY] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[xIter][yIter+counterY] != ' ')
                        {
                            break;
                        }
                        counterY--;
                    }

                    counterX = 1;
                    counterY = 1;
                    while (counterX + xIter < 8)
                    {
                        if (aBoard[xIter + counterX][yIter] == 'R' || aBoard[xIter + counterX][yIter] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[xIter + counterX][yIter] != ' ')
                        {
                            break;
                        }
                        counterX++;
                    }
                    while (counterY + yIter < 8)
                    {
                        if (aBoard[xIter][yIter+counterY] == 'R' || aBoard[xIter][yIter+counterY] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[xIter][yIter+counterY] != ' ')
                        {
                            break;
                        }
                        counterY++;
                    }
                    // bishop / queen checking
                    counterX = 1;
                    while (counterX + xIter < 8 && counterX + yIter < 8)
                    {
                        if (aBoard[counterX+xIter][counterX+yIter] == 'B' || aBoard[counterX+xIter][counterX+yIter] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][counterX+yIter] == ' ')
                        {
                            break;
                        }
                        counterX++;
                    }
                    counterX = 1;
                    counterY = -1
                    while (counterX + xIter < 8 && counterY + yIter > 0)
                    {
                        if (aBoard[counterX+xIter][yIter+counterY] == 'B' || aBoard[counterX+xIter][counterY+yIter] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][yIter+counterY] == ' ')
                        {
                            break;
                        }
                        counterX++;
                        counterY--;
                    }
                    counterX = -1;
                    counterY = 1
                    while (counterX + xIter > 0 && counterY + yIter < 8)
                    {
                        if (aBoard[counterX+xIter][yIter+counterY] == 'B' || aBoard[counterX+xIter][counterY+yIter] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][yIter+counterY] == ' ')
                        {
                            break;
                        }
                        counterX--;
                        counterY++;
                    }
                    counterX = -1;
                    counterY = -1
                    while (counterX + xIter > 0 && counterY + yIter > 0)
                    {
                        if (aBoard[counterX+xIter][yIter+counterY] == 'B' || aBoard[counterX+xIter][counterY+yIter] == 'Q')
                        {
                            return false;
                        }
                        if (aBoard[counterX+xIter][yIter+counterY] == ' ')
                        {
                            break;
                        }
                        counterX--;
                        counterY--;
                    }
                    if (!knightCheck(xIter, yIter, aBoard, 'N'))
                    {
                        return false;
                    }

                }
            }
        }
        return true;
    }
}

bool board::makeMove(string aMove)
{
    {
        int pieceX;
        int pieceY;
        if (aMove[0] > Z)
        {
            // pawn moves

        }
        switch (aMove[0]) {
            case 'R': {

            }
            case 'N':
            case 'B':
            case 'Q':
            case 'K':
        }
    }
}

void board::print()
{

    for (int iIter = 0; iIter < 8; iIter++)
    {
        for (int jIter = 0; jIter < 8; jIter++)
        {
            std::cout << '[' << this->boardState[iIter] << ']'

        }
        std::cout << '\n';
    }
    std::cout << '\n';

}


string board::generateFEN()
{
    string retStr;
    for (auto xIter : this->boardState)
    {
        int spaceCounter = 0;
        for (auto yIter : xIter)
        {
            if (yIter == ' ')
            {
                spaceCounter++;
                continue;
            }
            if (spaceCounter > 0)
            {
                retStr += spaceCounter;
                spaceCounter = 0;
            }
            retStr += yIter;
        }
        retStr += '/';
    }
    if (whiteMove)
    {
        retStr += " w";
    }
    else {
        retStr += " b";
    }
    return retStr;
}
