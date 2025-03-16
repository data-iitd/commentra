#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,string> P;
P v[22]; // Array to store n pairs
vector<int> d[33]; // Vector of vectors to store indices

def main(void):
  n = 0
  while(cin >> n and n): # Read n until it is zero
    m = 0
    for i in range(33): d[i].clear() # Clear all vectors in d
    for i in range(n): # Read m for each element
      v[i].first = 0 # Initialize the first element of v to 0
      cin >> v[i].second >> m # Read the string and m
      for j in range(m): # For each m, read an integer and update v and d
	a = 0
	cin >> a # Read the integer
	v[i].first += n - len(d[a]) # Update the first element of v
	for k in range(len(d[a])): # Update the first elements of other v elements
	  v[d[a][k]].first -= 1
	d[a].append(i) # Store the index of the current element in d
    sort(v,v+n) # Sort the array v based on the first element of P
    print v[0].first, v[0].second # Output the first element of v
  return 0

