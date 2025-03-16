import java.util.Scanner; // Import the Scanner class from the java.util package for input/output operations
import java.util.Vector; // Import the Vector class from the java.util package for storing the elements of the vector

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object for input/output operations

        int n = sc.nextInt(); // Read the number of elements and the size of the subarray from the user and store them in the variables n and k
        int k = sc.nextInt();

        Vector<Integer> l = new Vector<Integer>(n); // Declare a vector l of size n and initialize it with n default-constructed elements

        for(int i = 0; i < n; i++){ // Iterate through the elements of the vector l and read each element from the user
            l.add(sc.nextInt());
        }

        l.sort(null); // Sort the vector l in ascending order

        int ans = 0; // Initialize an integer variable ans to 0 for storing the sum of the first k elements in descending order

        for(int i = 0; i < k; i++){ // Iterate through the first k elements in descending order and add their values to the variable ans
            ans += l.get(n - 1 - i);
        }

        System.out.println(ans); // Output the value of the variable ans to the console
    }
}

