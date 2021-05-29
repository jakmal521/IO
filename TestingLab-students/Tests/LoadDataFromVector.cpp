#include "pch.h"

class LoadDataVectorTest : public ::testing::TestWithParam<tuple< int, int >> {

};
TEST_P(LoadDataVectorTest, CheckLoadDataVectorTest)
{
	int A = get<0>(GetParam());
	int B = get<1>(GetParam());
	double** tab = new double* [A];

	for (int i = 0; i < A; i++)
	{
		tab[i] = new double[B];

	}
	double value = 0;
	for (int i = 0; i < A; i++)
	{

		for (int j = 0; j < B; j++)


		{
			tab[i][j] = value;
			value += 2;
		}

	}

	Matrix C = Matrix(A, B);
	C.load_data(tab);

	value = 0;
	for (int i = 0; i < A * B; i++)
	{
		ASSERT_EQ(C.data.at(i), value);
		value += 2;
	}

}

INSTANTIATE_TEST_CASE_P(CheckLoadDataVectorTest, LoadDataVectorTest,
	::testing::Values(
		make_tuple(2, 3),
		make_tuple(1, 1),
		make_tuple(150, 20),
		make_tuple(0, 0),
		make_tuple(3, 4)
	));
