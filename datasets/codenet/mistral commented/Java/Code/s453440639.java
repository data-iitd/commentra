import java.util.Scanner; // Importing the Scanner class for reading input

public class Main { // Defining the main class

    public static void main(String[] args) { // Starting point of the program
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console

        int H = sc.nextInt(); // Reading the first integer (height of the grid) from the input
        int W = sc.nextInt(); // Reading the second integer (width of the grid) from the input
        sc.nextLine(); // Consuming the newline character left after reading integers

        char[][] S = new char[H][W]; // Creating a 2D char array of size H x W to store the grid

        for (int i = 0; i < H; i++) { // Iterating through each row of the grid
            String text = sc.nextLine(); // Reading a line of text from the input
            for (int j = 0; j < W; j++) { // Iterating through each character in the current line
                S[i][j] = text.charAt(j); // Assigning the character at the current position in the line to the corresponding cell in the grid
            }
        }
        sc.close(); // Closing the Scanner object after reading all the input

        for (int i = 0; i < H; i++) { // Iterating through each row of the grid again
            for (int j = 0; j < W; j++) { // Iterating through each cell in the current row
                if (S[i][j] == '.') { // If the current cell is empty
                    int count = 0; // Initializing a counter to keep track of the number of '#' neighbors
                    for (int a = -1; a <= 1; a++) { // Iterating through all possible positions of neighbors in the grid
                        if (i + a < 0 || H <= i + a) { // Checking if the current position is out of bounds
                            continue; // If it is, skip to the next iteration
                        }
                        for (int b = -1; b <= 1; b++) { // Iterating through all possible positions of neighbors in the same row
                            if (j + b < 0 || W <= j + b) { // Checking if the current position is out of bounds
                                continue; // If it is, skip to the next iteration
                            }
                            if (S[i + a][j + b] == '#') { // If the current neighbor is a '#', increment the counter
                                count++;
                            }
                        }
                    }
                    S[i][j] = (char)(count+48); // Assigning the number of neighbors to the current cell
                }
                System.out.printf("%c", S[i][j]); // Printing the current cell to the output
            }
            System.out.printf("\n"); // Printing a newline character after each row
        }
    }
}
