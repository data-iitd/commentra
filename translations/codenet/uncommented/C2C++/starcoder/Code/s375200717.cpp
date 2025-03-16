#include<iostream>
using namespace std;
int main(void){
    int n,i,a;
    cin>>n;
    for(i=1;i<=n;i++){
        a=i;
        if((a%3)==0){
            cout<<" "<<i;
        }else{
            for(;a;){
                if((a%10)==3){
                    cout<<" "<<i;
                    a=0;
                }
                a=a/10;
            }
        }
    }
    cout<<endl;
    return 0;
}
