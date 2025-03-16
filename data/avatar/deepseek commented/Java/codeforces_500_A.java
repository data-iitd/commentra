import java.util.*; // Importing the necessary package for input and other utilities

public class Main {
    // Main class definition

    public static boolean dfs(int currpos, int[] arr, int target) {
        // Depth-first search method to find if the target position can be reached
        if (currpos == target) return true; // If current position is the target, return true
        if (currpos == arr.length + 1) return false; // If current position exceeds array length, return false

        boolean teleport = dfs(currpos + arr[currpos - 1], arr, target); // Recursive call with teleported position
        if (teleport) return true; // If teleportation leads to the target, return true
        return false; // Otherwise, return false
    }

    public static void main(String[] args) throws Exception {
        // Main method where the program execution begins
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        int n = sc.nextInt(); // Reading the number of elements in the array
        int goal = sc.nextInt(); // Reading the target position
        int[] arr = new int[n - 1]; // Initializing the array with n-1 elements

        for (int i = 0; i < n - 1; i++) {
            arr[i] = sc.nextInt(); // Reading the array elements
        }

        boolean isFound = dfs(1, arr, goal); // Calling the dfs method with initial position 1
        if (isFound) System.out.println("YES"); // If the target position is found, print "YES"
        else System.out.println("NO"); // Otherwise, print "NO"

        sc.close(); // Closing the Scanner object
    }
}
