
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Define a constant for array or list size
    const int NUM = ( int ) ( 1e5 + 2 ) ; 
    
    // Initialize a Scanner object to read input
    int N = 0 ; 
    scanf("%d", &N);
    
    // Initialize a HashMap to store value and its index
    int *map = ( int * ) malloc ( sizeof ( int ) * NUM ) ; 
    memset ( map, 0, sizeof ( int ) * NUM ) ; 
    
    // Initialize a PriorityQueue to store numbers
    int *nums = ( int * ) malloc ( sizeof ( int ) * NUM ) ; 
    memset ( nums, 0, sizeof ( int ) * NUM ) ; 
    
    // Read each number, add it to the PriorityQueue, and store its value and index in the HashMap
    for ( int i = 0 ; i < N ; i ++ ) { 
        int tmp = 0 ; 
        scanf("%d", &tmp);
        nums[i] = tmp ; 
        map[tmp] = i ; 
    } 
    
    // Initialize variables to keep track of the current index and the count of differences
    int bin = 0 ; 
    int diff = 0 ; 
    
    // Loop until the PriorityQueue is empty
    while (! nums[0] ) { 
        // Retrieve the next number and its index from the PriorityQueue and HashMap
        int num = nums[bin] ; 
        int idx = map[num] ; 
        
        // If the current index is not even when bin is even (or vice versa), increment the diff counter
        if ( ( bin % 2 )!= ( idx % 2 ) ) { 
            diff ++ ; 
        } 
        
        // Update bin and take modulo 2 to keep it within 0 or 1
        bin ++ ; 
        bin %= 2 ; 
    } 
    
    // Calculate the answer by dividing diff by 2
    int ans = ( diff / 2 ) ; 
    
    // Print the result
    printf("%d\n", ans);
    
    return 0;
}

