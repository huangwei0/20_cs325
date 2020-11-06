#include "sort.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

void mergevalue(vector<int>&list11, int p, int q, int r){
  int n1 = q - p + 1;
  int m1 = r - q;
  int L[n1];
  int R[m1];

  for (int i = 0; i < n1; i++){
    L[i] = list11[p + i];
  }

  for (int j = 0; j < m1; j++){
    R[j] = list11[q + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = p;

  while (i < n1 && j < m1){
    if (L[i] >= R[j]){
      list11[k] = L[i];
      i = i + 1;
    }
    else{
      list11[k] = R[j];
      j = j + 1;
    }
    k += 1;
  }

  while (i < n1){
    list11[k] = L[i];
    i += 1;
    k += 1;
  }

  while (j < m1){
    list11[k] = R[j];
    j += 1;
    k += 1;
  }

}

void sort(vector<int>& list11, int p, int r){
  if (p < r){
    int q = (p + r) / 2;
    sort(list11, p, q);
    sort(list11, q + 1, r);
    mergevalue(list11, p, q, r);
  }
}
