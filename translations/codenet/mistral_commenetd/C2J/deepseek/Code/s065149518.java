import java.util.Scanner;

public class Game {
    static final int MAX = 21;
    static int n, x, y;
    static int[][] fld = new int[MAX][MAX];

    public static void main(void) {
        Scanner scanner = new Scanner(System.in);
        int m; // m is the number of moves to be made
        while (true) { // Infinite loop until user inputs a non-positive number for n
            if (scanner.hasNextInt()) { // Try to read an integer from the standard input
                n = scanner.nextInt();
                if (n >= 0) { // If n is non-negative, initialize the game and read m
                    init(n);
                    m = scanner.nextInt();
                    move(m);
                    System.out.println(n == 0 ? "Yes" : "No"); // Print whether it's possible to make all moves
                } else {
                    break; // If n is non-positive, break the loop
                }
            }
        }
        scanner.close();
    }

    static void init(int i) { // Initialize the game with n fields
        int a, b;
        x = y = 10; // Set the initial position of the player
        for (int[] row : fld) {
            java.util.Arrays.fill(row, 0); // Initialize the field with zeros
        }
        while (i-- > 0) { // Read and store the obstacles' positions
            a = scanner.nextInt();
            b = scanner.nextInt();
            fld[b][a] = 1;
        }
    }

    static void move(int i) { // Move the player i times
        Scanner scanner = new Scanner(System.in);
        int a;
        String buf;
        while (i-- > 0) { // Iterate through all moves
            buf = scanner.next(); // Read the direction and the number of steps
            a = scanner.nextInt();
            switch (buf.charAt(0)) { // Determine the direction based on the first character
                case 'N':
                    for (int j = 0; j < a; j++) {
                        if (y > 0 && fld[y - 1][x] == 1) {
                            fld[y - 1][x] = 0;
                            n--;
                        }
                        y--;
                    }
                    break;
                case 'E':
                    for (int j = 0; j < a; j++) {
                        if (x < MAX - 1 && fld[y][x + 1] == 1) {
                            fld[y][x + 1] = 0;
                            n--;
                        }
                        x++;
                    }
                    break;
                case 'S':
                    for (int j = 0; j < a; j++) {
                        if (y < MAX - 1 && fld[y + 1][x] == 1) {
                            fld[y + 1][x] = 0;
                            n--;
                        }
                        y++;
                    }
                    break;
                case 'W':
                    for (int j = 0; j < a; j++) {
                        if (x > 0 && fld[y][x - 1] == 1) {
                            fld[y][x - 1] = 0;
                            n--;
                        }
                        x--;
                    }
                    break;
            }
        }
        scanner.close();
    }
}
