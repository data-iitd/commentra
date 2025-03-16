import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Scanner to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of strings N and the length L
        long N = scanner.nextLong();
        long L = scanner.nextLong();
        scanner.nextLine(); // Consume the newline character

        // List to store strings
        List<String> v = new ArrayList<>();

        // Read N strings from the standard input and store them in the list v
        for (long i = 0; i < N; i++) {
            String s = scanner.nextLine();
            v.add(s);
        }

        // Sort the list v in lexicographical order
        Collections.sort(v);

        // Concatenate and print the sorted strings without spaces
        for (String s : v) {
            System.out.print(s);
        }
        System.out.println();
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
