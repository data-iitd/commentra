
###
# Code
###

# Include necessary header files
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAXN 100000
#define MOD 100000007

// Define data structures
typedef struct {
    int w;
    int r;
} Ball;

// Define global variables
int N, M;
Ball balls[MAXN];

// Define helper functions
void init() {
    // Initialize input variables
    scanf("%d %d", &N, &M);
    
    // Initialize list of balls with their weight and position
    for (int i = 0; i < N; i++) {
        balls[i].w = 1;
        balls[i].r = 0;
    }
    balls[0].r = 1;
}

void process() {
    // Process each event
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        int w_x = balls[x - 1].w;
        int r_x = balls[x - 1].r;
        int w_y = balls[y - 1].w;
        int r_y = balls[y - 1].r;
        
        // Update balls' weights and positions based on the event
        if (w_x >= 1 && r_x >= 1) {
            // Ball x collides with ball y
            balls[x - 1].w -= 1;
            balls[y - 1].r += 1;
        } else if (w_x == 0) {
            // Ball x is stationary and ball y collides with another ball
            balls[x - 1].r -= 1;
            balls[y - 1].r += 1;
        } else {
            // Ball x is moving and collides with ball y
            balls[x - 1].w -= 1;
            balls[y - 1].w += 1;
        }
    }
}

int main() {
    init();
    process();
    
    // Calculate answer
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i].r) {
            ans += 1;
        }
    }
    
    // Print the answer
    printf("%d\n", ans);
    
    return 0;
}
