#include <iostream>

enum Piece {EMPTY, X, O};

class Utils {
public:
    static bool check_number_in_range(int val_to_check, int lower_range, int upper_range) {
        return (val_to_check < upper_range && val_to_check > lower_range);
    }
    static std::string print_piece(Piece p) {
        switch(p) {
            case EMPTY:
                return " ";
            case X:
                return "X";
            case O:
                return "O";
        }
    }
};

template <class T>
class TwoDimArray {
private:
    int width;
    int height;
    T* arr;
    void init_board(int w, int h, T default_value) {
        int size = w * h;
        this->arr[size];
        for (int i = 0; i < size; i++) {
            arr[i] = default_value;
        }
    }

public:
    TwoDimArray(int w, int h, T default_value){
        width = w;
        height = h;
        init_board(width, height, default_value);
    }
    int get_height() {
        return this->height;
    }
    int get_width() {
        return this->width;
    }
    T get (int x, int y) {
        if (not (Utils::check_number_in_range(x, -1, this->width) &&
                 Utils::check_number_in_range(y, -1, this->height))) {
            throw std::invalid_argument("Index not in range of array.");
        }
        int idx = y * this->width + x;
        return this->arr[idx];
    };
    void set (T val_to_set, int x, int y) {
        if (not (Utils::check_number_in_range(x, -1, this->width) &&
                 Utils::check_number_in_range(y, -1, this->height))) {
            throw std::invalid_argument("Index not in range of array.");
        }
        int idx = y * this->width + x;
        arr[idx] = val_to_set;
    }
};

//class Board {
//private:
//    const int rows = 3;
//    const int cols = 3;
//    TwoDimArray<Piece> b;
//public:
//    Board(Piece start_piece) {
//        b = TwoDimArray<Piece>(3, 3, EMPTY);
//    }
//    void print_status() const {
//        std::cout << "Rows: " << this->rows << " Cols: " << this->cols << std::endl;
//    }
//};



int main() {
    int p = 9;
    int* ptr = new int(9);
    std::cout << "Hello, World!" << std::endl;
    std::cout << ptr << " // " << *ptr << " // " << &ptr << std::endl;
//    Board b = Board(10, 3);
//    b.print_status();
//    TwoDimArray<Piece> t = TwoDimArray<Piece>(3, 3, EMPTY);
//    t.set(X, 0, 2);
//    std::cout << t.get(0, 0) << " // " << t.get(0, 2) << std::endl;
    return 0;
}
