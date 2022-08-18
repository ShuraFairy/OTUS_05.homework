#define BOOST_TEST_MODULE test_version

//#include "lib.h"
#include <boost/test/unit_test.hpp>
#include "matrix.h"

BOOST_AUTO_TEST_SUITE(boost_test_version)

BOOST_AUTO_TEST_CASE(operatorset) 
{
	Matrix<int, -1> matrix;
	matrix[1][1] = -1;
	BOOST_CHECK(matrix[1][1] == -1);
	BOOST_CHECK(matrix.size() == 0);
	matrix[100][100] = 314;
	BOOST_CHECK(matrix[100][100] == 314);
	BOOST_CHECK(matrix.size() == 1);
}

BOOST_AUTO_TEST_CASE(tasktest) 
{
	Matrix<int, 0> matrix;
	for (int i = 0; i < 10; ++i) {
		matrix[i][i] = i;
	}
	for (int i = 0; i < 10; ++i) {
		matrix[i][9 - i] = 9 - i;
	}
	BOOST_CHECK(matrix.size() == 18);
}

BOOST_AUTO_TEST_SUITE_END()
