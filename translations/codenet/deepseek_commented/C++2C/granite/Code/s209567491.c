
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;math.h&gt;
#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;algorithm&gt;
#include &lt;string&gt;
#include &lt;functional&gt;
#include &lt;stack&gt;
#include &lt;queue&gt;
#include &lt;cstdio&gt;
#include &lt;cstdlib&gt;
#include &lt;cstring&gt;
#include &lt;list&gt;
#include &lt;set&gt;

int main(int argc, char *args[]) {
    int N, D, X;
    int num_of_chocolate;
    int counter;
    int days;
    int A[101];

    scanf("%d %d %d", &N, &D, &X);

    for (int i = 0; i &lt; N; i++) {
        scanf("%d", &A[i]);
    }

    num_of_chocolate = 0;
    for (int i = 0; i &lt; N; i++) {
        days = 0;
        counter = 0;
        for (int j = 0;; j++) {
            days = j * A[i] + 1;
            if (days &lt;= D) {
                counter++;
            }
            else {
                break;
            }
        }
        num_of_chocolate = num_of_chocolate + counter;
    }

    num_of_chocolate = num_of_chocolate + X;

    printf("%d\n", num_of_chocolate);

    return 0;
}

