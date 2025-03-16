#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <limits.h>

#define MAX_CHAR 1000000

int main()
{
    char s[MAX_CHAR];
    scanf("%s", s);
    int even[2] = {0};
    int odd[2] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        if (i % 2 == 0)
        {
            even[s[i] - '0']++;
        }
        else
        {
            odd[s[i] - '0']++;
        }
    }
    printf("%d", min(strlen(s) - (even[0] + odd[1]), strlen(s) - (even[1] + odd[0])));
    return 0;
}

