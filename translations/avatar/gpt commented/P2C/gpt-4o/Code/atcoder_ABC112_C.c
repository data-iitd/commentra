#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CANDIDATES 10000
#define MAX_COORDINATE 101

typedef struct {
    int x;
    int y;
    int h;
} Building;

void solve(int n, Building *buildings) {
    int x0, y0, h0;
    int found = 0;

    // Initialize the coordinates and height of the first building with a positive height
    for (int i = 0; i < n; i++) {
        if (buildings[i].h > 0) {
            x0 = buildings[i].x;
            y0 = buildings[i].y;
            h0 = buildings[i].h;
            found = 1;
            break;
        }
    }

    if (!found) {
        return; // No building with positive height found
    }

    // Generate candidate positions (cx, cy) with their corresponding heights
    int candidates[MAX_CANDIDATES][3];
    int candidate_count = 0;

    for (int cx = 0; cx < MAX_COORDINATE; cx++) {
        for (int cy = 0; cy < MAX_COORDINATE; cy++) {
            int ch = h0 + abs(cx - x0) + abs(cy - y0);
            candidates[candidate_count][0] = cx;
            candidates[candidate_count][1] = cy;
            candidates[candidate_count][2] = ch;
            candidate_count++;
        }
    }

    // Filter candidates based on the height constraints from the other buildings
    for (int i = 0; i < n; i++) {
        Building b = buildings[i];
        int new_candidate_count = 0;

        for (int j = 0; j < candidate_count; j++) {
            int cx = candidates[j][0];
            int cy = candidates[j][1];
            int ch = candidates[j][2];

            if (fmax(ch - abs(cx - b.x) - abs(cy - b.y), 0) == b.h) {
                candidates[new_candidate_count][0] = cx;
                candidates[new_candidate_count][1] = cy;
                candidates[new_candidate_count][2] = ch;
                new_candidate_count++;
            }
        }
        candidate_count = new_candidate_count;
    }

    // Select the first valid candidate position and height
    if (candidate_count > 0) {
        int xx = candidates[0][0];
        int yy = candidates[0][1];
        int hh = candidates[0][2];

        // Print the result as a space-separated string
        printf("%d %d %d\n", xx, yy, hh);
    }
}

void readQuestion(int *n, Building **buildings) {
    scanf("%d", n);
    *buildings = (Building *)malloc(*n * sizeof(Building));

    for (int i = 0; i < *n; i++) {
        scanf("%d %d %d", &(*buildings)[i].x, &(*buildings)[i].y, &(*buildings)[i].h);
    }
}

int main() {
    int n;
    Building *buildings;

    readQuestion(&n, &buildings);
    solve(n, buildings);

    free(buildings);
    return 0;
}

// <END-OF-CODE>
