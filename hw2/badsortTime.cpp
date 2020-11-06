/**********************************************
Name: Wei Huang
project: stoogeSorttime
date: 1/21/20
reference:
https://oregonstate.instructure.com/courses/1750806/pages/hw-1-problem-4-help-video?module_item_id=19313804
https://www.chegg.com/homework-help/questions-and-answers/using-c-modify-code-collect-running-time-data-call-new-timing-program-badstoogesort-instea-q43903378
**********************************************/
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

// bad sort by α = 2/3
void badSort(int arr[], int start, int end){
  int size = end - start+1;
  if (size == 2){
    if (arr[start] > arr[end]){
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
    }
  }
    else if (size > 2)
  {
    int point = size/3;
    badSort(arr, start, end - point);
    badSort(arr, start+point, end);
    badSort(arr, start, end - point);
  }
}

//print the time cost of the badSort, I set input for this peokject because the programn will run much time. I can input the small array size that make the program run short.
int main(){
  int n;
  clock_t time_req;
  cout<<" Enter array size: ";
  cin >> n;
  int array[n];
  srand(time(NULL));
  for(int i = 0;i<n;i++){
    array[i] = rand()/1000000;
  }
  time_req = clock();
  badSort(array, 0, n);
  time_req = clock()- time_req;
  cout<<"array size is: "<<n<<" , it took "<< (float)time_req/CLOCKS_PER_SEC<<" sec"<<endl;


return 0;
}
