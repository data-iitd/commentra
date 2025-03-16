#include<iostream>
using namespace std;

int search(int A[],int n,int key){
    int i=0;
    A[n]=key;
    while(A[i]!=key) i++;
    return i!=n;
}

int main(void){
    int n,A[10000+1],q,key,sum=0;
    int i;
    
    cin>>n;
    for(i=0;i<n;i++) cin>>A[i];
    cin>>q;
    for(i=0;i<q;i++){
	cin>>key;
	if(search(A,n,key)) sum++;
    }
    cout<<sum<<endl;

    return 0;
}
