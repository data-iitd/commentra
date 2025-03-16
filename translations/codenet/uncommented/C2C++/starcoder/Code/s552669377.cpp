#include<iostream>
using namespace std;

int main(void){
int i,n,tmp;
long long int min=1000000,max=-1000000,sum=0;

cin>>n;
	
for(i=0;i<n;i++){
cin>>tmp;
if(min>tmp)min=tmp;
if(max<tmp)max=tmp;
sum+=tmp;
}

cout<<min<<" "<<max<<" "<<sum<<endl;

return 0;
}

