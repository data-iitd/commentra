#include<iostream>
using namespace std;

// Declare variables
int W, H, x, y, r;

int main(){
	// Read input values from user
	cin>>W>>H>>x>>y>>r;

	// Check if point is inside the rectangle or not
	if(x-r<0 || x+r>W || y-r<0 || y+r>H){
		// If point is outside the rectangle
		cout<<"No"<<endl;
	}
	else if(x-r>=0 && x+r<=W && y-r>=0 && y+r<=H){
		// If point is inside the rectangle
		cout<<"Yes"<<endl;
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}