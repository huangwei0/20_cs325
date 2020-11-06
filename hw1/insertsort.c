//insertion sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *fp,*fpw;

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
  int i;
  for (i=0; i < n; i++)
    fprintf(fpw,"%d ", arr[i]);
  fprintf(fpw,"\n");

}

int main(){
  int arr[1000] = {0};
  size_t arr_size =0;
  int data;
  char file1[20];
  char line [256];
  strcpy(file1,"data.txt");
  fp = fopen(file1,"r+");
  if (fp == NULL){ // if file not opened return error
    perror("Unable to open file");
    return -1;
  }

  else{

    fscanf (fp, "%d", &data);
    arr[arr_size]=data;
    arr_size++;
    while (!feof(fp)){
      fscanf (fp, "%d", &data);
      arr[arr_size]=data;
      arr_size++;
      // arr[arr_size]=data;
      //
      // arr_size++;
    }

  }
  char file2[20];
  strcpy(file2,"insert.out");
  fpw = fopen(file2,"w");
  if (fpw == NULL){ // if file not opened return error
    perror("Unable to create file");
    return -1;
  }
  fprintf(fpw,"Given array is \n");
  printArray(arr, arr_size);
  insertionSort(arr, arr_size);
  fprintf(fpw,"\nSorted array Using INSERT SORT is \n");
  printArray(arr, arr_size);
  fclose(fpw);
  fpw=NULL;
  fp=NULL;

  return 0;

}
