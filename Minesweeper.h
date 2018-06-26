#pragma once

#include <iostream>

#include <vector>
#include <ostream>
#include "Cell.hpp"

using namespace std;

struct Cell;

namespace Mines {
    struct Mine_board{
        Mine_board();

        template <typename T>
        Cell* get_cell(T cell){
            return &board[cell.getRow()][cell.getCol()];
        }

        template <typename T>
        bool isOutOfBounds(const T & cell)const{
            return cell.getRow() < 0 || cell.getCol() < 0 || cell.getRow() >= n || cell.getCol() >= n;
        }

        /* Friend functions */
        friend ostream &operator<<(ostream &os, const Mine_board &mine_board);

        static const int n = 6;
        Cell board[n][n];
    private:
        void fill_board();
        void determine_adj_cells();
        void determine_n_adj_mines();
    };


    struct Minesweeper {
        Minesweeper() {
            cout << mine_board << endl;
        }

        void click(CellBase cell){
            auto *ec = mine_board.get_cell<CellBase>(cell);

            switch (ec->getValue()){
                case 'E':
                    revealed(ec);
                    break;
                case 'M':
                    ec->setValue('X');
                    break;
            }

            cout << endl << mine_board << endl;
        }

    private:
        void revealed(Cell *cell) {
            if(cell->get_n_adj_mines() > 0){
                cell->setValue(cell->get_n_adj_mines()+ static_cast<int>('0'));
            }
            else{
                revealed_recursively(cell);
            }
        }
        void revealed_recursively(Cell *cell){
            for(auto ac : cell->adjacent_cells){
                auto *ec = mine_board.get_cell<CellBase>(*ac);
                if(ec->get_n_adj_mines() == 0 && ec->getValue() == 'E') {
                    ec->setValue(static_cast<int>(ec->get_n_adj_mines()+48));
                    revealed_recursively(ec);
                }
                else if (ec->getValue() == 'E'){
                    ec->setValue(static_cast<int>(ec->get_n_adj_mines()+48));
                }
            }
        }

        Mine_board mine_board;
    };

}//End of mines namespace.