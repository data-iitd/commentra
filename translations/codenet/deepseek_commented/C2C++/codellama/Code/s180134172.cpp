#include<iostream>
using namespace std;
int main(){
    int n,k,p[99999],i,j,l,m,o=0;
    // Read the number of elements (n) and the number of elements to sum (k)
    cin>>n>>k;
    // Read n integers and store them in the array p
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    // Perform selection sort on the array p
    for(i=0;i<n;i++){
        l=i;
        for(j=i+1;j<n;j++){
            if(p[j]<p[l]){
                l=j;
            }
        }
        if(l!=i) {
            m=p[i];
            p[i]=p[l];
            p[l]=m;
        }
    }
    // Sum the first k elements of the sorted array
    for(i=0;i<k;i++){
        o +=p[i];
    }
    // Print the sum of the first k elements
    cout<<o<<endl;
    return(0);
}
