import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int input[][] = new int[3][3];
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<3;j++)
			{
				input[i][j] = sc.nextInt();
			}
		}
		int tc = sc.nextInt();
		for(int i = 0;i<tc;i++)
		{
			int testcase = sc.nextInt();
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
