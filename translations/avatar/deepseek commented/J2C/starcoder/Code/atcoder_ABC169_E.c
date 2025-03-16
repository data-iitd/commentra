
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Declare and initialize a constant integer
    int num = 998244353;
    
    // Create a BufferedReader object to read input from the standard input
    BufferedReader bf = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
    
    // Create a PrintWriter object to write output to the standard output
    PrintWriter out = new PrintWriter ( System.out ) ; 
    
    // Read the number of elements 'n' from the input
    int n = Integer.parseInt ( bf.readLine ( ) ) ; 
    
    // Create two ArrayList objects to store the pairs of integers
    ArrayList < Integer > ai = new ArrayList < Integer > ( ) ; 
    ArrayList < Integer > bi = new ArrayList < Integer > ( ) ; 
    
    // Read the pairs of integers from the input and store them in the ArrayList objects
    for ( int i = 0 ; i < n ; i ++ ) { 
        StringTokenizer st = new StringTokenizer ( bf.readLine ( ) ) ; 
        ai.add ( Integer.parseInt ( st.nextToken ( ) ) ) ; 
        bi.add ( Integer.parseInt ( st.nextToken ( ) ) ) ; 
    } 
    
    // Sort both the ArrayList objects
    Collections.sort ( ai ) ; 
    Collections.sort ( bi ) ; 
    
    // Check if 'n' is odd or even
    if ( n % 2 == 1 ) { 
        // If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
        out.println ( bi.get ( bi.size ( ) / 2 ) - ai.get ( ai.size ( ) / 2 ) + 1 ) ; 
        out.close ( ) ; 
    } else { 
        // If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
        double b = ( ai.get ( ai.size ( ) / 2 ) + ai.get ( ai.size ( ) / 2 - 1 ) + 0.0 ) / 2 ; 
        double c = ( bi.get ( bi.size ( ) / 2 ) + bi.get ( bi.size ( ) / 2 - 1 ) + 0.0 ) / 2 ; 
        out.println ( ( int ) ( 2 * ( c - b ) + 1 ) ) ; 
        out.close ( ) ; 
    } 
    return 0;
}

