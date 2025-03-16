#include <iostream>

using namespace std;

int main()
{

int a[10000], min, max, n, i;
long long sum = 0;
cin >> n;
for(i = 0; i < n; i++){
 cin >> a[i];
 sum += a[i];
 }
 max = min = a[0];
for(i = 1; i < n; i++){
if(a[i] > max)max = a[i];
 if(a[i] < min)min = a[i];
 }
 cout << min << " " << max << " " << sum << endl;

 return 0;
}

