#include "pch.h"

class LoadDataTest : public ::testing::TestWithParam<tuple< int, int >> {

};
TEST_P(LoadDataTest, CheckLoadDataTest)
{
	int A = get<0>(GetParam());
	int B = get<1>(GetParam());

	double** tab = new double *[A];
	vector<double> vec;

	for (int i = 0; i < A; i++)
	{
		tab[i] = new double[B];

	}
	double value=0;
	for (int i = 0; i < A; i++)
	{

		for (int j = 0; j < B; j++)


		{
			tab[i][j] = value;
			vec.push_back(value);
			value += 2;

		}

	}

	Matrix C = Matrix(A, B);
	Matrix D = Matrix(A, B);

	EXPECT_TRUE(C.load_data(tab));
	EXPECT_TRUE(D.load_data(vec, A, B));
	value = 0;
	for (int i = 0; i < A*B; i++)
	{
		ASSERT_EQ(C.data.at(i), value);
		value += 2;
	}
	ASSERT_EQ(D.data, vec); 
	delete [] tab;
}

INSTANTIATE_TEST_CASE_P(CheckLoadDataTest, LoadDataTest,
	::testing::Values(
		make_tuple(2,3),
		make_tuple(1,1),
		make_tuple(150, 20),
		make_tuple(0, 0),
		make_tuple(3, 4)
	));
