import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input

        String s = sc.nextLine(); // Read a string input from the user and store it in s

        // Construct the abbreviated version of the string
        String t = s.charAt(0) + (s.length() - 2) + s.charAt(s.length() - 1);

        System.out.println(t); // Output the abbreviated string
    }
}

