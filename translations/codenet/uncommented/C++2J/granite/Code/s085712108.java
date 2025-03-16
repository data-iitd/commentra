
/*Lucky_Glass*/
import java.util.*;
public class s085712108{
	static int[][] F={{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}};
	static int MOD=7007;
	static Vector<Integer>[] Hash=new Vector[MOD];
	static boolean HASH(int n)
	{
		for(int i=0;i<Hash[n%MOD].size();i++)
			if(n==Hash[n%MOD].get(i))
				return false;
		Hash[n%MOD].add(n);
		return true;
	}
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt(),b=in.nextInt(),c=in.nextInt();
		Queue<int[]> que=new LinkedList<int[]>();
		que.add(new int[]{a,b,c,0});
		while(!que.isEmpty())
		{
			int[] Fro=que.poll();
			if(Fro[0]==Fro[1]&&Fro[1]==Fro[2])
			{
				System.out.println(Fro[3]);
				return;
			}
			for(int i=0;i<6;i++)
			{
				int[] Push=Fro.clone();
				Push[3]++;
				Push[0]+=F[i][0];Push[1]+=F[i][1];Push[2]+=F[i][2];
				int n=Push[0]*10000+Push[1]*100+Push[2];
				if(!HASH(n)) continue;
				que.add(Push);
			}
		}
	}
}
