#pragma once
#include <iostream>

#define n 5
using namespace std;

class Matrix
{
private:
	double M[n];
public:
	friend void InputMatrix(Matrix M[n]);
	friend void OutputMatrix(Matrix M[n]);
	friend void SortMatrix(Matrix M[n]);
	void Diag(Matrix M[n]);
	int Elements(Matrix M[n]);
};

void InputMatrix(Matrix M[n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "M[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> M[i].M[j];
		}
	}
}

void OutputMatrix(Matrix M[n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << M[i].M[j] << "\t";
		}
		cout << endl;
	}
}

void Matrix::Diag(Matrix M[n])
{
	int i = 0, j;
	j = i;
	cout << endl << "diagonal elements:" << endl << endl;
	for (i; i < n; i++, j++)
	{
		cout << M[i].M[j] << "\t";
	}
	cout << endl;
}

int Matrix::Elements(Matrix M[n])
{
	int i, j, prod;
	double sum = 0, ser, k = 0.0;
	for (i = 1; i < n ; i++)
	{
		prod = 1;
		for (j = 0; j < n; j++)
		{
			if (i > j) {
				prod *= M[i].M[j];

					   }
		}
		cout << endl << "Product of the elements of the " << i + 1 << " line is " << prod << endl;
		sum += prod;
		k += 1.0;

	}

	sum += M[i].M[j];
	cout << endl << "sum = " << sum << endl;
	return 0;
}

void SortMatrix(Matrix M[])
{
	for (int j = 0; j < 5; j++)
	{
		int Mat1[2];
		int Mat2[3];
		for (int i = 0; i < 5; i++)
		{
			if (i < 2)
				Mat1[i] = M[i].M[j];

			else
				Mat2[i - 2] = M[i].M[j];
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
				M[indexResMat].M[j] = Mat2[indexMat2];
				indexMat2++;
				if (indexMat2 == 3)
					isSubMat2 = true;
			}
			else
			{
				M[indexResMat].M[j] = Mat1[indexMat1];
				indexMat1++;
				if (indexMat1 == 2)
					isSubMat1 = true;
			}
			indexResMat++;
			if (isSubMat1)
			{
				for (indexMat2; indexMat2 < 3; indexMat2++)
				{
					M[indexResMat].M[j] = Mat2[indexMat2];
					indexResMat++;
				}
				break;
			}
			if (isSubMat2)
			{
				for (indexMat1; indexMat1 < 2; indexMat1++)
				{
					M[indexResMat].M[j] = Mat1[indexMat1];
					indexResMat++;
				}
				break;
			}
		}
	}
}