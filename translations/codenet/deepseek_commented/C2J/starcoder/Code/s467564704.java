import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		// Declare a 3x3 matrix to store the input
		int input[][] = new int[3][3];
		
		// Read the 3x3 matrix from the user
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				input[i][j] = Integer.parseInt(args[i*3+j]);
			}
		}
		
		// Read the number of test cases
		int tc = Integer.parseInt(args[9]);
		
		// Variable to store the current test case
		int testcase;
		
		// Loop through each test case
		for(int i = 0;i<tc;i++)
		{
			// Read the test case value
			testcase = Integer.parseInt(args[10+i]);
			
			// Loop through the matrix to zero out the corresponding elements
			for(int i = 0;i<3;i++)
			{
				for(int j = 0;j<3;j++)
				{
					if(input[i][j] == testcase)
					{
						input[i][j] = 0;
					}
				}
			}
		}
		
		// Check for winning conditions for a Tic-Tac-Toe game
		if(input[0][0] == 0 && input[1][1] == 0 && input[2][2] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[0][2] == 0 && input[1][1] == 0 && input[2][0] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[0][0] == 0 && input[0][1] == 0 && input[0][2] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[1][0] == 0 && input[1][1] == 0 && input[1][2] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[2][0] == 0 && input[2][1] == 0 && input[2][2] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[0][1] == 0 && input[1][1] == 0 && input[2][1] == 0)
		{
			System.out.println("Yes");
		}
		else if(input[0][2] == 0 && input[1][2] == 0 && input[2][2] == 0)
		{
			System.out.println("Yes");
		}
		else
		{
			System.out.println("No");	
		}
	}
}
