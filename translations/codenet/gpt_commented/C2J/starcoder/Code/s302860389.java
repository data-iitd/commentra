import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        // Create a Scanner object to read input from stdin
        Scanner input = new Scanner(System.in);

        // Read a string of numbers from user input
        String inputNumbers = input.next();

        // Convert each character to an integer and store in respective variables
        int a = Character.getNumericValue(inputNumbers.charAt(0));
        int b = Character.getNumericValue(inputNumbers.charAt(1));
        int c = Character.getNumericValue(inputNumbers.charAt(2));
        int d = Character.getNumericValue(inputNumbers.charAt(3));

        // Iterate through all combinations of addition and subtraction for the four numbers
        for (int i = 0; i < 2; i++) // Loop for the first operation (a + b or a - b)
        {
            for (int j = 0; j < 2; j++) // Loop for the second operation (result + c or result - c)
            {
                for (int k = 0; k < 2; k++) // Loop for the third operation (result + d or result - d)
                {
                    // Determine the first operation (addition or subtraction with a and b)
                    int sum;
                    if (i == 0)
                    {
                        sum = a + b; // Perform addition
                    }
                    else
                    {
                        sum = a - b; // Perform subtraction
                    }

                    // Determine the second operation (addition or subtraction with c)
                    if (j == 0)
                    {
                        sum = sum + c; // Perform addition
                    }
                    else
                    {
                        sum = sum - c; // Perform subtraction
                    }

                    // Determine the third operation (addition or subtraction with d)
                    if (k == 0)
                    {
                        sum = sum + d; // Perform addition
                    }
                    else
                    {
                        sum = sum - d; // Perform subtraction
                    }

                    // Check if the calculated sum equals 7
                    if (sum == 7)
                    {
                        // Print the expression that results in 7
                        System.out.printf("%d%c%d%c%d%c%d=7\n", a, (i == 0? '+' : '-'), b, (j == 0? '+' : '-'), c, (k == 0? '+' : '-'), d);
                        
                        return; // Exit the program after finding the first valid expression
                    }
                }
            }
        }
    }
}
