/*Lucky_Glass*/
import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int a=cin.nextInt(),b=cin.nextInt(),c=cin.nextInt();
		int tot=0;
		Queue<Integer> que=new LinkedList<Integer>();
		que.add(a*10000+b*100+c);
		while(!que.isEmpty())
		{
			int fro=que.poll();
			if(fro/10000==fro/100%10==fro%10)
			{
				System.out.println(tot);
				return;
			}
			for(int i=0;i<6;i++)
			{
				int n=fro/10000+F[i][0]+fro/100%10*F[i][1]+fro%10*F[i][2];
				if(n/10000==n/100%10==n%10) continue;
				que.add(n);
			}
			tot++;
		}
	}
}
