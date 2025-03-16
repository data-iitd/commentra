import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read input from the user
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();

        // Define a list of string representations of powers of ten
        List<String> a = Arrays.asList("10", "100", "1000", "10000", "100000");

        // Convert the input string into a list of integers and calculate the sum
        int newSum = 0;
        for (char c : n.toCharArray()) {
            newSum += Character.getNumericValue(c);
        }

        // Check if the input is one of the predefined values in the list 'a'
        if (a.contains(n)) {
            // If the input matches one of the predefined values, print 10
            System.out.println(10);
        } else {
            // If the input does not match, print the calculated sum
            System.out.println(newSum);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
