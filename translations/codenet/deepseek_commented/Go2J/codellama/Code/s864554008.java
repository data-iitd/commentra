
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a new data instance
        Data d = newData();

        // Check if the smaller image exists within the larger image and print the result
        if (d.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // Function to initialize a new data instance by reading image dimensions and data from standard input
    public static Data newData() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the dimensions of the images
        int m = sc.nextInt();

        // Load the images from standard input
        String[] nImg = load(n, sc);
        String[] mImg = load(m, sc);

        // Return a new data instance with the loaded images and dimensions
        return new Data(n, m, nImg, mImg);
    }

    // Function to read a specified number of strings from standard input and return them as a slice of strings
    public static String[] load(int cnt, Scanner sc) {
        String[] ret = new String[cnt];
        for (int i = 0; i < cnt; i++) {
            ret[i] = sc.next(); // Read each string from standard input
        }
        return ret;
    }

    // Method to check if the smaller image exists within the larger image
    public boolean exist() {
        // Iterate over all possible positions where the smaller image could fit within the larger image
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (match(i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
                    return true;
                }
            }
        }
        return false;
    }

    // Method to check if the smaller image matches the corresponding part of the larger image at a given position
    public boolean match(int x, int y) {
        // Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (nImg[x + i][y + j].equals(mImg[i][j])) { // If any pixel does not match, return false
                    return false;
                }
            }
        }
        return true; // If all pixels match, return true
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

