import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        // Declare a 4x4 array to hold input values and a variable for test cases
        int input[][] = new int[4][4];
        int tc;

        // Read 3x3 input values from the user
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                input[i][j] = Integer.parseInt(args[0]); // Store each input value in the array
            }
        }

        // Read the number of test cases
        tc = Integer.parseInt(args[1]);
        int testcase;

        // Process each test case
        for(int i = 0; i < tc; i++)
        {
            testcase = Integer.parseInt(args[2]); // Read the current test case value

            // Check the input array for the testcase value and set it to 0 if found
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(input[i][j] == testcase)
                    {
                        input[i][j] = 0; // Replace the found value with 0
                    }
                }
            }
        }

        // Check for winning conditions in the modified input array
        if(input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0) // Check diagonal from top-left to bottom-right
        {
            System.out.println("Yes");
        }
        else if(input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0) // Check diagonal from top-right to bottom-left
        {
            System.out.println("Yes");
        }
        else if(input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0) // Check first row
        {
            System.out.println("Yes");
        }
        else if(input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0) // Check second row
        {
            System.out.println("Yes");
        }
        else if(input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0) // Check third row
        {
            System.out.println("Yes");
        }
        else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0) // Check first column
        {
            System.out.println("Yes");
        }
        else if(input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0) // Check second column
        {
            System.out.println("Yes");
        }
        else if(input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0) // Check third column
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No"); // If no winning condition is met, output "No"
        }
    }
}
