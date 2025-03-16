#include <iostream>

using namespace std;

int main(void)
{
	int a,b,c,i,j,k;
	int max;

	// Step 1: Read the number of test cases (j) from the user input.
	cin>>j;

	for(i=0;i<j;i++){
		// Step 3: For each test case, read three integers (a, b, c).
		cin>>a;
		cin>>b;
		cin>>c;

		// Step 4: Determine the maximum of the three integers.
		max=a;
		k=0;
		if(max<=b){
			max=b;
			k=1;
		}
		if(max<=c){
			max=c;
			k=2;
		}

		// Step 5: Calculate the square of the maximum and the squares of a, b, and c.
		max=max*max;
		a=a*a;
		b=b*b;
		c=c*c;

		// Step 6: Check if the square of the maximum is equal to the sum of the squares of the other two integers.
		if(k==0 && max==b+c){
			cout<<"YES"<<endl;
		}
		else if(k==1 && max==a+c){
			cout<<"YES"<<endl;
		}
		else if(k==2 && max==a+b){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return (0);
}

