
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to store the input grid
struct grid {
    int H;
    int W;
    char **A;
};

// Create a struct to store the starting points of 'B'
struct start {
    int y;
    int x;
    int depth;
};

// Create a struct to store the visited cells
struct flag {
    int **flag;
};

// Create a struct to store the directions
struct dir {
    int *dx;
    int *dy;
};

// Create a struct to store the answer
struct ans {
    int ans;
};

// Create a function to read the input grid
struct grid read_grid() {
    struct grid grid;
    scanf("%d %d", &grid.H, &grid.W);
    grid.A = (char**)malloc(grid.H * sizeof(char*));
    for (int i = 0; i < grid.H; i++) {
        grid.A[i] = (char*)malloc(grid.W * sizeof(char));
        scanf("%s", grid.A[i]);
    }
    return grid;
}

// Create a function to initialize the queue with the starting points of 'B'
struct start *init_queue(struct grid grid) {
    struct start *queue = (struct start*)malloc(grid.H * grid.W * sizeof(struct start));
    int count = 0;
    for (int i = 0; i < grid.H; i++) {
        for (int j = 0; j < grid.W; j++) {
            if (grid.A[i][j] == '#') {
                queue[count].y = i;
                queue[count].x = j;
                queue[count].depth = 0;
                count++;
            }
        }
    }
    return queue;
}

// Create a function to initialize the visited cells
struct flag init_flag(struct grid grid) {
    struct flag flag;
    flag.flag = (int**)malloc(grid.H * sizeof(int*));
    for (int i = 0; i < grid.H; i++) {
        flag.flag[i] = (int*)malloc(grid.W * sizeof(int));
        for (int j = 0; j < grid.W; j++) {
            flag.flag[i][j] = 0;
        }
    }
    return flag;
}

// Create a function to initialize the directions
struct dir init_dir() {
    struct dir dir;
    dir.dx = (int*)malloc(4 * sizeof(int));
    dir.dy = (int*)malloc(4 * sizeof(int));
    dir.dx[0] = 1;
    dir.dx[1] = -1;
    dir.dx[2] = 0;
    dir.dx[3] = 0;
    dir.dy[0] = 0;
    dir.dy[1] = 0;
    dir.dy[2] = 1;
    dir.dy[3] = -1;
    return dir;
}

// Create a function to process the queue and find the answer
struct ans process_queue(struct grid grid, struct start *queue, struct flag flag, struct dir dir) {
    struct ans ans;
    ans.ans = 0;
    while (queue->y != -1) {
        int y = queue->y;
        int x = queue->x;
        int depth = queue->depth;
        queue++;
        for (int i = 0; i < 4; i++) {
            int newY = y + dir.dy[i];
            int newX = x + dir.dx[i];
            if (0 <= newY && newY <= grid.H - 1 && 0 <= newX && newX <= grid.W - 1) {
                if (flag.flag[newY][newX] == 0 && grid.A[newY][newX] == '.') {
                    flag.flag[newY][newX] = 1;
                    queue->y = newY;
                    queue->x = newX;
                    queue->depth = depth + 1;
                    ans.ans = max(ans.ans, depth + 1);
                }
            }
        }
    }
    return ans;
}

// Create a function to find the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Create a function to print the answer
void print_ans(struct ans ans) {
    printf("%d\n", ans.ans);
}

// Create a function to free the memory
void free_memory(struct grid grid, struct start *queue, struct flag flag) {
    for (int i = 0; i < grid.H; i++) {
        free(grid.A[i]);
    }
    free(grid.A);
    free(queue);
    for (int i = 0; i < grid.H; i++) {
        free(flag.flag[i]);
    }
    free(flag.flag);
}

// Create a function to run the program
void run() {
    // Read the input grid
    struct grid grid = read_grid();

    // Initialize the queue with the starting points of 'B'
    struct start *queue = init_queue(grid);

    // Initialize the visited cells
    struct flag flag = init_flag(grid);

    // Initialize the directions
    struct dir dir = init_dir();

    // Process the queue and find the answer
    struct ans ans = process_queue(grid, queue, flag, dir);

    // Print the answer
    print_ans(ans);

    // Free the memory
    free_memory(grid, queue, flag);
}

int main() {
    run();
    return 0;
}

