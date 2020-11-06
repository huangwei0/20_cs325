/************************************
Project: mergesort.cpp hw1
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
#include <string>

using namespace std;

//mergesort algorithms
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
  int arr_size = 0;
  int num;
  int arr[100];

  ifstream fp;
  fp.open("data.txt");
  ofstream fpw;
  fpw.open("merge.out");

  fp >> num;
  while(fp >>arr[arr_size] ){
    if(arr_size>num){
      break;
    }
    arr_size++;
  }
  fp.close();

  merge_sort(arr,0,arr_size-1);
  if (fpw.is_open())
  {
     for(int i = 0; i < arr_size; i ++){
     fpw << arr[i] << " " ;
         }
  fpw.close();
     }
  return 0;
}
