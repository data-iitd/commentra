#include<iostream>
using namespace std;

bool search(int A[],int n,int key){
    int i=0;
    // Add the key to the end of the array to handle the case where the key is not found
    A[n]=key;
    // Loop until the key is found in the array
    while(A[i]!=key) i++;
    // Return 1 if the key is found, otherwise return 0
    return i!=n;
}

int main(void){
    int n,A[10000+1],q,key,sum=0;
    int i;
    
    // Read the size of the array
    cin>>n;
    // Read the array elements
    for(i=0;i<n;i++) cin>>A[i];
    // Read the number of queries
    cin>>q;
    // Process each query
    for(i=0;i<q;i++){
	cin>>key;
	// Perform the search operation for the current query element
	if(search(A,n,key)) sum++;
    }
    // Print the count of successful searches
    cout<<sum<<endl;

    return 0;
}
