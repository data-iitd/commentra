#include<stdio.h>

int main(){
	// Read input values from user
	int W, H, x, y, r;
	scanf("%d %d %d %d %d", &W, &H, &x, &y, &r);

	// Check if point is inside the rectangle or not
	if(x-r<0 || x+r>W || y-r<0 || y+r>H){
		// If point is outside the rectangle
		printf("No\n");
	}
	else if(x-r>=0 && x+r<=W && y-r>=0 && y+r<=H){
		// If point is inside the rectangle
		printf("Yes\n");
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}

