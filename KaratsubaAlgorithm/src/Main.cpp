#include<iostream>
#include<stdlib.h>
#include "BigInteger.h"
/**
	@author:		Ýsmail DEMÝRCAN-Eda ÇAM -->152120171029-152120171037//ALGORITHMS AND COMPLEXITY (A)
	@date:			28 Mart 2020 Cumartesi
	@brief:			Bu kod parcacigi Long integer iki sayýyý Karatsuba Algorithm kullanarak çarpmaya yarar.
*/
int main()
{
	BigInteger A;
	int N;
	string filename1, filename2;
	string value1, value2, result;
	
	cout << "Enter N: ";
	cin >> N;

	cout << "Enter first file name: ";
	cin >> filename1;
	value1 = A.Readfile(filename1, N);

	cout << "Enter first file name: ";
	cin >> filename2;
	value2 = A.Readfile(filename2, N);

	result = A.Multiply(value1, value2);
	if (A.WriteFile(result))
		cout << "The resulting integer is written to 'result.txt'" << endl;

	system("pause");
}