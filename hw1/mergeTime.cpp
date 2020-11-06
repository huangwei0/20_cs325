/************************************
Project: mergeTime.cpp hw1
Name : Wei Huang
Course: cs 325
Data:winter 2020
reference: https://oregonstate.instructure.com/courses/1750806/pages/hw-1-problem-4-help-video?module_item_id=19313804
*************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int left, int mid, int right){
   int i, j, lower_half, upper_half;
   int temp[(right-left)+1];
   lower_half=left;
   upper_half=mid+1;
   for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
      if(arr[lower_half]<=arr[upper_half]){
	 temp[i]=arr[lower_half];
	 lower_half++;
      }
      else{
	 temp[i]=arr[upper_half];
	 upper_half++;
      }
   }
   if(lower_half>mid)
      for(j=upper_half;j<=right;j++, i++)
	 temp[i]=arr[j];
   else
      for(j=lower_half;j<=mid;j++, i++)
	 temp[i]=arr[j];

   for(j=0,i=left;i<=right;i++,j++)
      arr[i]=temp[j];
}

// repeat the merge sort algorithm
void merge_sort(int arr[], int left, int right) {
   int mid;
   if(left<right) {
      mid=(right+left)/2;
      merge_sort(arr, left, mid);
      merge_sort(arr, mid+1, right);
      merge(arr, left, mid, right);
   }
}

int main(){
const int N = 1000002;
int arr[N];
FILE * file1;
file1 =fopen("mergeTimesAvg.txt","w");
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
	merge_sort(arr,0,j);

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
