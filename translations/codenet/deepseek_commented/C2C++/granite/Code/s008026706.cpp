
#include<iostream>

int main(){
	int a,b,x,y;
	
	// Step 4: Read two integers from the user.
	std::cin>>a>>b;
	
	// Step 5: Calculate the perimeter of a rectangle using the formula 2*a + 2*b and store it in x.
	x=2*a+2*b;
	
	// Step 6: Calculate the area of a rectangle using the formula a*b and store it in y.
	y=a*b;
	
	// Step 7: Print the area and perimeter.
	std::cout<<y<<" "<<x<<"\n";
	
	// Step 8: Return 0 to indicate successful execution.
	return 0;
}
