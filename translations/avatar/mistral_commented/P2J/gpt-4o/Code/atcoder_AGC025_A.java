import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Take an input from the user and assign it to the variable 'n'
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();

        // Initialize a list 'a' with some strings representing numbers
        List<String> a = Arrays.asList("10", "100", "1000", "10000", "100000");

        // Convert each character of the input 'n' to an integer and sum them up
        int newSum = 0;
        for (char c : n.toCharArray()) {
            newSum += Character.getNumericValue(c);
        }

        // Check if the input 'n' is present in the list 'a'
        if (a.contains(n)) {
            // If the input 'n' is present in the list 'a', then print the number 10
            System.out.println(10);
        } else {
            // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
            System.out.println(newSum);
        }

        scanner.close();
    }
}
// <END-OF-CODE>
