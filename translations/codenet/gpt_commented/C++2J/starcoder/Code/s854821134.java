import java.util.*; // Include the utility library
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object
        int a = sc.nextInt(); // Read an integer input from the user
        int b = sc.nextInt(); // Read an integer input from the user

        // Check if both a and b are less than or equal to 8
        if (a <= 8 && b <= 8) 
            System.out.println("Yay!"); // If true, print "Yay!"
        else 
            System.out.println(":("); // If false, print ":("
    }
}
