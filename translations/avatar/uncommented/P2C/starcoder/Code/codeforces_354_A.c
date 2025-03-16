#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, L, R, QL, QR, i, j, sum_el[1000001], answer;
    scanf("%d %d %d %d %d", &n, &L, &R, &QL, &QR);
    int W[n];
    for(i=0; i<n; i++)
        scanf("%d", &W[i]);
    sum_el[0] = 0;
    for(i=1; i<=n; i++)
        sum_el[i] = W[i-1] + sum_el[i-1];
    answer = QR*(n-1) + sum_el[n]*R;
    for(i=1; i<=n; i++)
    {
        int energy = L*sum_el[i] + R*(sum_el[n]-sum_el[i]);
        if(i>(n-i))
            energy = energy + (i-(n-i)-1)*QL;
        else if((n-i)>i)
            energy = energy + ((n-i)-i-1)*QR;
        if(energy<answer)
            answer = energy;
    }
    printf("%d", answer);
    return 0;
}
