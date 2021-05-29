#include "pch.h"

class ConstructorWithVectorValuesTest : public ::testing::TestWithParam<tuple< int>> {

};
TEST_P(ConstructorWithVectorValuesTest, CheckConstructorWithVectorValuesTest)
{
	int x = get<0>(GetParam());
	int x2 =x;
	x *= x;
	vector<double> vec;
	while (x--)
	{
		vec.push_back(double(x * x));

	}
	Matrix A(x2, vec);
	Matrix B(x2, x2, vec);
	ASSERT_EQ(A.data, vec);
	ASSERT_EQ(B.data, vec);
	
}

INSTANTIATE_TEST_CASE_P(CheckConstructorWithVectorValuesTest, ConstructorWithVectorValuesTest,
	::testing::Values(
		make_tuple(-10),
		make_tuple(0),
		make_tuple(1),
		make_tuple(2),
		make_tuple(150),
		make_tuple(250),
		make_tuple(300)
	

	));



