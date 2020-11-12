#include "BigInteger.h"

/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BigInteger::BigInteger()
{
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
BigInteger::~BigInteger()
{
}
/**
	@brief:			Bu fonksiyon sayýlarýn basamaklarýný karsýlastirip buyuk olaný dondurmeye yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
int BigInteger::Max(int lenght1, int lenght2)
{
	if (lenght1 > lenght2)
	{
		return lenght1;
	}
	return lenght2;
}
/**
	@brief:			Bu fonksiyon metoddaki toplama islemini yapmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
string BigInteger::Add(string value1, string value2)
{
	int length = max(value1.size(), value2.size());
	int carry = 0;
	int sum_col;
	string result;

	//Basamaklari esitlemek icin eksik olan sayinin basi 0 ile doldurulur.
	while (value1.size() < length)
		value1.insert(0, "0");

	while (value2.size() < length)
		value2.insert(0, "0");

	//Toplama islemi yapilir.
	for (int i = length - 1; i >= 0; i--) {
		sum_col = (value1[i] - '0') + (value2[i] - '0') + carry;
		carry = sum_col / 10;
		result.insert(0, to_string(sum_col % 10));
	}

	if (carry)
		result.insert(0, to_string(carry));

	//Bastaki 0lar kaldirilir ve sonuc dondurulur.
	int zero = min(result.find_first_not_of('0'), result.size() - 1);
	result = result.erase(0, zero);
	return result;
}
/**
	@brief:			Bu fonksiyon metoddaki cikarma islemini yapmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
string BigInteger::Subtract(string value1, string value2)
{
	int length = max(value1.size(), value2.size());
	int diff;
	string result;
	//Basamaklari esitlemek icin eksik olan sayinin basi 0 ile doldurulur.
	while (value1.size() < length)
		value1.insert(0, "0");

	while (value2.size() < length)
		value2.insert(0, "0");

	//Cikarma islemi yapilir.
	for (int i = length - 1; i >= 0; i--) {
		diff = (value1[i] - '0') - (value2[i] - '0');
		if (diff >= 0)
			result.insert(0, to_string(diff));
		else {
			int j = i - 1;
			while (j >= 0) {
				value1[j] = ((value1[j] - '0') - 1) % 10 + '0';
				if (value1[j] != '9')
					break;
				else
					j--;
			}
			result.insert(0, to_string(diff + 10));
		}
	}
	//Bastaki 0lar kaldirilir ve sonuc dondurulur.
	int zero = min(result.find_first_not_of('0'), result.size() - 1);
	result = result.erase(0, zero);
	return result;
}
/**
	@brief:			Bu fonksiyon metodun kendisini gerceklemeye yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
string BigInteger::Multiply(string value1, string value2)
{
	int length = max(value1.size(), value2.size());

	//Basamaklari esitlemek icin eksik olan sayinin basi 0 ile doldurulur.
	while (value1.size() < length)
		value1.insert(0, "0");

	while (value2.size() < length)
		value2.insert(0, "0");

	if (length == 1)
		return to_string((value1[0] - '0') * (value2[0] - '0'));

	//Karatsuba metodu kullanilarak carpma islemi rekursif olarak gerceklestirilir.
	string w = value1.substr(0, length / 2);
	string x = value1.substr(length / 2, length - length / 2);
	string y = value2.substr(0, length / 2);
	string z = value2.substr(length / 2, length - length / 2);

	string p0 = Multiply(w, y);
	string p1 = Multiply(x, z);
	string p2 = Multiply(Add(w, x), Add(y, z));
	string p3 = Subtract(p2, Add(p0, p1));

	for (int i = 0; i < 2 * (length - length / 2); i++)
		p0.append("0");
	for (int i = 0; i < length - length / 2; i++)
		p3.append("0");

	string result = Add(Add(p0, p1), p3);
	//Bastaki 0lar kaldirilir ve sonuc dondurulur.
	int zero = min(result.find_first_not_of('0'), result.size() - 1);
	result = result.erase(0, zero);
	return result;
}
/**
	@brief:			Bu fonksiyon sayilarimizi dosyadan okumaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
string BigInteger::Readfile(string filename, int N)
{
	ifstream dataFile;
	dataFile.open(filename);
	string tempValue, value;
	if (!dataFile)
	{
		cout << "The file was not open." << endl;
		system("pause");
		exit(0);
	}
	//dosyadaki sayi stringde tutulur.
	while (!dataFile.eof())
	{
		dataFile >> tempValue;
	}
	if (N > tempValue.size())
	{
		cout << "N > Number in file" << endl;
		system("pause");
		exit(0);
	}
	for (int i = 0; i < N; i++)
		value += tempValue[i];
	dataFile.close();
	/*
		Projede istenilen durum aþaðýdaki açýklamada yer almaktadýr.
		The first digit in the file represents the least significant digit of the number, and the last digit represents
		the most significant digit.That means that if A.txt contains “123456”, this represents the decimal number
		654321 and not 123456. The result must also be written with the least significant digit first.
	*/
	value = string(value.rbegin(), value.rend());
	return value;
}
/**
	@brief:			Bu fonksiyon sonucumuzu dosyaya yazmaya yarar ..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
bool BigInteger::WriteFile(string result)
{
	ofstream ResultFile;
	ResultFile.open("result.txt");
	if (!ResultFile)
	{
		cout << "The file was not create.";
		return 0;
	}
	/*
		Projede istenilen durum aþaðýdaki açýklamada yer almaktadýr.
		The first digit in the file represents the least significant digit of the number, and the last digit represents
		the most significant digit.That means that if A.txt contains “123456”, this represents the decimal number
		654321 and not 123456. The result must also be written with the least significant digit first.
	*/
	result = string(result.rbegin(), result.rend());
	ResultFile << result;
	ResultFile.close();
	return 1;
}