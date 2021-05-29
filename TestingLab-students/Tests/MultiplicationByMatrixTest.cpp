#include "pch.h"

class MultiplicationByMatrixTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix >> {

};
TEST_P(MultiplicationByMatrixTests, CheckMultiplicationByMatrixTests)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix C = get<2>(GetParam());
	
	A = A * B;

	ASSERT_EQ(A.data, C.data);
	
}

INSTANTIATE_TEST_CASE_P(CheckMultiplicationByMatrixTests, MultiplicationByMatrixTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0), Matrix(2, 3, 2.), Matrix(2, 3, 4.)),
		make_tuple(Matrix(1, 2.), Matrix(1, 7.), Matrix(1, 14.)),
		make_tuple(Matrix(2, vector<double>{1, 2, 3, 4}), Matrix(2, 2.), Matrix(2, vector<double>{6, 6, 14, 14})),
		make_tuple(Matrix(5, 10.0), Matrix(5, 0.5), Matrix(5, 0.25)),
		make_tuple(Matrix(5, 2), Matrix(5, 0), Matrix(5,0))
	));
		