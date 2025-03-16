

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a pair type with first integer and second string
typedef struct {
  int first;
  string second;
} P;

// Initialize an array of pairs v with size n
P v[22];

// Initialize a vector of integers d with size 33
vector<int> d[33];

// Main function
int main(void){
  // Read the number of test cases n
  while(scanf("%d",&n) && n){
    // Initialize d array for each test case
    for(int i = 0; i < 33; i++) d[i].clear();
    
    // Process each test case
    for(int i = 0; i < n; i++){
      // Initialize the first element of pair v[i] as 0
      v[i].first = 0;
      
      // Read the name and number of students m for the current test case
      scanf("%s %d",v[i].second,&m);
      
      // For each student, read the number of absences a and update the scores accordingly
      for(int j = 0; j < m; j++){
	int a;
	// Read the number of absences a for the current student
	scanf("%d",&a);
	
	// Calculate the effect of the current student's absences on the scores of other students
	v[i].first += n - (int)d[a].size();
	
	// Update the scores of students who have the same number of absences as the current student
	for(int k = 0; k < (int)d[a].size(); k++){
	  // Decrease the score of the student whose index is in d[a] by 1
	  v[d[a][k]].first--;
	}
	
	// Add the index of the current student to the vector d[a]
	d[a].push_back(i);
      }
    }
    
    // Sort the pairs in the array v in ascending order based on their first elements
    sort(v,v+n);
    
    // Print the name and the highest score of the student with the highest score
    printf("%d %s\n",v[0].first,v[0].second.c_str());
  }
}
