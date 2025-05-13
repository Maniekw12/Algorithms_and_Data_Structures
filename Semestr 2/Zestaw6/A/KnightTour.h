#include <iostream>
#include <vector>
#include <algorithm>

// w skrocie ten algorytm wybiera kolejny krok taki
// ktory ma najmniej kolejnych ruchow

class KnightTour{
private:
    int board_size;
    std::vector<std::vector<int>> board;

    // wszystkie możliwe ruchy rycerza na planszy x oraz planszy y
    int move_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int move_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};


    bool is_safe(int x, int y){
        return (x >= 0 && x < board_size && y >= 0 && y < board_size && board[x][y] == -1);
    }

    int count_degree(int x, int y){
        int count = 0;

        for(int i = 0; i < 8;i++){
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];

            if(is_safe(next_x,next_y)){
                count++;
            }
        }
        return count;
    }

    bool solve_tour(int x, int y, int move_count){

        board[x][y] = move_count;
        if (move_count == board_size * board_size) {
            return true;
        }

        class NextMove{
        public:
            int x, y;
            int degree;
        };
        std::vector<NextMove> next_moves;

        for(int i=0; i<8;i++){
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];

            // Oblicz liczbę wyjść dla tego pola (heurystyka Warnsdorffa)
            if (is_safe(next_x, next_y)) {
                int degree = count_degree(next_x, next_y);
                next_moves.push_back({next_x, next_y, degree});
            }
        }

        // Posortuj ruchy według heurystyki Warnsdorffa (najpierw pola z najmniejszą liczbą wyjść)
        std::sort(next_moves.begin(), next_moves.end(),
                  [](const NextMove& a, const NextMove& b) { return a.degree < b.degree; });

        // Wypróbuj każdy z możliwych ruchów, zaczynając od tych z najmniejszą liczbą wyjść
        for (const auto& move : next_moves) {
            if (solve_tour(move.x, move.y, move_count + 1)) {
                return true;
            }
        }

        // Jeśli żaden ruch nie prowadzi do rozwiązania, cofnij ten ruch (backtracking)
        board[x][y] = -1;
        return false;
    }

public:
    KnightTour(int size): board_size(size){
        board.resize(size, std::vector<int>(size, -1));
    }

    bool solve(int start_x = 0, int start_y = 0) {
        return solve_tour(start_x, start_y, 1);
    }

    void print_solution() {
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                std::cout  << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};







