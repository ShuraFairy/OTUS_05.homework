#include <gtest/gtest.h>
#include "matrix.h"


TEST(Matrixtest, operatorset) 
{
	Matrix<int, -1> matrix;
	matrix[1][1] = -1;
	EXPECT_EQ(matrix[1][1], -1);
	EXPECT_EQ(matrix.size(), 0);
	matrix[100][100] = 314;
	EXPECT_EQ(matrix[100][100], 314);
	EXPECT_EQ(matrix.size(), 1);
}

TEST(Matrixtest, tasktest) 
{
	Matrix<int, 0> matrix;
	for (int i = 0; i < 10; ++i) 
		matrix[i][i] = i;
	
	for (int i = 0; i < 10; ++i) 
		matrix[i][9 - i] = 9 - i;
	
	EXPECT_EQ(matrix.size(), 18);
}

TEST(Matrixtest, set_main_diagonal) {

	Matrix<int, 0> matrix;

	for (int i = 0; i < 10; ++i) {
		matrix[i][i] = i;
	}

	ASSERT_EQ(matrix[1][1], 1);
	ASSERT_EQ(matrix[2][2], 2);
	ASSERT_EQ(matrix[3][3], 3);
	ASSERT_EQ(matrix[4][4], 4);
	ASSERT_EQ(matrix[5][5], 5);
	ASSERT_EQ(matrix[6][6], 6);
	ASSERT_EQ(matrix[7][7], 7);
	ASSERT_EQ(matrix[8][8], 8);
	ASSERT_EQ(matrix[9][9], 9);

	ASSERT_EQ(matrix.size(), 9);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
