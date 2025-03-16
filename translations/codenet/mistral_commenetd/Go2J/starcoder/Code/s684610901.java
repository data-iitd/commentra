// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

// Define a custom type 'pair' for sorting
class pair {
    int index; // Index for sorting
    Object p1, p2; // Two elements to be compared

    pair(int index, Object p1, Object p2) {
        this.index = index;
        this.p1 = p1;
        this.p2 = p2;
    }
}

// Define a slice type 'pairs' for sorting 'pair' type
class pairs implements Comparator<pair> {
    @Override
    public int compare(pair p1, pair p2) {
        return p1.index - p2.index;
    }
}

// Main function
public class Main {
    // Define a custom type 'Country' with gold, silver, and bronze fields
    static class Country {
        int gold, silver, bronze;

        Country(int gold, int silver, int bronze) {
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
        }
    }

    // Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
    public static List<Country> stableSortExample() {
        // Your code here!
    }

    public static void main(String[] args) {
        // Read input A, B, and C
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        // Check if C is within the range of A and B
        if (C >= A && C <= B) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

