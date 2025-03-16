import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input from stdin

        int n = sc.nextInt();  // Read the number of sides from user input

        // Calculate the sum of the interior angles of a polygon with 'n' sides
        // The formula for the sum of interior angles is (n - 2) * 180
        System.out.println((n - 2) * 180);  // Output the calculated sum of interior angles

        sc.close();  // Close the Scanner object
    }
}
