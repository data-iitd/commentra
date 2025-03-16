
import java.util.*;
import java.lang.*;
import java.io.*;

class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		String str=sc.nextLine();
		int sum=0;
		for(char x:str.toCharArray())
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
