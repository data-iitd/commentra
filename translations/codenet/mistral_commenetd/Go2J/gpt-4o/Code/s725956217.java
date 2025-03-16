// Import necessary packages
import java.util.*;

// Main class is the entry point of the program
public class Main {
    // Method to print output to the console
    static void out(Object... x) {
        System.out.println(Arrays.toString(x));
    }

    // Method to read an integer value from the standard input
    static int getInt() {
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }

    // Method to read a string value from the standard input
    static String getString() {
        Scanner sc = new Scanner(System.in);
        return sc.next();
    }

    // Method to return the maximum value between two integers
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    // Method to return the minimum value between two integers
    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Method to return the absolute difference between two integers
    static int asub(int a, int b) {
        return a > b ? a - b : b - a;
    }

    // Method to return the absolute value of an integer
    static int abs(int a) {
        return a >= 0 ? a : -a;
    }

    // Method to find the lower bound index
    static int lowerBound(int[] a, int x) {
        int idx = Arrays.binarySearch(a, x);
        return idx < 0 ? -idx - 1 : idx;
    }

    // Method to find the upper bound index
    static int upperBound(int[] a, int x) {
        int idx = Arrays.binarySearch(a, x);
        return idx < 0 ? -idx - 1 : idx + 1;
    }

    // Class to represent a shop with two integers
    static class Shop {
        int a, b;

        Shop(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    // Main method is the entry point of the program
    public static void main(String[] args) {
        // Read the number of shops N and the number of customers M from the standard input
        int N = getInt();
        int M = getInt();

        // Initialize a list of shop data structures
        List<Shop> shops = new ArrayList<>();
        // For each shop in the list
        for (int i = 0; i < N; i++) {
            // Read the capacity 'a' and demand 'b' of the shop from the standard input
            int a = getInt();
            int b = getInt();
            // Create a new shop data structure with the read values and add it to the list
            shops.add(new Shop(a, b));
        }

        // Sort the list in ascending order based on the 'a' field of each shop
        shops.sort(Comparator.comparingInt(shop -> shop.a));

        // Initialize a variable named total to store the total capacity used by the shops
        int total = 0;
        // For each shop in the sorted list
        for (Shop shop : shops) {
            // Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
            int n = min(shop.b, M);
            // Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
            total += n * shop.a;
            // Decrease the maximum demand by the number of customers served by the shop
            M -= n;
            // If the maximum demand becomes zero, break the loop
            if (M == 0) {
                break;
            }
        }
        // Print the total capacity used by the shops
        out(total);
    }
}
// <END-OF-CODE>
