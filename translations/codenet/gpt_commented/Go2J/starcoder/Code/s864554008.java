package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new data instance and check for the existence of a match
        data d = newData();
        if (d.exist()) {
            System.out.println("Yes"); // Print "Yes" if a match exists
        } else {
            System.out.println("No");  // Print "No" if no match is found
        }
    }

    // Function to read input dimensions and images, returning a data instance
    public static data newData() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        // Load the first image and the second image based on the dimensions
        String[] nImg = load(n);
        String[] mImg = load(m);

        // Return a data instance containing the dimensions and images
        return new data(n, m, nImg, mImg);
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
    public static boolean exist(data d) {
        // Iterate over possible starting positions in the first image
        for (int i = 0; i <= d.n-d.m; i++) {
            for (int j = 0; j <= d.n-d.m; j++) {
                // Check if the second image matches the first image at the current position
                if (match(d, i, j)) {
                    return true; // Return true if a match is found
                }
            }
        }

        // Return false if no match is found after checking all positions
        return false;
    }

    // Method to check if the second image matches the first image at a specific position
    public static boolean match(data d, int x, int y) {
        // Iterate over each cell of the second image
        for (int i = 0; i < d.m; i++) {
            for (int j = 0; j < d.m; j++) {
                // Compare the corresponding cells of the two images
                if (d.nImg[x+i][y+j]!= d.mImg[i][j]) {
                    return false; // Return false if any cell does not match
                }
            }
        }

        // Return true if all cells match
        return true;
    }

    // Define a struct to hold the dimensions and images
    public static class data {
        int n, m; // n: number of rows in the first image, m: number of rows in the second image
        String[] nImg, mImg; // nImg: first image as a slice of strings, mImg: second image as a slice of strings

        public data(int n, int m, String[] nImg, String[] mImg) {
            this.n = n;
            this.m = m;
            this.nImg = nImg;
            this.mImg = mImg;
        }
    }
}

