// Java program For handling Input/Output 
import java.io.*; 
import java.util.*;
import java.math.*;
//import java.awt.*;

public class Main { 
    // Scanner object for input
    Scanner sc;
    int max = 0, cur = 0; // Variables to track maximum value and current value

    // Method to solve the main logic of the program
    void solve(){
        // Read two integers from input
        int a = ni();
        int b = ni();

        // Calculate and print the maximum of 0 and (a - 2*b)
        System.out.println(Math.max(0, a - 2 * b));
    }

    /*
    // Commented out code for handling graph-related logic
    int n = ni();
    int m = ni();
    int s[] = new int[n];

    // Input array of integers
    ia(s);

    // Initialize a 2D array to represent roads (graph)
    int roads[][] = new int[n][n];
    for(int i = 0; i < m; i++) {
        int p = ni();
        int q = ni();
        // Mark the roads as bidirectional
        roads[p - 1][q - 1] = 1;
        roads[q - 1][p - 1] = 1;
    }

    // Print the adjacency matrix of the roads
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            System.out.print(roads[i][j] + " ");
        }
        System.out.println();
    }
    int start = ni() - 1;

    // Find roads starting from the given node
    findRoads(roads[start], roads, start, s);
    System.out.println(max);
    }

    // Recursive method to find roads and calculate maximum value
    void findRoads(int a[], int roads[][], int j, int s[]) {
        for(int i = 0; i < a.length; i++) {
            if(a[i] == 1) {
                // Print the current road
                System.out.println(i);
                // Remove the road from the graph
                roads[i][j] = 0;
                roads[j][i] = 0;
                cur += s[j]; // Update current value
                int temp = s[j]; // Store the current value
                s[j] = 0; // Mark the current node as visited
                // Recursively find roads from the next node
                findRoads(roads[i], roads, i, s);
                max = Math.max(max, cur); // Update maximum value
                cur -= s[j]; // Backtrack current value
                // Restore the road in the graph
                roads[i][j] = 1;
                roads[j][i] = 1;
                s[j] = temp; // Restore the current node's value
            }
        }
    }

    // Constructor to initialize the Scanner object
    Main() {
        try {  
            sc = new Scanner(System.in);
        } catch(Exception e) {
            System.out.println(e);
        }
    }

    // Main method to execute the program
    public static void main(String[] args) { 
        new Main().solve(); // Create an instance of Main and call solve
    }

    // Utility methods for input handling

    // Input an integer from scanner
    int ni() {
        int a = sc.nextInt();
        return a;
    }

    // Input a long from scanner
    long nl() {
        return sc.nextLong();
    }

    // Input a float from scanner
    float nf() {
        float a = sc.nextFloat();
        return a;
    }

    // Input a double from scanner
    double nd() {
        double a = sc.nextDouble();
        return a;
    }

    // Input a sentence from scanner
    String ns() {
        return sc.nextLine();
    }

    // Converts a string to StringTokenizer
    StringTokenizer nst(String s) {
        return new StringTokenizer(s);
    }

    // Input an integer array
    void ia(int a[]) {
        for(int i = 0; i < a.length; i++)
            a[i] = sc.nextInt();
    }

    // Input a long array
    void la(long a[]) {
        for(int i = 0; i < a.length; i++)
            a[i] = sc.nextLong();
    }

    // Input a float array
    void fa(float a[]) {
        for(int i = 0; i < a.length; i++)
            a[i] = sc.nextFloat();
    }

    // Input a double array
    void da(double a[]) {
        for(int i = 0; i < a.length; i++)
            a[i] = sc.nextDouble();
    }

    // Input a string array either with all empty input or from scanner
    void sa(String a[], boolean empty) {
        if(empty) {
            for(int i = 0; i < a.length; i++) {
                a[i] = ""; // Initialize with empty strings
            }
        } else {
            for(int i = 0; i < a.length; i++) {
                a[i] = ns(); // Read from scanner
            }
        }
    }

    // Input two-dimensional integer array
    void ida(int a[][], int n, int m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = ni(); // Read each element
            }
        }
    }

    // Input two-dimensional long array
    void lda(long a[][], int n, int m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = nl(); // Read each element
            }
        }
    }

    // Input two-dimensional double array
    void dda(double a[][], int n, int m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = nd(); // Read each element
            }
        }
    }

    // Convert string to integer
    int stoi(String s) {
        return Integer.parseInt(s);
    }

    // Convert string to double
    double stod(String s) {
        return Double.parseDouble(s);
    }

    // Find minimum in a long array
    long lmin(long a[]) {
        long min = Long.MAX_VALUE; // Initialize min to maximum value
        for(int i = 0; i < a.length; i++) {
            if(min > a[i])
                min = a[i]; // Update min if a smaller value is found
        }
        return min; // Return the minimum value
    }

    // Find minimum in an integer array
    int imin(int a[]) {
        int min = Integer.MAX_VALUE; // Initialize min to maximum value
        for(int i = 0; i < a.length; i++) {
            if(min > a[i])
                min = a[i]; // Update min if a smaller value is found
        }
        return min; // Return the minimum value
    }

    // Find maximum in a long array
    long lmax(long a[]) {
        long max = Long.MIN_VALUE; // Initialize max to minimum value
        for(int i = 0; i < a.length; i++) {
            if(max < a[i])
                max = a[i]; // Update max if a larger value is found
        }
        return max; // Return the maximum value
    }

    // Find maximum in an integer array
    int imax(int a[]) {
        int max = Integer.MIN_VALUE; // Initialize max to minimum value
        for(int i = 0; i < a.length; i++) {
            if(max < a[i])
                max = a[i]; // Update max if a larger value is found
        }
        return max; // Return the maximum value
    }

    // Check whether an element is present in an integer array using binary search
    boolean ibs(int a[], int toFind) {
        Arrays.sort(a); // Sort the array for binary search
        int min = 0;
        int max = a.length - 1;
        boolean found = false;

        // Perform binary search
        while(min <= max && !found) {
            int mid = min + (max - min) / 2;
            if(a[mid] == toFind) {
                found = true; // Element found
            } else if(toFind > a[mid]) {
                min = mid + 1; // Search in the right half
            } else {
                max = mid - 1; // Search in the left half
            }
        }
        return found; // Return whether the element was found
    }

    // Check whether an element is present in a long array using binary search
    boolean lbs(long a[], long toFind) {
        Arrays.sort(a); // Sort the array for binary search
        int min = 0;
        int max = a.length - 1;
        boolean found = false;

        // Perform binary search
        while(min <= max && !found) {
            int mid = min + (max - min) / 2;
            if(a[mid] == toFind) {
                found = true; // Element found
            } else if(toFind > a[mid]) {
                min = mid + 1; // Search in the right half
            } else {
                max = mid - 1; // Search in the left half
            }
        }
        return found; // Return whether the element was found
    }

    // Convert binary string to integer
    int stb(String s) {
        int sum = 0;
        int k = 0;
        // Convert each character to its integer value and calculate the sum
        for(int i = s.length() - 1; i >= 0; i--) {
            sum += stoi(s.charAt(i) + "") * Math.pow(2, k++);
        }
        return sum; // Return the computed sum
    }
}
