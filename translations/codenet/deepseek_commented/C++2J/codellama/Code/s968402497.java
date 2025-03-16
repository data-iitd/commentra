
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int tc=sc.nextInt();
		int n=sc.nextInt();
		int m=sc.nextInt();
		if(n>m) {
			int temp=n;
			n=m;
			m=temp;
		}
		for(int i=1;i<=m;i++) {
			if(i*tc>=n&&i*tc<=m) {
				System.out.println("OK");
				break;
			}
		}
		if(i>m) System.out.println("NG");
		sc.close();
	}
}

