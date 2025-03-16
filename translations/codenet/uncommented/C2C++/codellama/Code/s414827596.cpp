#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int a,b,c,d,e,f;
	double x,y;
	while(cin>>a>>b>>c>>d>>e>>f){
		y = (double)(c*d-f*a)/(b*d-e*a);
		x = (double)(c*e-f*b)/(a*e-d*b);
		if(y<=0&&y>-0.0005)y=0;
		if(x<=0&&x>-0.0005)x=0;
		cout<<fixed<<setprecision(3)<<x<<" "<<y<<endl;
	}
	return 0;
}

