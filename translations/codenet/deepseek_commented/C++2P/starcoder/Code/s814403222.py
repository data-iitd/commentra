
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,string> P;
P v[22]; // Array to store n pairs
vector<int> d[33]; // Vector of vectors to store indices

int main(void){
  int n;
  while(cin >> n && n){ // Read n until it is zero
    int m;
    for(int i = 0; i < 33; i++) d[i].clear(); // Clear all vectors in d
    for(int i = 0; i < n; i++){ // Read m for each element
      v[i].first = 0; // Initialize the first element of v to 0
      cin >> v[i].second >> m; // Read the string and m
      for(int j = 0; j < m; j++){ // For each m, read an integer and update v and d
	int a;
	cin >> a;
	v[i].first += n - (int)d[a].size(); // Update the first element of v
	for(int k = 0; k < (int)d[a].size(); k++){ // Update the first elements of other v elements
	  v[d[a][k]].first--;
	}
	d[a].push_back(i); // Store the index of the current element in d
      }
    }
    sort(v,v+n); // Sort the array v based on the first element of P
    cout << v[0].first << " " << v[0].second << endl; // Output the first element of v
  }
}

