# include <iostream>
#include "Header.h"
int main()
{
	Matrix M[N];
	cout << "Enter elements of the matrix M:" << endl;
	InputMatrix(N);
	cout << endl << "Your matrix:" << endl << endl;
	OutputMatrix(N);
	SortMatrix(M);
	cout << endl << "Sorted matrix:" << endl << endl;
	OutputMatrix(M);
	M[N].Diag(M);
	M[N].Elements(M);
	system("pause");
	return 0;
} 