#include "pch.h"

class DeterminantTest : public ::testing::TestWithParam<tuple<Matrix, int>> {

};
TEST_P(DeterminantTest, CheckDeterminantTest)
{
	Matrix A = get<0>(GetParam());
	int  expected = get<1>(GetParam());

	ASSERT_EQ(A.determinant(), expected);
}

INSTANTIATE_TEST_CASE_P(CheckDeterminantTest, DeterminantTest,
	::testing::Values(
		make_tuple(Matrix(0, 2.), 0),
		make_tuple(Matrix(1, 2.), 2),
		make_tuple(Matrix(3, -2.), 0)
	));
