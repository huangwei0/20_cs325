/**********************************************
Name: Wei Huang
project: stoogeSort
date: 1/21/20
reference:
https://www.tutorialspoint.com/cplusplus-program-to-perform-stooge-sort
**********************************************/
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//bad sort is used stooge sort algorithm to make the integers in data.text have a correct sequence.
void badSort(int a[],int start, int end) {
   int temp;
   if(end-start+1 > 2) {
      temp = (end-start+1)/3;
      badSort(a, start, end-temp);
      badSort(a, start+temp, end);
      badSort(a, start, end-temp);
   }
   if(a[end] < a[start]) {
      temp = a[start];
      a[start] = a[end];
      a[end] = temp;
    }
}


int main(){
  string line;
  int size =0;
  int* array_size;
  int* array;
  int j=0;

//open the file
  ifstream fp;
  ofstream fpw;

//read data.txt
  fp.open("data.txt");
  //find the array size in the file, and check the file open
  if(fp.is_open()){
    while(getline(fp, line)){
      size ++;
    }
      array_size = new int [size];
  }
 else{
    cout<<"error open file"<<endl;
    exit(1);
  }
  fp.close();
  fp.clear();
  fp.open("data.txt");
  fpw.open("bad.out");
// get the array from the file and input the correct sequence in the bad.out, and check the file open
  if(fp.is_open()){
    while(size>=0){
      fp>>array_size[j];
      array =new int[array_size[j]];
      for(int i=0;i<array_size[j];i++){
        fp>> array[i];
        }
        badSort(array,0,array_size[j]-1);
      for(int i=0;i<array_size[j];i++){
        fpw <<array[i]<<" ";
      }
      if(size !=0){
        fpw<< '\n';
      }
      delete array;
      j++;
      size--;
    }
  }
  else{
    cout<<"error open file"<<endl;
    exit(1);
  }
  //clear the space
delete array_size;

  fp.close();
  fpw.close();

  return 0;
}
