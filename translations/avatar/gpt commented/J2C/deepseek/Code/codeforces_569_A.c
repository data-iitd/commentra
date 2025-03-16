#include <stdio.h>

int main() {
    int T, S, q;
    scanf("%d %d %d", &T, &S, &q);
    
    double previous = S;
    int answer = 0;
    
    while (previous < T) {
        answer++;
        previous *= q;
    }
    
    printf("%d\n", answer);
    return 0;
}
