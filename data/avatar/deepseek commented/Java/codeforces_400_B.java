
import java.util.HashMap; // Importing HashMap for potential future use
import java.util.HashSet; // Importing HashSet to store unique differences
import java.util.Scanner; // Importing Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize Scanner to read input
        int n = sc.nextInt(); // Read the first integer input (number of strings)
        int m = sc.nextInt(); // Read the second integer input (possibly not used in this code)

        String arrs[] = new String[n]; // Declare and initialize array to store strings
        for (int i = 0; i < n; i++) {
            arrs[i] = sc.next(); // Read each string and store it in the array
        }

        int length[] = new int[n]; // Declare and initialize array to store differences
        int index = 0; // Initialize index for the length array
        int returnDex = 0; // Initialize returnDex to store the result

        for (String tmp : arrs) { // Loop through each string in the array
            int dexG = tmp.indexOf("G"); // Find the index of 'G' in the string
            int dexS = tmp.indexOf("S"); // Find the index of 'S' in the string
            if (dexG > dexS) { // Check if 'G' comes after 'S'
                returnDex = -1; // Set returnDex to -1 if 'G' is after 'S'
            }
            length[index++] = dexS - dexG; // Calculate and store the difference in length array
        }

        HashSet<Integer> set = new HashSet<Integer>(); // Initialize HashSet to store unique differences
        for (int len : length) { // Loop through each difference in the length array
            set.add(len); // Add the difference to the HashSet
        }

        if (returnDex == -1) { // Check if returnDex is -1
            System.out.println(returnDex); // Print -1 if 'G' comes after 'S'
        } else {
            System.out.println(set.size()); // Print the size of the HashSet if 'G' does not come after 'S'
        }
    }
}

