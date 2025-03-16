
#include<stdio.h>
#define N 2000
int num1,math[N+1];

// Initialize variables
int a, num2, ans, sum = 0;
int i, j;

// Initialize math array with first element as 1
math[0] = 1;

// Read the number of integers to be input
printf("Enter the number of integers to be input:\n");
scanf("%d",&num1);

// Read each integer and calculate its sum
for(i=0;i<num1;i++){
    printf("Enter an integer:\n");
    scanf("%d",&a);

    // Add the current integer to the sum
    sum += a;

    // Mark all the previous numbers as visited
    for(j=sum-a;j>=0;j--){
        if(math[j]==1) math[j+a] = 1;
    }
}

// Read the number of integers to be checked
printf("Enter the number of integers to be checked:\n");
scanf("%d",&num2);

// Check each integer and print the result
for(i=0;i<num2;i++){
    printf("Enter an integer to check:\n");
    scanf("%d",&ans);

    // Check if the current integer is marked as visited
    if(math[ans]==1) printf("yes\n");
    else printf("no\n");
}

// Return 0 to indicate successful execution
return 0;

