#include "pch.h"

class RankTest : public ::testing::TestWithParam<tuple<Matrix, int>> {

};
TEST_P(RankTest, CheckRankTest)
{
	Matrix A = get<0>(GetParam());
	int  expected = get<1>(GetParam());

	ASSERT_EQ(A.rank(), expected);
}

INSTANTIATE_TEST_CASE_P(CheckRankTest, RankTest,
	::testing::Values(
		make_tuple(Matrix(0, 2.), 0),
		make_tuple(Matrix(1, 100), 1),
		make_tuple(Matrix(3, -2.), 0),
		make_tuple(Matrix(3, vector<double>{1, 2, 3, 4, 3,2,1, 0 ,0}), 3),
		make_tuple(Matrix(3, 0.5), 0),
		make_tuple(Matrix(3), 0)

	));
