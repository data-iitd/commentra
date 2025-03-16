
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		String A = in.next();
		String B = in.next();
		String C = in.next();

		int la = A.length(), lb = B.length();

		if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0))
		{
			System.out.println("YES");
		}
		else
		{
			System.out.println("NO");
		}
	}
}

