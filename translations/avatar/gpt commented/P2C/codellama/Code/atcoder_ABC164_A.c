#include <stdio.h>

int main()
{
    // Read two integers from input: S (the strength) and W (the weight)
    int S, W;
    scanf("%d %d", &S, &W);
    
    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    if (S <= W)
        printf("unsafe\n");
    else
        printf("safe\n");
    
    return 0;
}

