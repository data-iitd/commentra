#include <iostream>
using namespace std;

int main() {
	
	int n, i, j, q, x[10000], y[500], sum = 0;
	
	cin >> n;
	
	for( i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	cin >> q;
	
	for( i = 0; i < q; i++) {
		cin >> y[i];
	}
	
	for( i = 0; i < q; i++) {
		for( j = 0; j < n; j++) {
			if( y[i]==x[j]) {
			sum = sum + 1;
			break ;
			}
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
