/************************************
Project: insertsort.cpp hw1
Name : Wei Huang
Course: cs 325
Data:winter 2020
*************************************/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//insertSort algorithms
void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
	key = arr[i];
	j = i-1;
	while (j >= 0 && arr[j] > key){
	arr[j+1] = arr[j];
	j = j-1;
	}
	arr[j+1] = key;
	}
}


// read the  sequence integers from the data.txt, and input correct sequence the insert.out
int main(){
	int arr[1000];
	ifstream fp;
	fp.open("data.txt");
	ofstream fpw;
	fpw.open("insert.out");
	fpw << "Sorted array Using INSERT SORT is"<<endl;
	for(int i = 0; i < 3; i++){
			int arr_size = 0;
		fp >> arr_size;
		for(int j = 0; j < arr_size; j++){
			fp >> arr[j];
		}
		insertionSort(arr,arr_size);

		for(int i = 0; i <arr_size; i++){
			fpw << arr[i] << " ";
		}
		fpw <<endl;
	}
	fp.close();
  fpw.close();
 return 0;
}
