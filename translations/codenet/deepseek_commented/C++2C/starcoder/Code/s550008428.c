#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <fenv.h>

int main(){
    int s, x, d=2; 
    scanf("%d", &s); // Read the initial number from the user
    set<int> a;
    a.insert(s); // Insert the initial number into the set

    while(1) { // Start an infinite loop
        if(s%2==0){ // Check if the current number is even
            x = s/2; // Halve the number
            if(a.find(x)!=a.end()) { // Check if the halved number has been encountered before
                printf("%d\n", d); // Output the current step count and terminate the program
                return 0;
            }
            a.insert(x); // Insert the halved number into the set
        } else { // The current number is odd
            x = 3*s + 1; // Triple the number and add one
            if(a.find(x)!=a.end()) { // Check if the new number has been encountered before
                printf("%d\n", d); // Output the current step count and terminate the program
                return 0;
            }
            a.insert(x); // Insert the new number into the set
        }
        s = x; // Update the current number to the new number
        d++; // Increment the step count
    }

    printf("%d\n", d); // Output the step count (this line will never be reached)

    return 0;
}

