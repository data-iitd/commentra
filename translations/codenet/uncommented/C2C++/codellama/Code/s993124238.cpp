#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,d;
	cin >> n >> d;
	int point[n+1][d+1];
	
	for (int i=1;i<=n ; i++){
		for (int j=1; j<=d; j++){
			cin >> point[i][j];
		}
	}
	
	int count=0;
	for (int i=1; i<=n-1; i++){
		for (int j=i+1; j<=n; j++){
			
			int sum=0;
			for (int k=1; k<=d; k++){
				sum = sum+ (point[i][k] - point[j][k])*(point[i][k] - point[j][k]);
			}
			double kyori = sqrt(sum);
			if (ceil(kyori) == floor(kyori)){
				count++;
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}

