#include "Cell.hpp"
#include "Minesweeper.h"

void Cell::determine_adjacent_cells(Mines::Mine_board & mine_board) {
    std::vector <CellBase> adjacenct_cell_indices;
    adjacenct_cell_indices.emplace_back(CellBase{row - 1, col - 1});
    adjacenct_cell_indices.emplace_back(CellBase{row    , col - 1});
    adjacenct_cell_indices.emplace_back(CellBase{row + 1, col - 1});
    adjacenct_cell_indices.emplace_back(CellBase{row + 1, col});
    adjacenct_cell_indices.emplace_back(CellBase{row + 1, col + 1});
    adjacenct_cell_indices.emplace_back(CellBase{row    , col + 1});
    adjacenct_cell_indices.emplace_back(CellBase{row - 1, col + 1});
    adjacenct_cell_indices.emplace_back(CellBase{row - 1, col});

    for (auto cell : adjacenct_cell_indices){
        if (!mine_board.isOutOfBounds<CellBase>(cell))
            adjacent_cells.emplace_back(mine_board.get_cell<CellBase>(cell));
    }
}