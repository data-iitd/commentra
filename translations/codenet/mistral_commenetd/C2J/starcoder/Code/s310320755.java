
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		while (true)
		{
			System.out.print("Enter the size of the square matrix: ");
			int n = sc.nextInt();

			if (n == 0)
			{
				break;
			}

			int r = (n + 1) / 2 + 1;
			int c = (n + 1) / 2;

			int[][] arr = new int[n + 1][n + 1];

			arr[r][c] = 1;

			int cnt = 1;
			int flag = 1;

			while (cnt!= n*n + 1)
			{
				++cnt;

				if (flag)
				{
					++r;
					++c;

					if (c > n)
					{
						c = 1;
					}

					if (r > n)
					{
						r = 1;
					}

					if (arr[r][c]!= 0)
					{
						flag = 0;
						--cnt;
					}
					else
					{
						arr[r][c] = cnt;
					}
				}
				else
				{
					++r;
					--c;

					if (c < 1)
					{
						c = n;
					}

					if (r > n)
					{
						r = 1;
					}

					if (arr[r][c]!= 0)
					{
						flag = 0;
					}
					else
					{
						arr[r][c] = cnt;
						flag = 1;
					}
				}
			}

			for (r = 1; r < n + 1; r++)
			{
				for (c = 1; c < n + 1; c++)
				{
					System.out.printf("%4d", arr[r][c]);
					arr[r][c] = 0;

					if (c == n)
					{
						System.out.println();
					}
				}
			}
		}
	}
}

