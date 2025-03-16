import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int N,i;
		int[] a,b;
		N=cin.nextInt();
		a=new int[N];
		b=new int[N];
		for(i=0;i<N;i++)
		{
			a[i]=cin.nextInt();
			b[i]=a[i];
		}
		Arrays.sort(b);
		int frontHalf=b[N/2-1];
		int backHalf=b[N/2];
		for(i=0;i<N;i++)
		{
			if(a[i]<backHalf)
				System.out.println(backHalf);
			else
				System.out.println(frontHalf);
		}
	}
}
