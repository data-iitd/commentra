
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new data instance and check for the existence of a match
        Data d = newData();
        if (d.exist()) {
            System.out.println("Yes"); // Print "Yes" if a match exists
        } else {
            System.out.println("No");  // Print "No" if no match is found
        }
    }

    // Function to read input dimensions and images, returning a data instance
    public static Data newData() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] nImg = load(n);
        String[] mImg = load(m);

        // Return a data instance containing the dimensions and images
        return new Data(n, m, nImg, mImg);
    }

    // Function to load an image of given count from standard input
    public static String[] load(int cnt) {
        String[] ret = new String[cnt]; // Create a slice to hold the image strings
        for (int i = 0; i < cnt; i++) {
            // Read each line of the image into the slice
            ret[i] = sc.next();
        }

        // Return the loaded image
        return ret;
    }

    // Method to check if the second image exists within the first image
    public boolean exist() {
        // Iterate over possible starting positions in the first image
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                // Check if the second image matches the first image at the current position
                if (match(i, j)) {
                    return true; // Return true if a match is found
                }
            }
        }

        // Return false if no match is found after checking all positions
        return false;
    }

    // Method to check if the second image matches the first image at a specific position
    public boolean match(int x, int y) {
        // Iterate over each cell of the second image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Compare the corresponding cells of the two images
                if (nImg[x + i][y + j].equals(mImg[i][j])) {
                    return false; // Return false if any cell does not match
                }
            }
        }

        // Return true if all cells match
        return true;
    }

    // Constructor to initialize the data instance
    public Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    // Instance variables
    private int n;
    private int m;
    private String[] nImg;
    private String[] mImg;
}

class Data {
    public Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    public boolean exist() {
        // Iterate over possible starting positions in the first image
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                // Check if the second image matches the first image at the current position
                if (match(i, j)) {
                    return true; // Return true if a match is found
                }
            }
        }

        // Return false if no match is found after checking all positions
        return false;
    }

    public boolean match(int x, int y) {
        // Iterate over each cell of the second image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                // Compare the corresponding cells of the two images
                if (nImg[x + i][y + j].equals(mImg[i][j])) {
                    return false; // Return false if any cell does not match
                }
            }
        }

        // Return true if all cells match
        return true;
    }

    // Instance variables
    private int n;
    private int m;
    private String[] nImg;
    private String[] mImg;
}

