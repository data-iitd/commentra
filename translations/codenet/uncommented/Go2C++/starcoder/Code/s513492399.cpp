#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b, a%b);
}

int main(){
   int k, a, b, c, ans=0;
   cin>>k;
   for(a=1;a<=k;a++){
     for(b=1;b<=k;b++){
       for(c=1;c<=k;c++){
         ans+=gcd(a, gcd(b, c));
       }
     }
   }
   cout<<ans<<endl;
}

