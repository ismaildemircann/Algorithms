#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
void swap(int* a, int* b);
int getMax(int A[], int N);
int Partition(int A[], int N);
/**
	@author:		Ýsmail DEMÝRCAN-Eda ÇAM -->152120171029-152120171037//ALGORITHMS AND COMPLEXITY (A)
	@date:			12 Mayýs 2020 Salý
	@brief:			Bu kod parcaciginda Sorting algoritmalarý implement edilmistir.
*/
/****************************************************
 * Uses bubble sort to sort A[0..N-1]
 ****************************************************/
void BubbleSort(int A[], int N) {
	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N - i; j++) //Sýralanmamýþ kýsým için sort iþlemi tekrarlanýr.
		{
			if (A[j - 1] > A[j])
			{
				tmp = A[j - 1]; //Swap.
				A[j - 1] = A[j];
				A[j] = tmp;
			}
		}
	}
} //end-BubbleSort

/****************************************************
 * Uses selection sort to sort A[0..N-1]
 ****************************************************/
void SelectionSort(int A[], int N) {
	int i, j, min;
	for (i = 0; i < N - 1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
			if (A[j] < A[min])
				min = j;
		int temp = 0;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
} //end-SelectionSort

/****************************************************
 * Uses insertion sort to sort A[0..N-1]
 ****************************************************/
void InsertionSort(int A[], int N) {
	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > value)
		{
			A[j + 1] = A[j]; //A[j] saða kaydýrýlýr.
			j--;
		}
		A[j + 1] = value;
	}
} //end-InsertionSort

/****************************************************
 * Uses mergesort to sort A[0..N-1]
 ****************************************************/
void MergeSort(int A[], int N) {
	if (N <= 1)
		return;
	MergeSort(A, N / 2);
	MergeSort(&A[N / 2], N / 2);
	int* B = new int[N];
	int i = 0;
	int j = N / 2;
	int k = 0;
	while (i != N / 2 && j != N)
	{
		if (A[i] <= A[j])
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	while (i < N / 2)
	{
		B[k] = A[i];
		i++;
		k++;
	}
	while (j < N)
	{
		B[k] = A[j];
		j++;
		k++;
	}
	for (int i = 0; i < N; i++)
	{
		A[i] = B[i];
	}
	delete[] B;
} //end-MergeSort

/****************************************************
 * Uses quicksort sort to sort A[0..N-1]
 ****************************************************/

void QuickSort(int A[], int N)
{
	if (N <= 1) return;
	int pivot = Partition(A, N); //Pivotun indexi belirlenir
	QuickSort(A, pivot); //Saðdakiler sýralanýr
	QuickSort(A + pivot + 1, N - pivot - 1); //Soldakiler sýralanýr
} //end-QuickSort
void heapify(int A[], int N, int i)
{
	int Max = i;
	int Left = 2 * i + 1;
	int Right = 2 * i + 2;
	if (Left < N && A[Left] > A[Max])
		Max = Left;
	if (Right < N && A[Right] > A[Max])
		Max = Right;
	int temp = 0;
	if (Max != i)
	{
		temp = A[i];
		A[i] = A[Max];
		A[Max] = temp;
		heapify(A, N, Max);
	}
}
/****************************************************
 * Uses heapsort to sort A[0..N]
 * NOTICE: The first element is in A[0] not in A[1]
 ****************************************************/
void HeapSort(int A[], int N) {
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(A, N, i);
	int temp = 0;
	for (int i = N - 1; i > 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapify(A, i, 0);
	}
} //end-HeapSort

/****************************************************
 * Uses radixsort to sort A[0..N]
 ****************************************************/
void RadixSort(int A[], int N) {
	int mul = 1;
	int max = getMax(A, N);//Max fonksiyonu çaðýrýlýr.
	while (max)
	{
		CountingSort(A, N); //Counting sort kullanýlarak radix sortun basamak bazlý implementasyonu gerçekleþtirilir.
		mul *= 10;
		max /= 10;
	}
} //end-RadixSort

/****************************************************
 * Uses countingsort to sort A[0..N]
 ****************************************************/
void CountingSort(int A[], int N)
{
	int i, j, k;
	int index = 0;
	int min, max;
	min = max = A[0];
	for (i = 1; i < N; i++)
	{
		min = (A[i] < min) ? A[i] : min;
		max = (A[i] > max) ? A[i] : max;
	}
	k = max - min + 1;
	int* B = new int[k];
	for (i = 0; i < k; i++)
		B[i] = 0;
	for (i = 0; i < N; i++)
		B[A[i] - min]++;
	for (i = min; i <= max; i++)
		for (j = 0; j < B[i - min]; j++)
			A[index++] = i;
	delete[] B;
} //end-CountingSort
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int A[], int N)
{
	if (N <= 1) return 0;

	int pivot = A[0]; //Pivot ilk eleman seçilir
	int i = 1, j = N - 1;

	while (1) {
		while (A[j] > pivot) //Sondan baþlayarak pivottan küçük olmayan elemanlar gezilir.
			j--;
		while (A[i] < pivot && i < j) //Baþtan baþlayarak pivottan büyük olmayan elemanlar gezilir.
			i++;
		if (j <= i)
			break; //Son ve baþtaki iþaretçilerimiz ayný olduðunda iþlem biter.

		swap(&A[i], &A[j]); //Yukarudaki durumlarý saðlamayan elemanlar swap edilir.
		i++;
		j--;
	}
	swap(&A[0], &A[j]); //Saðýnda küçükler solunda büyükler olacak þekilde pivot ortaya getirilir.
	return j;
}
int getMax(int A[], int N) {
	int max = A[0];
	for (int i = 1; i < N; i++)
		if (A[i] > max)
			max = A[i];
	return max;
}
