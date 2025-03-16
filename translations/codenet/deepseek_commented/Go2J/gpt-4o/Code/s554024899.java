import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new scanner to read input
        Scanner sc = new Scanner(System.in);
        
        // Read two integers from the input
        int x = sc.nextInt();
        int y = sc.nextInt();
        
        // Define an array containing three arrays, each representing a group of months with the same number of days
        int xt = -1, yt = -1;
        int[][] a = {
            {1, 3, 5, 7, 8, 10, 12}, // 31 days
            {4, 6, 9, 11},           // 30 days
            {2}                      // February
        };
        
        // Iterate over the array to determine which group each of the integers belongs to
        for (int i = 0; i < a.length; i++) {
            for (int n : a[i]) {
                if (x == n) {
                    xt = i;
                }
                if (y == n) {
                    yt = i;
                }
            }
        }
        
        // Compare the groups of x and y to determine if they belong to the same group
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        sc.close();
    }
}

// Function to return the maximum of two integers (not used in this code)
public static int max(int a, int b) {
    return a > b ? a : b;
}

// <END-OF-CODE>
