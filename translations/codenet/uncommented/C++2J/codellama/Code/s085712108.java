/*Lucky_Glass*/
import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		int a,b,c,tot;
		int[][] F={{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}};
		int MOD=7007;
		int[] Hash=new int[MOD];
		Queue<Integer> que=new LinkedList<Integer>();
		Scanner sc=new Scanner(System.in);
		a=sc.nextInt();
		b=sc.nextInt();
		c=sc.nextInt();
		que.add(a*10000+b*100+c);
		while(!que.isEmpty())
		{
			int Fro=que.poll();
			a=Fro/10000;
			b=(Fro%10000)/100;
			c=Fro%100;
			if(a==b && b==c)
			{
				System.out.println(tot);
				return;
			}
			for(int i=0;i<6;i++)
			{
				a+=F[i][0];
				b+=F[i][1];
				c+=F[i][2];
				int n=a*10000+b*100+c;
				if(Hash[n%MOD]!=0) continue;
				Hash[n%MOD]=n;
				que.add(n);
			}
			tot++;
		}
	}
}
