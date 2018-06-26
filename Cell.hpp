#pragma once
#include <vector>
using namespace std;

typedef int Index;

namespace Mines {
    struct Mine_board;
}

struct CellBase{
    /* Constructors */
    CellBase() : row(0), col(0){}
    CellBase(Index row, Index col) : row(row), col(col){}
    CellBase(Index row, Index col, char value) : row(row), col(col), value(value){}

    /* Getters*/
    char getValue() const { return value; }
    Index getRow() const { return row; }
    Index getCol() const { return col; }

    /* Setters*/
    void setValue(char value) { CellBase::value = value; }
    void setRow(Index row) { CellBase::row = row; }
    void setCol(Index col) { CellBase::col = col; }

protected:
    char value;
    Index row, col;
};


struct Cell : public CellBase {
    /* Constructors */
    Cell() : CellBase(0,0), n_adjacent_mines(0){}
    Cell(Index row, Index col, char value) : CellBase(row, col, value), n_adjacent_mines(0){}

    /* Getters */
    int get_n_adj_mines() const { return n_adjacent_mines; }

    /* Setters */
    void set_n_adj_mines(int n_adjacent_mines) { Cell::n_adjacent_mines = n_adjacent_mines; }

    void determine_adjacent_cells(Mines::Mine_board & mine_board);

    std::vector <Cell*> adjacent_cells;

private:
    int n_adjacent_mines;
};

