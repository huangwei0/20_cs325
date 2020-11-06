/*********************************************
Name: Wei Huang
Project: hw5.cpp
Data: winter2020
reference:
https://www.chegg.com/homework-help/questions-and-answers/implement-c-program-suppose-two-types-professional-wrestlers-babyfaces-good-guys-heels-bad-q24851404
https://www.chegg.com/homework-help/questions-and-answers/c-language-suppose-two-types-professional-wrestlers-babyfaces-good-guys-heels-bad-guys--pa-q34916794
http://www.cplusplus.com/reference/map/map/
**********************************************/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 100010
vector<int> adj[SIZE];
int babyfaces[SIZE];
bool visited[SIZE];

bool bfs(int,int);

int main(int argc, char * args[]){
   int n, u, v, r;
   string babyname, rival1, rival2;
   bool possible = 1;
   map<string, int> data;

   //reade the file name
   ifstream file(args[1]);
   if (!file) {
       cout << "Error opening\n";
       return 0;
   }

   //read the the number of wrestlers.
   file >> n;
   string names[n + 1];
   for (int i = 0; i<n; i++){
       file >> babyname;
       data[babyname] = i;
       names[i] = babyname;
   }

   //read the the number of rivalries
   file >> r;
   for (int i = 0;i < r;i++){
       file >> rival1 >> rival2;
       u = data[rival1];
       v = data[rival2];
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   //close the file.
   file.close();


   memset(babyfaces, 0, sizeof babyfaces);
   memset(visited, 0, sizeof visited);
   babyfaces[0] = 0;
   for (int i = 0;i < n;i++){
       if (visited[i])
           continue;

       possible = bfs(i, 0);
       if (!possible)
           break;
   }
   if (!possible){
       cout << "No" << endl;
   }
   else{
       vector<string> faces, heels;

       for (int i = 0;i < n;i++){
           if (babyfaces[i])
               faces.push_back(names[i]);
           else
               heels.push_back(names[i]);
       }
       //print
       cout << "Yes\n";
       cout << "Babyfaces: ";
       for (int i = 0;i<faces.size();i++)
           cout << faces[i] << " ";
       cout << endl;
       cout << "Heels: ";
       for (int i = heels.size() - 1;i >= 0;i--)
           cout << heels[i] << " ";
       cout << endl;
   }

   return 0;
}

//checks if the graph of rivalries list is bipartite or not
bool bfs(int pos, int parent){
   visited[pos] = 1;
   int i, value;
   babyfaces[pos] = 1 - babyfaces[parent];
   for (i = 0;i<adj[pos].size();i++){
       value = adj[pos][i];
       if (!visited[value]){
           bfs(value, pos);
       }
       else{

           if (babyfaces[value] == babyfaces[pos])
               return false;
       }
   }
   return true;

}
