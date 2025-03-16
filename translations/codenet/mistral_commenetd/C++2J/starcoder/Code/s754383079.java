
import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		// read string a from standard input
		Scanner sc=new Scanner(System.in);
		String a=sc.next();

		// read string b from standard input
		String b=sc.next();

		// get the length of string a
		int n=a.length();

		// get the length of string b
		int m=b.length();

		// iterate through all possible substrings of string a that have the same length as string b
		for(int i=1;i+m-1<=n;i++)
		{
			// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
			int sum=0;

			// iterate through each character in the substring of string a and compare it with the corresponding character in string b
			for(int j=1;j<=m;j++)
				// if the characters are different, increment sum by 1
				if(a.charAt(i+j-1)!=b.charAt(j))
					sum++;

			// update the minimum number of differences if a smaller number is found
			if(sum<ans)
				ans=sum;
		}

		// print the minimum number of differences to standard output
		System.out.println(ans);
	}
}

