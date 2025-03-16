
#include<stdio.h>

int main(){
    // Declare variables to store the dimensions of the rectangle and the circle
    int W, H, x, y, r;
    
    // Read the dimensions of the rectangle and the circle from the input
    scanf("%d %d %d %d %d", &W, &H, &x, &y, &r);
    
    // Check if the circle is outside the rectangle
    if(x - r < 0 || x + r > W || y - r < 0 || y + r > H){
        // If any part of the circle is outside the rectangle, print "No"
        printf("No\n");
    }
    else {
        // If the circle is completely inside the rectangle, print "Yes"
        printf("Yes\n");
    }
    
    // End of the main function
    return 0;
}
