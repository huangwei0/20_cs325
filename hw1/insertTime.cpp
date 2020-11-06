/************************************
Project: inserTime.cpp hw1
Name : Wei Huang
Course: cs 325
Data:winter 2020
reference: https://oregonstate.instructure.com/courses/1750806/pages/hw-1-problem-4-help-video?module_item_id=19313804
*************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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
void printArray(int arr[], int n){
  for(int i=0;i<n;i++)
    printf("%d", arr[i]);
  printf("\n");

}
int main(){
const int N = 1000002;
int arr[N];
FILE * file1;
file1 =fopen("InserTimesAvg.txt","w");
float total, average;

for(int j = 0; j<= 100000; j=j+10000){
	fprintf(file1, "%d", j);
	printf("%d", j);
	total = 0;
	average = 0;
	for(int k=1; k<=3; k++){
		srand(time(NULL));
		for(int i=0;i<j;i++){
			arr[i] = rand()% 1000;
		}
	clock_t t1,t2;
	t1=clock();
	insertionSort(arr,j);

	t2 = clock();
	float diff((float) t2 - (float) t1);
	float seconds = diff/ CLOCKS_PER_SEC;
	total =total+seconds;
	printf(" ,%f",seconds);
	fprintf(file1, "%f", seconds);
	}
	average = total/3;
	printf("average %f \n",average);
	fprintf(file1, "%f\n", average);
}
fclose (file1);
  return 0;
}
