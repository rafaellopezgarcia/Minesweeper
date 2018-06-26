#include "Minesweeper.h"

namespace Mines {

    Mine_board::Mine_board() {
        fill_board();
        determine_adj_cells();
        determine_n_adj_mines();
    }

    void Mine_board::fill_board() {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                board[i][j].setValue('E');
                board[i][j].setRow(i);
                board[i][j].setCol(j);
            }
        }
        board[1][2].setValue('M');
        board[1][3].setValue('M');
        board[3][3].setValue('M');
    }

    void Mine_board::determine_adj_cells() {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                board[i][j].determine_adjacent_cells(*this);
            }
        }
    }

    void Mine_board::determine_n_adj_mines() {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                Cell *e_cell = &board[i][j];
                for (auto ac : e_cell->adjacent_cells) {
                    if (board[ac->getRow()][ac->getCol()].getValue() == 'M') {
                        e_cell->set_n_adj_mines(e_cell->get_n_adj_mines()+1);
                    }
                }
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, const Mine_board &mine_board) {
        for (size_t i = 0; i < mine_board.n; ++i) {
            for (size_t j = 0; j < mine_board.n; ++j) {
                os << mine_board.board[i][j].getValue() << " ";
            }
            os << "\n";
        }
        return os;
    }

}

