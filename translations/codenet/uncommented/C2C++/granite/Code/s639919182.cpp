
#include <iostream>
using namespace std;
int main(void)
{
	int v[10];
	int sum=0;
	int i;
	
	for(i=0;i<10;i++)
	cin>>v[i];
	
	for(i=0;i<10;i++)
	sum+=v[i];
	
	cout<<sum<<endl;
	
	return 0;
}
