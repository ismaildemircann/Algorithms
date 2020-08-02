#Algorithms
## [1) Long Integer Multiplication with Karatsuba Algorithm](https://github.com/ismaildemircann/Algorithms/blob/master/README.md#1-long-integer-multiplication-with-karatsuba-algorithm-1)
## [2) Sorting Algorithms](https://github.com/ismaildemircann/Algorithms/blob/master/README.md#2-sorting-algorithms-1)
## [3) Authors](https://github.com/ismaildemircann/Algorithms/blob/master/README.md#3-authors-1)

## 1) Long Integer Multiplication with Karatsuba Algorithm
In this project you are asked to implement the divide-and-conquer long integer multiplication algorithm, whose running time is O(n1.58).
Your program will first prompt for N, the number of digits that each integer has. Then the program will
prompt for the name of the file where the first integer is stored, then prompt for the name of the file
where the second integer is stored. It will then multiply the integers using the divide-and-conquer long
integer multiplication algorithm and write the result to a file named “result.txt”. Here is a typical
interaction between the user and your program:

![Figure1](https://github.com/ismaildemircann/Algorithms/blob/master/KaratsubaAlgorithm/images/Figure1.png)

The first digit in the file represents the least significant digit of the number, and the last digit represents
the most significant digit. That means that if A.txt contains “123456”, this represents the decimal number
654321 and not 123456. The result must also be written with the least significant digit first.



x = 7854

y = 6912
 
[78][54]
a = 78
 b = 54

[69][12]
c = 69
 d = 12

x = 10^(n/2) * a + b or 7800 + 54

y = 10^(n/2) * c + d or 6900 + 12

x * y = (10^(n/2) * a + b) * (10^(n/2) * c + d)

= 10^(n)*ac + 10^(n/2)(ad + bc) + bd


## 2) Sorting Algorithms

* Bubble Sort

* Selection Sort

* Insertion Sort

* Merge Sort

* Quick Sort

* Heap Sort

* Radix Sort

* Counting Sort

## 3) Authors
* [Eda Çam](https://github.com/edacaam)
* [İsmail Demircan](https://github.com/ismaildemircann)
