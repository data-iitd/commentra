import java.util.*; // Import the Scanner class

public class Main
{
    public static String check(int x, int y) // Function declaration: check takes two integer arguments and returns a string
    {
        if(y % 2 == 0) // Check if y is even
        {
            int t = (int)(0.5*y) - x; // Calculate t as half of y minus x

            if(t >= 0 && (x-t) >= 0) // Check if t is greater than or equal to zero and if x - t is also greater than or equal to zero
            {
                return "Yes"; // If both conditions are true, return "Yes"
            }
        }

        return "No"; // If y is not even, return "No"
    }

    public static void main(String[] args) // Main function declaration
    {
        Scanner input = new Scanner(System.in); // Create a Scanner object to read input from standard input

        int x = input.nextInt(); // Read input value for x from standard input
        int y = input.nextInt(); // Read input value for y from standard input

        System.out.println(check(x, y)); // Call check function with input values and print its return value to standard output
    }
}

