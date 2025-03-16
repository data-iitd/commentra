#include<iostream>

using namespace std;
const int MAX_N=1e3; // Define the maximum size of the array
int data[MAX_N]; // Declare the array to store the data

int main(){
	int m, nmi, nma;
	while(cin>>m>>nmi>>nma && nmi!=0){ // Read the values of m, nmi, and nma, and continue until nmi is 0
		for(int i=0;i<m;i++)cin>>data[i]; // Read m integers into the array data
		int ma=0; // Initialize the maximum difference to 0
		int ans=0; // Initialize the answer index to 0
		for(int i=nmi-1;i<nma;i++){ // Loop through the range from nmi-1 to nma-1
			if(ma<=data[i]-data[i+1]){ // Check if the current difference is greater than the maximum difference found so far
				ans=i+1; // Update the answer index
				ma=data[i]-data[i+1]; // Update the maximum difference
			}
		}
		cout<<ans<<endl; // Print the answer index
	}
}