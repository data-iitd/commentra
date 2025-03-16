
#include<iostream>
using namespace std;
int main(){
    int n,k,p[99999],i,j,l,m,o=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>p[i];
    }
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
    for(i=0;i<k;i++){
        o +=p[i];
    }
    cout<<o<<endl;
    return 0;
}
