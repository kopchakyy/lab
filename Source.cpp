# include <iostream>
#include "Header.h"
int main()
{
	Matrix M[n];
	cout << "Enter elements of the matrix M:" << endl;
	InputMatrix(M);
	cout << endl << "Your matrix:" << endl << endl;
	OutputMatrix(M);
	SortMatrix(M);
	cout << endl << "Sorted matrix:" << endl << endl;
	OutputMatrix(M);
	M[n].Diag(M);
	M[n].Elements(M);
	system("pause");
	return 0;
}