
// Include necessary header files
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare a vector to store strings and variables for input
        Vector<String> v;
        int N, L;

        // Read the number of strings (N) and the length of strings (L)
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();

        // Input N strings from the user and store them in the vector
        for(int i = 0; i < N; i++) {
            String s;
            s = sc.next();
            v.add(s); // Add the string to the vector
        }

        // Sort the vector of strings in lexicographical order
        Collections.sort(v);

        // Output the sorted strings
        for(int i = 0; i < v.size(); i++) {
            System.out.print(v.get(i)); // Print each string in the sorted order
        }
        System.out.println(); // Print a newline at the end
    }
}

