
import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		String str=sc.next();
		int sum=0;
		for(char x:str)
		{
			sum+=(x-'0');
		}
		if(sum%9==0)
		{
			System.out.println("Yes");
		}
		else
			System.out.println("No");
	}
}

