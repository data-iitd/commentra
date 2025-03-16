
#include <iostream>
#include <cstring>
#define MAX 21

void init(int i);
void move(int i);

int n, x, y;
char fld[MAX][MAX];

int main(void) {
    int m; // m is the number of moves to be made
    while(1) { // Infinite loop until user inputs a non-positive number for n
        if(~std::cin >> n) { // Try to read an integer from the standard input
            if(n >= 0) { // If n is non-negative, initialize the game and read m
                init(n);
                std::cin >> m;
                move(m);
                std::cout << (n ? "No" : "Yes") << std::endl; // Print whether it's possible to make all moves
            } else {
                break; // If n is non-positive, break the loop
            }
        }
    }
    return 0;
}

void init(int i) { // Initialize the game with n fields
    int a, b;
    x = y = 10; // Set the initial position of the player
    memset(fld, 0, sizeof(fld)); // Initialize the field with zeros
    while(i--) { // Read and store the obstacles' positions
        std::cin >> a >> b;
        fld[b][a] = 1;
    }
}

void move(int i) { // Move the player i times
    int a, d;
    char buf[2];
    while(i--) { // Iterate through all moves
        std::cin >> buf >> a; // Read the direction and the number of steps
        switch(buf[0]) { // Determine the direction based on the first character
          case 'N':
            d = 0;
            break;
          case 'E':
            d = 1;
            break;
          case 'S':
            d = 2;
            break;
          case 'W':
            d = 3;
            break;
        }
        while(a--) { // Move the player in the given direction
            if(d % 2) { // If the direction is odd, move horizontally
                d % 2 ? ~-d ? x-- : x++ : d ? y-- : y++;
            } else { // If the direction is even, move vertically
                d ? y-- : y++;
                x += d / 2;
            }
            if(fld[y][x]) { // If there's an obstacle at the current position, remove it and decrease the number of available moves
                fld[y][x] = 0;
                n--;
            }
        }
    }
}

