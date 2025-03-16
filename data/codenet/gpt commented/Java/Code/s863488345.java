import java.util.*;

public class Main {
    // Variables to store the number of maps, dimensions of the map, and the battle map itself
    static int mapNum; // Number of Battle Town maps
    static int h; // Height of the map
    static int w; // Width of the map
    static char[][] battleTown; // 2D array to store the Battle Town map
    static int bomberActNum; // Number of actions for the tank
    static char[] bomberAct; // Array to store the actions of the tank
    static int[] tank = new int[2]; // Array to store tank's position
    static int xOfTank; // X coordinate of the tank
    static int yOfTank; // Y coordinate of the tank
    static int xOfBomber; // X coordinate of the bomber
    static int yOfBomber; // Y coordinate of the bomber
    static int s; // Display variable
    static int k; // Display variable
    static int a; // X coordinate of the bomber
    static int b; // Y coordinate of the bomber
    static int x; // Tank's position X
    static int y; // Tank's position Y

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read the number of maps
        mapNum = sc.nextInt();

        // Loop through each map
        for (int i = 0; i < mapNum; i++) {
            // Print a new line between maps
            if (1 <= i && i < mapNum) {
                System.out.println("");
            }
            // Read the dimensions of the map
            h = sc.nextInt();
            w = sc.nextInt();

            // Initialize the battleTown array with the given dimensions
            battleTown = new char[h][w];

            // Read the map layout
            for (int j = 0; j < h; j++) {
                char[] c = sc.next().toCharArray();
                for (int k = 0; k < w; k++) {
                    battleTown[j][k] = c[k];

                    // Check if the current character is a tank
                    if ('^' == battleTown[j][k] || 'v' == battleTown[j][k] || '<' == battleTown[j][k] || '>' == battleTown[j][k]) {
                        // Store the tank's position
                        x = j;
                        y = k;
                    }
                }
            }

            // Read the number of actions for the bomber
            bomberActNum = sc.nextInt();
            bomberAct = sc.next().toCharArray();

            // Ensure the tank's position is within the bounds of the map
            if (0 <= x && x < h && 0 <= y && y < w) {
                // Process each action for the bomber
                for (int l = 0; l < bomberActNum; l++) {
                    // Move the tank up
                    if (bomberAct[l] == 'U') {
                        battleTown[x][y] = '^';
                        if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
                            battleTown[x - 1][y] = '^';
                            battleTown[x][y] = '.';
                            x--;
                        }
                    }
                    // Move the tank down
                    if (bomberAct[l] == 'D') {
                        battleTown[x][y] = 'v';
                        if (x + 1 < h && battleTown[x + 1][y] == '.') {
                            battleTown[x + 1][y] = 'v';
                            battleTown[x][y] = '.';
                            x++;
                        }
                    }
                    // Move the tank left
                    if (bomberAct[l] == 'L') {
                        battleTown[x][y] = '<';
                        if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
                            battleTown[x][y - 1] = '<';
                            battleTown[x][y] = '.';
                            y--;
                        }
                    }
                    // Move the tank right
                    if (bomberAct[l] == 'R') {
                        battleTown[x][y] = '>';
                        if (y + 1 < w && battleTown[x][y + 1] == '.') {
                            battleTown[x][y + 1] = '>';
                            battleTown[x][y] = '.';
                            y++;
                        }
                    }
                    // Fire the tank's weapon
                    if (bomberAct[l] == 'S') {
                        xOfBomber = x;
                        yOfBomber = y;
                        moveBomber(xOfBomber, yOfBomber);
                    }
                }
                // Print the final state of the battleTown map
                for (s = 0; s < h; s++) {
                    for (k = 0; k < w; k++) {
                        System.out.print(battleTown[s][k]);
                    }
                    System.out.println();
                }
            }
        }
    }

    // Method to handle the bomber's firing action
    public static void moveBomber(int a, int b) {
        // Ensure the bomber's position is within the bounds of the map
        if (0 <= a && a < h && 0 <= b && b < w) {
            // Check the direction the tank is facing and fire accordingly
            if ('^' == battleTown[a][b]) {
                for (int i = a - 1; i >= 0; i--) {
                    if (battleTown[a - 1][b] == '*') {
                        battleTown[a - 1][b] = '.';
                        return; // End firing if a brick wall is hit
                    } else if (battleTown[a - 1][b] == '#') {
                        return; // End firing if an iron wall is hit
                    } else {
                        a--;
                        if (a == 0) {
                            return; // Stop if the top of the map is reached
                        }
                    }
                }
            }

            if ('v' == battleTown[a][b]) {
                for (int i = a + 1; i < h; i++) {
                    if (battleTown[a + 1][b] == '*') {
                        battleTown[a + 1][b] = '.';
                        return; // End firing if a brick wall is hit
                    } else if (battleTown[a + 1][b] == '#') {
                        return; // End firing if an iron wall is hit
                    } else {
                        a++;
                        if (a == h) {
                            return; // Stop if the bottom of the map is reached
                        }
                    }
                }
            }

            if ('<' == battleTown[a][b]) {
                for (int i = b - 1; i >= 0; i--) {
                    if (battleTown[a][b - 1] == '*') {
                        battleTown[a][b - 1] = '.';
                        return; // End firing if a brick wall is hit
                    } else if (battleTown[a][b - 1] == '#') {
                        return; // End firing if an iron wall is hit
                    } else {
                        b--;
                        if (b == 0) {
                            return; // Stop if the left edge of the map is reached
                        }
                    }
                }
            }

            if ('>' == battleTown[a][b]) {
                for (int i = b + 1; i < w; i++) {
                    if (battleTown[a][b + 1] == '*') {
                        battleTown[a][b + 1] = '.';
                        return; // End firing if a brick wall is hit
                    } else if (battleTown[a][b + 1] == '#') {
                        return; // End firing if an iron wall is hit
                    } else {
                        b++;
                        if (b == w) {
                            return; // Stop if the right edge of the map is reached
                        }
                    }
                }
            }
        }
    }
}
