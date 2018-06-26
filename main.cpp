#include <iostream>
#include "Cell.hpp"
#include "Minesweeper.h"



int main() {
    Mines::Minesweeper ms;
    CellBase cell(0,0);
    ms.click(cell);
    return 0;
}