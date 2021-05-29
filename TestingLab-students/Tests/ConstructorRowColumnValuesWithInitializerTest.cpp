#include "pch.h"

class ConstructorRowColumnValues: public ::testing::TestWithParam<tuple<Matrix, int, int , double>> {

};
TEST_P(ConstructorRowColumnValues, CheckConstructorRowColumnValuesTestWithInitializer)
{
	Matrix A = get<0>(GetParam());
	int rows = get<1>(GetParam());
	int columns = get<2>(GetParam());
	double value = get<3>(GetParam());
	ASSERT_EQ(A.rows, rows);
	ASSERT_EQ(A.columns, columns);
	for(int i=0; i<A.columns*A.rows; i++)
	ASSERT_EQ(A.data.at(i), value);
}

INSTANTIATE_TEST_CASE_P(CheckConstructorRowColumnValuesTest, ConstructorRowColumnValues,
	::testing::Values(

		make_tuple(Matrix(2, 1.0), 2,2,1.0),
		make_tuple(Matrix(2), 2,2,0),
		make_tuple(Matrix(200), 200,200,0),
		make_tuple(Matrix(3, 2.5), 3,3,2.5),
		make_tuple(Matrix(2, 2, 1.0), 2, 2, 1.0),
		make_tuple(Matrix(3, 3), 3,3 ,0),
		make_tuple(Matrix(0, 0, 2.),0,0,2.),
		make_tuple(Matrix(300, 1), 300, 1, 0),
		make_tuple(Matrix(1, 300),1,300, 0),
		make_tuple(Matrix(-1, -3, 1.),0,0, 1.)
	
	
	));