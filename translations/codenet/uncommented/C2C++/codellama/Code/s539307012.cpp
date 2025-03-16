#include<iostream>

int main(void){
	int n,x,min,m,i;
	std::cin>>n>>x>>min;
	x-=min;
	for(i=1;i<n;i++){
		std::cin>>m;
		x-=m;
		if(min>m){
			min=m;
		}
	}
	std::cout<<n+x/min<<std::endl;
	return 0;
}

