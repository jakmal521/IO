#include "pch.h"

class ConstructorLambdaTests1Param : public ::testing::TestWithParam<tuple<Matrix, vector<double> >> {

};
TEST_P(ConstructorLambdaTests1Param, CheckConstructorLambdaTests1Param)
{
	Matrix A = get<0>(GetParam());
	vector<double > vec= get<1>(GetParam());
	ASSERT_EQ(A.data, vec);

}

INSTANTIATE_TEST_CASE_P(CheckConstructorLambdaTests1Param, ConstructorLambdaTests1Param,
	::testing::Values(
		make_tuple(Matrix(2, [](int i, int j) {return (double)i; }), vector<double>{0., 0., 1., 1.}),
		make_tuple(Matrix(3, [](int i, int j) {return (double)(i*i); }), vector<double>{0., 0.,0., 1., 1.,1.,4.,4.,4.}),
		make_tuple(Matrix(2, [](int i, int j) {return (double)-1; }), vector<double>{-1., -1., -1., -1.}),
		make_tuple(Matrix(0, [](int i, int j) {return (double)i; }), vector<double>{}),
		make_tuple(Matrix(1, [](int i, int j) {return (double)10; }), vector<double>{10.})
		
	));


class ConstructorLambdaTests2Param : public ::testing::TestWithParam<tuple<Matrix, vector<double> >> {

};
TEST_P(ConstructorLambdaTests2Param, CheckConstructorLambdaTests2Param)
{
	Matrix A = get<0>(GetParam());
	vector<double > vec = get<1>(GetParam());
	ASSERT_EQ(A.data, vec);

}

INSTANTIATE_TEST_CASE_P(CheckConstructorLambdaTests2Param, ConstructorLambdaTests2Param,
	::testing::Values(
		make_tuple(Matrix(2,2, [](int i, int j) {return (double)i; }), vector<double>{0., 0., 1., 1.}),
		make_tuple(Matrix(3,2, [](int i, int j) {return (double)(i * i); }), vector<double>{0., 0., 1., 1., 4.,4.}),
		make_tuple(Matrix(2,1, [](int i, int j) {return (double)-1; }), vector<double>{-1., -1.}),
		make_tuple(Matrix(0,1, [](int i, int j) {return (double)i; }), vector<double>{}),
		make_tuple(Matrix(1,1, [](int i, int j) {return (double)10; }), vector<double>{10.})
	));

class LoadDataLambdaTest : public ::testing::TestWithParam<tuple<Matrix, vector<double> >> {

};
TEST_P(LoadDataLambdaTest, CheckLoadDataLambdaTest)
{
	Matrix A = get<0>(GetParam());
	vector<double > vec = get<1>(GetParam());

	A.load_data([](int i, int j) {return (double)i*j; });


	ASSERT_EQ(A.data, vec);

}

INSTANTIATE_TEST_CASE_P(CheckLoadDataLambdaTest, LoadDataLambdaTest,
	::testing::Values(
		make_tuple(Matrix(2, 2), vector<double>{0., 0., 0., 1.}),
		make_tuple(Matrix(3, 2 ), vector<double>{0., 0., 0., 1., 0., 2.}),
		make_tuple(Matrix(2, 1), vector<double>{0., 0.}),
		make_tuple(Matrix(0, 1), vector<double>{}),
		make_tuple(Matrix(1, 1), vector<double>{0.})
	));
