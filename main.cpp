#include <iostream>
#include <cassert>
#include "matrix.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    {
        Matrix<int, -1> matrix; // бесконечная матрица int заполнена значениями -1
        assert(matrix.size() == 0); // все ячейки свободны

        auto a = matrix[0][0];
        assert(a == -1);
        assert(matrix.size() == 0);

        matrix[100][100] = 314;
        assert(matrix[100][100] == 314);
        assert(matrix.size() == 1);

        // выведется одна строка
        // 100100314
        for (const auto & elem : matrix)
        {
            int x;
            int y;
            int v;
            std::tie(x, y, v) = elem;
            std::cout << x << y << v << std::endl;
        }
    }
    {
        Matrix<int, 0> matrix;

        for (int i = 0; i < 10; ++i) 
        {
            matrix[i][i] = i;
        }

        for (int i = 0; i < 10; ++i) 
        {
            matrix[i][9 - i] = 9 - i;
        }

        for (int i = 1; i < 9; ++i) 
        {
            for (int j = 1; j < 9; ++j) 
            {
                std::cout << matrix[i][j] << ' ';
            }
            std::cout << '\n';
        }

        std::cout << "size() = " << matrix.size() << std::endl;

        for (const auto & i : matrix) 
        {
            int x;
            int y;
            int v;
            std::tie(x, y, v) = i;
            std::cout << '(' << x << ", " << y << ") = " << v << std::endl;
        }
    }

	return EXIT_SUCCESS;
}
