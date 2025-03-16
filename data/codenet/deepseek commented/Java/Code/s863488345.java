import java.util.*;

public class Main {
    static int mapNum; // Number of Battle Town maps
    static int h; // Height of the map
    static int w; // Width of the map
    static char[][] battleTown; // 2D array to store the Battle Town map
    static int bomberActNum; // Number of bomber commands
    static char[] bomberAct; // Array to store the bomber commands
    static int[] tank = new int[2]; // Array to store the tank's position
    static int xOfTank; // Tank's x position
    static int yOfTank; // Tank's y position
    static int xOfBomber; // Bomber's x position during explosion
    static int yOfBomber; // Bomber's y position during explosion
    static int s; // Loop variable for rows in the map
    static int k; // Loop variable for columns in the map
    static int a; // Bomber's x position for movement
    static int b; // Bomber's y position for movement
    static int x; // Temporary variable for tank's x position
    static int y; // Temporary variable for tank's y position

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        mapNum = sc.nextInt(); // Read the number of maps

        for (int i = 0; i < mapNum; i++) {
            if (i > 0) {
                System.out.println(); // Print a newline between maps, except for the first map
            }
            h = sc.nextInt(); // Read the height of the current map
            w = sc.nextInt(); // Read the width of the current map

            battleTown = new char[h][w]; // Initialize the Battle Town map

            for (int j = 0; j < h; j++) {
                char[] c = sc.next().toCharArray(); // Read a row of the map
                for (int k = 0; k < w; k++) {
                    battleTown[j][k] = c[k]; // Store the character in the map
                    if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                        x = j; // Store the tank's x position
                        y = k; // Store the tank's y position
                    }
                }
            }

            bomberActNum = sc.nextInt(); // Read the number of bomber commands
            bomberAct = sc.next().toCharArray(); // Read the bomber commands

            if (0 <= x && x <= h && 0 <= y && y <= w) {
                for (int l = 0; l < bomberActNum; l++) {
                    if (bomberAct[l] == 'U') {
                        moveTankUp(); // Move the tank up
                    } else if (bomberAct[l] == 'D') {
                        moveTankDown(); // Move the tank down
                    } else if (bomberAct[l] == 'L') {
                        moveTankLeft(); // Move the tank left
                    } else if (bomberAct[l] == 'R') {
                        moveTankRight(); // Move the tank right
                    } else if (bomberAct[l] == 'S') {
                        fireBomb(); // Fire a bomb
                    }
                }
                for (s = 0; s < h; s++) {
                    for (k = 0; k < w; k++) {
                        System.out.print(battleTown[s][k]); // Print the final state of the map
                    }
                    System.out.println(); // Print a newline after each row
                }
            }
        }
    }

    public static void moveTankUp() {
        if (x - 1 >= 0 && battleTown[x - 1][y] == '.') {
            battleTown[x - 1][y] = '^'; // Move the tank up
            battleTown[x][y] = '.';
            x--; // Update the tank's position
        }
    }

    public static void moveTankDown() {
        if (x + 1 < h && battleTown[x + 1][y] == '.') {
            battleTown[x + 1][y] = 'v'; // Move the tank down
            battleTown[x][y] = '.';
            x++; // Update the tank's position
        }
    }

    public static void moveTankLeft() {
        if (y - 1 >= 0 && battleTown[x][y - 1] == '.') {
            battleTown[x][y - 1] = '<'; // Move the tank left
            battleTown[x][y] = '.';
            y--; // Update the tank's position
        }
    }

    public static void moveTankRight() {
        if (y + 1 < w && battleTown[x][y + 1] == '.') {
            battleTown[x][y + 1] = '>'; // Move the tank right
            battleTown[x][y] = '.';
            y++; // Update the tank's position
        }
    }

    public static void fireBomb() {
        xOfBomber = x; // Store the bomber's x position
        yOfBomber = y; // Store the bomber's y position
        moveBomber(xOfBomber, yOfBomber); // Simulate the bomb explosion
    }

    public static void moveBomber(int a, int b) {
        if (0 <= a && a <= h && 0 <= b && b <= w) {
            if (battleTown[a][b] == '^') {
                for (int i = a - 1; i >= 0; i--) {
                    if (battleTown[i][b] == '*') {
                        battleTown[i][b] = '.'; // Destroy brick wall
                        return;
                    } else if (battleTown[i][b] == '#') {
                        return; // Stop at steel wall
                    } else {
                        a--; // Continue moving up
                    }
                }
            } else if (battleTown[a][b] == 'v') {
                for (int i = a + 1; i < h; i++) {
                    if (battleTown[i][b] == '*') {
                        battleTown[i][b] = '.'; // Destroy brick wall
                        return;
                    } else if (battleTown[i][b] == '#') {
                        return; // Stop at steel wall
                    } else {
                        a++; // Continue moving down
                    }
                }
            } else if (battleTown[a][b] == '<') {
                for (int i = b - 1; i >= 0; i--) {
                    if (battleTown[a][i] == '*') {
                        battleTown[a][i] = '.'; // Destroy brick wall
                        return;
                    } else if (battleTown[a][i] == '#') {
                        return; // Stop at steel wall
                    } else {
                        b--; // Continue moving left
                    }
                }
            } else if (battleTown[a][b] == '>') {
                for (int i = b + 1; i < w; i++) {
                    if (battleTown[a][i] == '*') {
                        battleTown[a][i] = '.'; // Destroy brick wall
                        return;
                    } else if (battleTown[a][i] == '#') {
                        return; // Stop at steel wall
                    } else {
                        b++; // Continue moving right
                    }
                }
            }
        }
    }
}
