
import java.util.Scanner;
// Import the Scanner class from the java.util package

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        // Create a new Scanner object sc that reads from the standard input

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        // Use the nextInt method of the Scanner class to read three integers
        // from the standard input and assign them to the variables a, b, and c

        if(a<b && b<c)
        {
            System.out.println("Yes");
            // If the condition a < b && b < c is true, print the string "Yes"
            // followed by a newline character to the standard output
        }
        else
        {
            System.out.println("No");
            // If the condition a < b && b < c is false, print the string "No"
            // followed by a newline character to the standard output
        }

        sc.close();
        // Close the Scanner object sc
    }
}

