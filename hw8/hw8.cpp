#include<iostream>
using namespace std;
using std::ifstream;

using std::string;

using std::vector;

void swapping(int &a,int &b){
  int t=a;
  a=b;
  b=t;
}

int partitioned(int arr[],int l,int h){
  int p=h,i=l,j=l-1;
  while(i<p){
    if(arr[i]>arr[p]){
      j++;
      swapping(arr[i],arr[j]);
      i++;
    }
    else{
      i++;
    }
  }
  j++;
  swapping(arr[p],arr[j]);
  return j;
}

void quicksort(int *a,int low,int high){
  int pivot;
  if(low<high){
    pivot=partitioned(a,low,high);
    quicksort(a,low,pivot-1);
    quicksort(a,pivot+1,high);
  }
}

int firstfit(int arr[] ,int size ,int capacity){
  int bin[size];
  for(int i=0;i<size;i++)bin[i]=capacity;
  bin[0]-=arr[0];
  int j=0,k;
  for(int i=1;i<size;i++){
    for( k=0;k<=j;k++){
      if(bin[k]>=arr[i]){
        bin[k]-=arr[i];
        break;
      }
    }
    if(k==j+1){
      j++;
      if(bin[j]>=arr[i]) bin[j]-=arr[i];
    }
  }
  return j+1;
}

int main(){
  ifstream dataval;

  string pathval = "bin.txt";

  dataval.open(pathval.c_str());

  vector<int> item_Weight_Vector;

  int test_case_count = 1;

  int test_case_num = 0;

  int capacityval = 0;

  int item_num = 0;

  int item_weight = 0;

  while (dataval >> test_case_num)

  {

  for (int i = 0; i < test_case_num; i++)

  {

  dataval >> capacityval;

  dataval >> item_num;

  for (int i = 0; i < item_num; i++)

  {

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

  // int t,n,c;
  // cin>>t;
  // int j=1;
  // while(j<=t){
  //   cin>>c>>n;
  //   int arr[n];
  //   for(int i=0;i<n;i++)
  //   cin>>arr[i];
  //   cout<<"testcase "<< j <<" : ";
  //   cout<<"FirstFit : "<<firstfit(arr,n,c)<<" ";
  //   quicksort(arr,0,n-1);
  //   cout<<"FirstFitDecreasing : "<<firstfit(arr,n,c)<<"\n";
  //   j++;
  // }
  return 0;
}
