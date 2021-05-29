#include "pch.h"
class CopyConstructorTest : public ::testing::TestWithParam<tuple<Matrix>> {

};
TEST_P(CopyConstructorTest, CheckCopyConstructorTest)
{
	Matrix A = get<0>(GetParam());
	Matrix B(A);
	for(int i=0; i<A.rows*A.columns; i++)
		ASSERT_EQ(A.data.at(i),B.data.at(i));
}

INSTANTIATE_TEST_CASE_P(CheckCopyConstructorTest, CopyConstructorTest,
	::testing::Values(
		make_tuple(Matrix(2)),
		make_tuple(Matrix(2, 2.)),
		make_tuple(Matrix(2, vector<double>{1, 2, 3, 4})),
		make_tuple(Matrix(1, vector<double>{1})),
		make_tuple(Matrix(3, vector<double>{1, 2, 3, 4, 5, 6, 7, 8, 9})),
		make_tuple(Matrix(3, 3, 2.)),
		make_tuple(Matrix(3, 3))
		));




