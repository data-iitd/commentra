
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int a, b, c;
        // Declare three integer variables: a, b, and c

        a = input.nextInt();
        b = input.nextInt();
        c = input.nextInt();
        // Use the nextInt function to read three integers from the standard
        // input and assign them to the variables a, b, and c respectively

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
    }
}

