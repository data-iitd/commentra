// Importing the Scanner class to read input from standard input
import java.util.Scanner;

// Function to solve the problem
public static String solve(int n, int[][] ls_xyh) {
    // Initialize x0 as None
    int x0 = 0;
    int y0 = 0;
    int h0 = 0;

    // Iterate through the list ls_xyh to find the point with the highest height
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {  // Check if the height is positive
            x0 = ls_xyh[i][0];  // Assign x0, y0, and h0
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            break;
        }
    }

    // Generate a list of candidate points based on the given height and the position of x0, y0
    int[][] cands = new int[101][101];
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            cands[cx][cy] = h0 + Math.max(Math.abs(cx - x0) + Math.abs(cy - y0), 0);
        }
    }

    // Filter out the invalid candidate points based on the given height
    for (int[] xyh : ls_xyh) {
        for (int cx = 0; cx < 101; cx++) {
            for (int cy = 0; cy < 101; cy++) {
                cands[cx][cy] = Math.max(cands[cx][cy] - Math.max(Math.abs(cx - xyh[0]) + Math.abs(cy - xyh[1]), 0), 0);
            }
        }
    }

    // Find the point with the minimum height among the valid candidates
    int xx = 0;
    int yy = 0;
    int hh = Integer.MAX_VALUE;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            if (cands[cx][cy] < hh) {
                xx = cx;
                yy = cy;
                hh = cands[cx][cy];
            }
        }
    }

    // Return the solution as a string
    return xx + " " + yy + " " + hh;
}

// Function to read the question and return the problem data
public static int[][] readQuestion() {
    // Read the first line to get the number of points
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    // Read the second line to get the list of points
    int[][] ls_xyh = new int[n][3];
    for (int j = 0; j < n; j++) {
        ls_xyh[j][0] = sc.nextInt();
        ls_xyh[j][1] = sc.nextInt();
        ls_xyh[j][2] = sc.nextInt();
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

