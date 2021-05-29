#include "pch.h"

class AdditionOperatorTest : public ::testing::TestWithParam<tuple< Matrix, Matrix, Matrix>> {

};
TEST_P(AdditionOperatorTest, CheckAdditionOperatorTest)
{
	Matrix A = get<0>(GetParam());
	Matrix B = get<1>(GetParam());
	Matrix C = get<2>(GetParam());

	A = A + B;
	ASSERT_EQ(A.data, C.data);
}



INSTANTIATE_TEST_CASE_P(CheckAdditionOperatorTest, AdditionOperatorTest,
	::testing::Values(

		make_tuple(Matrix(1,vector<double>(1)), Matrix(1, vector<double>(1)), Matrix(1, vector<double>(2))),
		make_tuple(Matrix(1,1.), Matrix(1, 2.), Matrix(1, 3.)),
		make_tuple(Matrix(3,2,2.), Matrix(3, 2, 2.), Matrix(3, 2,4.)),
		make_tuple(Matrix(3,0), Matrix(3, 0), Matrix(3, 0)),
		make_tuple(Matrix(0), Matrix(0), Matrix(0)),
		make_tuple(Matrix(3, sqrt(2)), Matrix(5, sqrt(3) ), Matrix(5, sqrt(2)+sqrt(3))),
		make_tuple(Matrix(5, -1.), Matrix(5, -10.), Matrix(5,-11.))
	));