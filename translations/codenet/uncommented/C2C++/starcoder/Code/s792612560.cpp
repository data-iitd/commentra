#include <iostream>
using namespace std;

int main(void) {
	int n;
	unsigned long long int m;
	cin>>n;
	m=n;
	n--;
	for(;n>1;n--) {
		m*=n;
	}
	cout<<m<<endl;
	return 0;
}
