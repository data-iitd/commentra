// Importing the Scanner class for reading input from standard input
import java.util.Scanner;

// Function to solve the problem
public static String solve(int n, int[][] ls_xyh) {
    // Initialize x0 as None
    int x0 = -1;
    int y0 = -1;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    int[][] cands = new int[101][101];
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            cands[i][j] = ls_xyh[0][2] + Math.abs(i - x0) + Math.abs(j - y0);
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++) {
                cands[j][k] = Math.max(cands[j][k] - Math.abs(ls_xyh[i][0] - j) - Math.abs(ls_xyh[i][1] - k), 0);
            }
        }
    }

    // Find the point with the minimum height among the valid candidates
    int[][] min_cand = new int[1][3];
    min_cand[0][0] = 100;
    min_cand[0][1] = 100;
    min_cand[0][2] = 1000000000;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (cands[i][j] < min_cand[0][2]) {
                min_cand[0][0] = i;
                min_cand[0][1] = j;
                min_cand[0][2] = cands[i][j];
            }
        }
    }

    // Return the solution as a string
    return min_cand[0][0] + " " + min_cand[0][1] + " " + min_cand[0][2];
}

// Function to read the question and return the problem data
public static int[][] readQuestion() {
    // Read the first line to get the number of points
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    // Read the second line to get the list of points
    int[][] ls_xyh = new int[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            ls_xyh[i][j] = sc.nextInt();
        }
    }

    // Return the problem data as a tuple (number of points, list of points)
    return ls_xyh;
}

// Main function to call the solve function and print the result
public static void main(String[] args) {
    // Call the readQuestion function to get the problem data
    int[][] data = readQuestion();

    // Call the solve function to get the solution
    String solution = solve(data.length, data);

    // Print the solution
    System.out.println(solution);
}

// END-OF-CODE
