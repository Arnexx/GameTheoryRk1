#include <vector>
#include <iostream>
using namespace std;
#define lim 15
#include <iomanip>




float func(float x, float y)
{
	return -6 * x*x + 32 / 5.0*y*y + 16 * x*y - 16 / 5.0*x - 64 / 5.0*y;
}



float findNash(vector<vector<float>>& matrix, int N) {
	vector<float> B, A;
	vector<int> maxMinIndex, MinMaxindex;
	float min, max, minIndex, maxIndex;

	

	for (int i = 0; i < N; i++)
	{
		A.push_back( matrix[i][0]);
		minIndex = i;
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] < A[i])
			{
				A[i] = matrix[i][j];
				minIndex = i;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		B.push_back(matrix[0][i]);
		maxIndex = i;
		for (int j = 0; j < N; j++)
		{
			if (matrix[j][i] > B[i])
			{
				B[i] = matrix[j][i];
				maxIndex = i;
			}
		}
	}
	max = A[0];
	min = B[0];
	maxIndex = minIndex = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
			maxIndex = i;
		}

		if (B[i] < min)
		{
			min = B[i];
			minIndex = i;
		}
	}
	return matrix[maxIndex][minIndex];
}

int main() {
	vector<vector<float>> matrix;
	int N = 1;
	cout.setf(ios::fixed);

	for (int k = 0; k < lim; k++)
	{
		for (int i = 0; i < N; i++)
		{
			matrix.resize(N);
			for (int j = 0; j < N; j++)
			{
				matrix[i].push_back( func(i / (float)N, j / (float)N));
				cout << matrix[i][j] << "   ";
			}
			cout << endl;
		}

		cout << findNash(matrix, N)<< endl<<endl;

		N++;
	}


	system("pause");
	return 0;
}

