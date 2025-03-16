#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

int main ( ) {
    char sa[1000000];
    char sb[1000000];
    scanf ( "%s %s", sa, sb );
    int a = atoi ( sa );
    int b = atoi ( sb ) * 100 + 0.1;
    printf ( "%d", a * b / 100 );
    return 0;
}

