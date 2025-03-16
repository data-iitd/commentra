// Header Files and Preprocessor Directives
#include <bits/stdc++.h>

// Global Variables
using namespace std;
int n;
int a[1000][999];
int e1[1000000];
int e2[1000000];
int d[1000000];
bool b[1000000];

// Function Definitions
int p(int a, int b){
	if(a<b){
		return a+b*n;
	}else{
		return b+a*n;
	}
}

int f(int from){
	if(b[from]) return -1; // If node is already visited, return -1 indicating a cycle
	if(d[from]) return d[from]; // If distance is already calculated, return it
	b[from]=true; // Mark the node as visited
	int to;
	to = e1[from];
	int max=0;
	if(to!=0){
		int now=f(to); // Recursively find the longest path from 'to'
		if(now<0) return now; // If there's a cycle, return -1
		if(now>max) max=now; // Update max if a longer path is found
	}
	to = e2[from];
	if(to!=0){
		int now=f(to); // Recursively find the longest path from 'to'
		if(now<0) return now; // If there's a cycle, return -1
		if(now>max) max=now; // Update max if a longer path is found
	}
	b[from]=false; // Unmark the node as visited (backtracking)
	return d[from]=max+1; // Store and return the longest path length
}

// Main Function
int main(void){
	cin>>n; // Read the size of the problem
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			cin>>a[i][j]; // Read and adjust indices to be 0-based
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n-2; j++){
			int from = p(i, a[i][j]); // Create a unique node index 'from'
			int to = p(i, a[i][j+1]); // Create a unique node index 'to'
			if(e1[from]==0){
				e1[from]=to; // Assign 'to' to e1 of 'from'
			}else if(e2[from]==0){
				e2[from]=to; // Assign 'to' to e2 of 'from'
			}else{
				cout<<-1<<endl; // If both e1 and e2 are already assigned, print -1 and exit
				return 0;
			}
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		int from = p(i, a[i][0]); // Create a unique starting node index 'from'
		int now=f(from); // Find the longest path from 'from'
		if(now<0){
			ans=-1; // If there's a cycle, set ans to -1
			break;
		}
		if(now>ans) ans=now; // Update ans if a longer path is found
	}
	cout<<ans<<endl; // Print the result
}

