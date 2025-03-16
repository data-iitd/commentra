#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // For descending order
}

int main() {
    int N;
    scanf("%d", &N);
    int size = 1 << N;
    int *S = (int *)malloc(size * sizeof(int));
    bool *spawned = (bool *)malloc(size * sizeof(bool));
    
    spawned[size - 1] = true;
    for (int i = 0; i < size; i++) {
        scanf("%d", &S[i]);
    }
    
    qsort(S, size, sizeof(int), compare);
    
    int *active = (int *)malloc(size * sizeof(int));
    int active_count = 0;
    active[active_count++] = S[size - 1];
    
    for (int i = 0; i < N; i++) {
        // Sort active in descending order
        qsort(active, active_count, sizeof(int), compare);
        
        int *activated = (int *)malloc(size * sizeof(int));
        int activated_count = 0;
        int next = size - 1;
        
        for (int j = 0; j < active_count; j++) {
            int slime = active[j];
            while (next >= 0 && (S[next] >= slime || spawned[next])) {
                next--;
            }
            if (next < 0) {
                printf("No\n");
                free(S);
                free(spawned);
                free(active);
                free(activated);
                return 0;
            }
            spawned[next] = true;
            activated[activated_count++] = S[next];
        }
        
        for (int j = 0; j < activated_count; j++) {
            active[active_count++] = activated[j];
        }
        
        free(activated);
    }
    
    printf("Yes\n");
    
    free(S);
    free(spawned);
    free(active);
    
    return 0;
}
