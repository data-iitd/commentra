
import java.util.Scanner; // Importing the Scanner class for input operations

public class s596502954{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner instance

        // Reading three integers and checking if their sum is greater than or equal to the third integer
        if (nextInt(sc) + nextInt(sc) >= nextInt(sc)) {
            System.out.println("Yes"); // Printing "Yes" if the condition is true
        } else {
            System.out.println("No"); // Printing "No" if the condition is false
        }
    }

    // nextInt() reads a single line of input as an integer
    public static int nextInt(Scanner sc) {
        return sc.nextInt();
    }
}

