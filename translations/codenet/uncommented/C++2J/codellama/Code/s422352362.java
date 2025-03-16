import java.util.*;
import java.lang.*;
import java.io.*;
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long a[] = new long[200005];
		long pre[] = new long[200005];
		long last[] = new long[200005];
		for(int i = 1;i<=n;i++){
			a[i] = sc.nextLong();
		}
		long sumpre = 0,sumlast = 0;
		for(int i = 1;i<n;i++){
			sumpre = sumpre + a[i];
			pre[i] = sumpre;
		}
		for(int i = n;i>1;i--){
			sumlast = sumlast + a[i];
			last[i] = sumlast;
		}
		long d = (long)Math.pow(10,18);
		for(int i = 1;i<n;i++){
			d = Math.min(d,Math.abs(pre[i]-last[i + 1]));
		}
		System.out.println(d);
	}
}
