import java.util.*;
import java.io.*;

public class Main {
    static int mod = (int) (1e9 + 7);

    // Function to read a list of integers from input
    static List<Integer> readInts() {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        List<Integer> ints = new ArrayList<>();
        for (String token : tokens) {
            ints.add(Integer.parseInt(token));
        }
        return ints;
    }

    // Main function to execute the logic
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine()); // Reading an integer input for 'n'
        List<Integer> A = readInts(); // Reading a list of integers
        Collections.sort(A); // Sorting the list of integers in ascending order
        int ans = 0; // Initializing the answer variable to accumulate the result

        // Looping through the last 2*n elements of the sorted list in reverse order
        for (int i = A.size() - 2; i >= A.size() - 2 * n - 1; i -= 2) {
            ans += A.get(i); // Adding the current element to the answer
        }

        System.out.println(ans); // Printing the final accumulated answer
    }
}
