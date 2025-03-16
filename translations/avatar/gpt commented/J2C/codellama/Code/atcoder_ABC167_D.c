#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 
#include <limits.h> 
#include <float.h> 
#include <assert.h> 
#include <stdint.h> 
#include <inttypes.h> 
#include <stddef.h> 
#include <stdarg.h> 
#include <errno.h> 
#include <ctype.h> 
#include <time.h> 
#include <sys/time.h> 
#include <sys/resource.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <dirent.h> 
#include <fcntl.h> 
#include <locale.h> 
#include <wchar.h> 
#include <wctype.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 
#include <limits.h> 
#include <float.h> 
#include <assert.h> 
#include <stdint.h> 
#include <inttypes.h> 
#include <stddef.h> 
#include <stdarg.h> 
#include <errno.h> 
#include <ctype.h> 
#include <time.h> 
#include <sys/time.h> 
#include <sys/resource.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <dirent.h> 
#include <fcntl.h> 
#include <locale.h> 
#include <wchar.h> 
#include <wctype.h> 

// Initialize scanner for input
struct scanner {
    FILE *fp;
    char *buf;
    int buf_size;
    int buf_len;
    int line;
    int col;
};

// Constants for modulo and limits
const int MOD = 1000000007; 
const int MAX = INT_MAX; 
const long LMAX = LONG_MAX; 

// Length for the array
int len = (int) 1e6 + 1; 

void doIt(struct scanner *sc) {
    // Read the number of elements N and the long value K
    int N = sc->nextInt(sc); 
    long K = sc->nextLong(sc); 
    
    // Initialize the array A to store the input values
    int A[N]; 
    
    // Read N integers into the array A and adjust values to be zero-indexed
    for (int i = 0; i < N; i++) { 
        A[i] = sc->nextInt(sc) - 1; 
    } 
    
    // Set to track used indices and arrays to store index and position
    int used[N]; 
    int idx[N]; 
    int pos[N]; 
    
    // Initialize variables for the cycle detection
    int next = 0, cur = 0; 
    
    // Detect the cycle in the array using the 'used' set
    while (!used[next]) { 
        used[next] = 1; 
        idx[next] = cur; 
        pos[cur] = next; 
        next = A[next]; 
        cur++; 
    } 
    
    // Calculate the lengths of the cycle and the position of the next element
    long a = (long) cur - idx[next]; 
    long b = (long) idx[next]; 
    
    // Calculate the answer based on the cycle length and K
    int ans = (int) ((10000 * a + K - b) % a + b); 
    
    // If b is greater than K, set ans to K
    if (b > K) ans = (int) K; 
    
    // Output the result, adjusting for 1-based indexing
    printf("%d\n", pos[ans] + 1); 
} 

int main(int argc, char *argv[]) { 
    // Create an instance of Main and call the doIt method
    struct scanner sc;
    sc.fp = stdin;
    sc.buf = NULL;
    sc.buf_size = 0;
    sc.buf_len = 0;
    sc.line = 1;
    sc.col = 1;
    doIt(&sc); 
    return 0; 
}

