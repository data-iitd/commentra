import java.util.*;

public class Main {
    // Variables declaration and initialization
    static int mapNum; // Number of Buttle Town maps
    static int h; // Height of the current map
    static int w; // Width of the current map
    static char[][] battleTown; // 2D array to store the current map
    static int bomberActNum; // Number of actions for the bomber
    static char [] bomberAct; // Array to store the bomber's actions
    static int []tank; // Array to store the tank's position
    static int xOfTank; // Current x-position of the tank
    static int yOfTank; // Current y-position of the tank
    static int xOfBomber; // Current x-position of the bomber
    static int yOfBomber; // Current y-position of the bomber
    static int s; // Counter for the map display
    static int k; // Counter for the current position in the map
    static int a; // Current x-position of the bomber
    static int b; // Current y-position of the bomber
    static int x; // Current x-position of the tank
    static int y; // Current y-position of the tank

    public static void main(String[] args){
        // Initialize the scanner to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the number of maps and initialize the variables for each map
        mapNum = sc.nextInt();
        for (int i = 0; i < mapNum; i++) {
            if (i > 0) { // Print an empty line between each map
                System.out.println("");
            }

            // Read the height and width of the current map
            h = sc.nextInt();
            w = sc.nextInt();

            // Initialize the battleTown array for the current map
            battleTown = new char[h][w];

            // Read the map data and store it in the battleTown array
            for (int j = 0; j < h; j++) {
                char[] c = sc.next().toCharArray();
                for (int k = 0; k < w; k++) {
                    battleTown[j][k] = c[k];

                    // Check if the current position is the tank's position
                    if (battleTown[j][k] == '^' || battleTown[j][k] == 'v' || battleTown[j][k] == '<' || battleTown[j][k] == '>') {
                        x = j;
                        y = k;
                    }
                }
            }

            // Read the number of actions for the bomber and store them in the bomberAct array
            bomberActNum = sc.nextInt();
            bomberAct = sc.next().toCharArray();

            // Check if the tank's position is within the map boundaries
            if (x >= 0 && x < h && y >= 0 && y < w) {
                // Perform the bomber's actions
                for (int l = 0; l < bomberActNum; l++) {
                    // Check the current action and perform the corresponding movement
                    switch (bomberAct[l]) {
                        case 'U':
                            // Move the bomber up
                            moveBomberUp(a, b);
                            break;
                        case 'D':
                            // Move the bomber down
                            moveBomberDown(a, b);
                            break;
                        case 'L':
                            // Move the bomber left
                            moveBomberLeft(a, b);
                            break;
                        case 'R':
                            // Move the bomber right
                            moveBomberRight(a, b);
                            break;
                        case 'S':
                            // Drop a bomb
                            dropBomb(xOfBomber, yOfBomber);
                            break;
                    }
                }

                // Display the current map
                displayMap(battleTown);
            }
        }
    }

    // Function to move the bomber up
    public static void moveBomberUp(int a, int b) {
        // Check if the bomber can move up
        if (canMove(a, b, -1, 0)) {
            // Move the bomber up and update the position in the battleTown array
            battleTown[a][b] = '^';
            a--;
            battleTown[a][b] = '.';
        }
    }

    // Function to move the bomber down
    public static void moveBomberDown(int a, int b) {
        // Check if the bomber can move down
        if (canMove(a, b, 1, 0)) {
            // Move the bomber down and update the position in the battleTown array
            battleTown[a][b] = 'v';
            a++;
            battleTown[a][b] = '.';
        }
    }

    // Function to move the bomber left
    public static void moveBomberLeft(int a, int b) {
        // Check if the bomber can move left
        if (canMove(a, b, 0, -1)) {
            // Move the bomber left and update the position in the battleTown array
            battleTown[a][b] = '<';
            b--;
            battleTown[a][b] = '.';
        }
    }

    // Function to move the bomber right
    public static void moveBomberRight(int a, int b) {
        // Check if the bomber can move right
        if (canMove(a, b, 0, 1)) {
            // Move the bomber right and update the position in the battleTown array
            battleTown[a][b] = '>';
            b++;
            battleTown[a][b] = '.';
        }
    }

    // Function to drop a bomb
    public static void dropBomb(int a, int b) {
        // Check if the bomber is on a valid position to drop a bomb
        if (isValidBombDropPosition(a, b)) {
            // Drop the bomb and update the battleTown array
            battleTown[a][b] = '*';
        }
    }

    // Function to check if the bomber can move to the given position
    public static boolean canMove(int x, int y, int dx, int dy) {
        // Check if the new position is within the map boundaries
        if (x + dx >= 0 && x + dx < h && y + dy >= 0 && y + dy < w) {
            // Check if the new position is a valid position to move to
            if (battleTown[x + dx][y + dy] == '.') {
                return true;
            }
        }
        return false;
    }

    // Function to check if the given position is a valid position to drop a bomb
    public static boolean isValidBombDropPosition(int x, int y) {
        // Check if the given position is a valid position to drop a bomb
        if (battleTown[x][y] == '.') {
            return true;
        }
        return false;
    }

    // Function to display the current map
    public static void displayMap(char[][] map) {
        // Display the map row by row
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                System.out.print(map[i][j]);
            }
            System.out.println();
        }
    }
}
