#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, L, R, QL, QR, i, j, sum_el, energy, answer;
    scanf("%d %d %d %d %d", &n, &L, &R, &QL, &QR);
    int *W = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &W[i]);
    sum_el = 0;
    for(i = 0; i < n; i++)
    {
        sum_el += W[i];
        W[i] = sum_el;
    }
    answer = QR * (n - 1) + W[n - 1] * R;
    for(i = 1; i < n; i++)
    {
        energy = L * W[i] + R * (W[n - 1] - W[i]);
        if(i > (n - i))
            energy += (i - (n - i) - 1) * QL;
        else
            energy += ((n - i) - i - 1) * QR;
        if(energy < answer)
            answer = energy;
    }
    printf("%d", answer);
    return 0;
}

