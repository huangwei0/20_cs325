#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sort.h"

#define CAPACITY 100
#define maximum_item 10000
#define maximum_weight 100
#define intervalvalue 1000

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int firstFit(int capacityval, vector<int> weights){
  vector<int> binsval;
  binsval.push_back(capacityval);
  for (int i = 0; i < weights.size(); i++){
    int fit = 0;
    for (int j = 0; j < binsval.size(); j++){
      if (weights[i] <= binsval[j]){
        binsval[j] -= weights[i];
        fit = 1;
        break;
      }
    }
    if (fit == 0){
      binsval.push_back(capacityval);
      binsval[binsval.size() - 1] -= weights[i];
    }
  }
  return binsval.size();
}


int main(){
// open bin file
  ifstream dataval;
  string pathval = "bin.txt";
  dataval.open(pathval.c_str());
  vector<int> item_Weight_Vector;
  int test_case_count = 1;
  int test_case_num = 0;
  int capacityval = 0;
  int item_num = 0;
  int item_weight = 0;

  while (dataval >> test_case_num){
    for (int i = 0; i < test_case_num; i++){
      dataval >> capacityval;
      dataval >> item_num;
      for (int i = 0; i < item_num; i++){
        dataval >> item_weight;
        item_Weight_Vector.push_back(item_weight);
      }

      int ff = firstFit(capacityval, item_Weight_Vector);

      sort(item_Weight_Vector, 0, item_Weight_Vector.size() - 1);
      // run first-fit-decreasing
      int ffd = firstFit(capacityval, item_Weight_Vector);
      cout << "Test Case " << test_case_count << " First Fit: " << ff << " - First Fit Decreasing: " << ffd << endl;
      item_Weight_Vector.clear();
      test_case_count += 1;
    }
  }

  cout << endl;
}
