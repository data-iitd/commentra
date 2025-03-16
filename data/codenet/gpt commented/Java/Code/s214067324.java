import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input from the user and parse it
        int x = Integer.parseInt(sc.next());
        
        // Check if the input integer is less than 1200
        // If true, print "ABC"; otherwise, print "ARC"
        System.out.println(x < 1200 ? "ABC" : "ARC");
        
        // Close the scanner to prevent resource leaks (optional but good practice)
        sc.close();
    }
}
