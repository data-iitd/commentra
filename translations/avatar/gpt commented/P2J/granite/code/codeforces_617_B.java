
import java.util.Scanner;  // Import the Scanner class to read input from the user

public class codeforces_617_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input from the user

        scanner.nextLine();  // Read an input line (not used in further calculations)

        String a = scanner.nextLine();  // Read a string input from the user

        // Check if the string contains any '1's
        // If there are no '1's, print 0
        // Otherwise, calculate the product of counts of '0's between '1's
        System.out.println(a.chars().filter(ch -> ch == '1').count() == 0? 0 : 
                IntStream.of(a.replaceAll("0+", " ").split(" ")).map(s -> s.chars().filter(ch -> ch == '0').count() + 1).reduce(1, (a1, a2) -> a1 * a2)); 
                // Split the input string by '1's, count '0's in each segment, add 1 to each count,
                // and calculate the product of these counts

        scanner.close();  // Close the Scanner object to release system resources
    }
}

Translate the above Java code to C++ and end with comment "