
import java.util.*; // Import the Scanner class for input/output operations

public class s329154546{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from the console
        int N = sc.nextInt(); // Read the number of strings
        int L = sc.nextInt(); // Read the length of each string
        String[] S = new String[N]; // Create an array to store the strings
        for (int i = 0; i < N; i++) {
            S[i] = sc.next(); // Read each string and store it in the array
        }
        Arrays.sort(S); // Sort the array of strings alphabetically
        for (int i = 0; i < N; i++) {
            System.out.print(S[i]); // Output each sorted string
        }
        System.out.println(); // Output a newline character
    }
}
