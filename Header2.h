#pragma once
#include <iostream>
#define N 5
#define C columns
#define S strings
using namespace std;
class Matrix
{
private:
	double M[N];
public:
	friend void InputMatrix(Matrix M[N]);
	friend void OutputMatrix(Matrix M[N]);
	friend void SortMatrix(Matrix M[N]);
	void Diag(Matrix M[N]);
	int Elements(Matrix M[N]);
};
void InputMatrix(Matrix M[N])
{
	for (int S = 0; S < N; S++)
	{
		for (int C = 0; C < N; C++)
		{
			cout << "M[" << S + 1 << "][" << C + 1 << "] = ";
			cin >> M[S].M[C];
		}
	}
}
void OutputMatrix(Matrix M[N])
{
	for (int S = 0; S < N; S++)
	{
		for (int C = 0; C < N; C++)
		{
			cout << M[S].M[C] << "\t";
		}
		cout << endl;
	}
}
void Matrix::Diag(Matrix M[N])
{
	int S = 0, C;
	C = S;
	cout << endl << "diagonal elements:" << endl << endl;
	for (S; C < N; S++, C++)
	{
		cout << M[S].M[C] << "\t";
	}
	cout << endl;
}
int Matrix::Elements(Matrix M[N])
{
	int S, C, prod;
	double sum = 0, ser, k = 0.0;
	for (S = 1; S< N; S++)
	{
		prod = 1;
		for (C= 0; C < N; C++)
		{
			if (S > C) {
				prod *= M[S].M[C];
			}
		}
		cout << endl << "Product of the elements of the " << S + 1 << " line is " << prod << endl;
		sum += prod;
		k += 1.0;
	}
	sum += M[S].M[C];
	cout << endl << "sum = " << sum << endl;
	return 0;
}
void SortMatrix(Matrix M[])
{
	for (int C = 0; C < 5; C++)
	{
		int Mat1[2];
		int Mat2[3];
		for (int S = 0; S < 5; S++)
		{
			if (S < 2)
				Mat1[S] = M[S].M[C];
			else
				Mat2[S - 2] = M[S].M[C];
		}
		for (int c = 0; c < 1; c++)
		{
			int x;
			if (Mat1[c] > Mat1[c + 1])
			{
				x = Mat1[c];
				Mat1[c] = Mat1[c + 1];
				Mat1[c + 1] = x;
			}
		}
		for (int c1 = 0; c1 < 2; c1++)
		{
			for (int c = 0; c < 2; c++)
			{
				int x;
				if (Mat2[c] > Mat2[c + 1])
				{
					x = Mat2[c];
					Mat2[c] = Mat2[c + 1];
					Mat2[c + 1] = x;
				}
			}
		}
		int indexMat1 = 0;
		int indexMat2 = 0;
		int indexResMat = 0;
		bool isSubMat1 = false;
		bool isSubMat2 = false;
		while (indexMat1 < 2)
		{
			if (Mat1[indexMat1] > Mat2[indexMat2])
			{
				M[indexResMat].M[C] = Mat2[indexMat2];
				indexMat2++;
				if (indexMat2 == 3)
					isSubMat2 = true;
			}
			else
			{
				M[indexResMat].M[C] = Mat1[indexMat1];
				indexMat1++;
				if (indexMat1 == 2)
					isSubMat1 = true;
			}
			indexResMat++;
			if (isSubMat1)
			{
				for (indexMat2; indexMat2 < 3; indexMat2++)
				{
					M[indexResMat].M[C] = Mat2[indexMat2];
					indexResMat++;
				}
				break;
			}
			if (isSubMat2)
			{
				for (indexMat1; indexMat1 < 2; indexMat1++)
				{
					M[indexResMat].M[C] = Mat1[indexMat1];
					indexResMat++;
				}
				break;
			}
		}
	}
}