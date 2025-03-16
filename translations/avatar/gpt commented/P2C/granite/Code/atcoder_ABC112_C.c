
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, h;
} Building;

char* solve(int n, Building* ls_xyh) {
    // Initialize the coordinates and height of the first building with a positive height
    int x0 = -1, y0 = -1, h0 = -1;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i].h > 0) {
            x0 = ls_xyh[i].x;
            y0 = ls_xyh[i].y;
            h0 = ls_xyh[i].h;
            break;
        }
    }
    
    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    Building* cands = (Building*)malloc(sizeof(Building) * 101 * 101);
    int cand_count = 0;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            cands[cand_count].x = cx;
            cands[cand_count].y = cy;
            cands[cand_count].h = h0 + abs(cx - x0) + abs(cy - y0);
            cand_count++;
        }
    }
    
    // Filter candidates based on the height constraints from the other buildings
    for (int i = 0; i < n; i++) {
        int x = ls_xyh[i].x, y = ls_xyh[i].y, h = ls_xyh[i].h;
        int new_cand_count = 0;
        for (int j = 0; j < cand_count; j++) {
            if (max(cands[j].h - abs(cands[j].x - x) - abs(cands[j].y - y), 0) == h) {
                cands[new_cand_count] = cands[j];
                new_cand_count++;
            }
        }
        cand_count = new_cand_count;
    }
    
    // Select the first valid candidate position and height
    int xx = cands[0].x, yy = cands[0].y, hh = cands[0].h;
    
    // Allocate memory for the result string and format it
    char* result = (char*)malloc(sizeof(char) * 30);
    sprintf(result, "%d %d %d", xx, yy, hh);
    
    // Free the memory allocated for the candidate positions
    free(cands);
    
    // Return the result string
    return result;
}

int main() {
    // Read input from standard input and parse the number of buildings and their properties
    int n;
    scanf("%d", &n);
    Building* ls_xyh = (Building*)malloc(sizeof(Building) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &ls_xyh[i].x, &ls_xyh[i].y, &ls_xyh[i].h);
    }
    
    // Execute the solve function with the input and print the result
    char* result = solve(n, ls_xyh);
    printf("%s\n", result);
    
    // Free the memory allocated for the input buildings
    free(ls_xyh);
    
    // Free the memory allocated for the result string
    free(result);
    
    return 0;
}

