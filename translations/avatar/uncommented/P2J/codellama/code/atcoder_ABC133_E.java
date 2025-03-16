import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main ( String[] args ) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		HashMap<Integer,ArrayList<Integer>> graph = new HashMap<Integer,ArrayList<Integer>>();
		for(int i=0;i<N-1;i++)
		{
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(graph.containsKey(a))
			{
				graph.get(a).add(b);
			}
			else
			{
				ArrayList<Integer> temp = new ArrayList<Integer>();
				temp.add(b);
				graph.put(a,temp);
			}
			if(graph.containsKey(b))
			{
				graph.get(b).add(a);
			}
			else
			{
				ArrayList<Integer> temp = new ArrayList<Integer>();
				temp.add(a);
				graph.put(b,temp);
			}
		}
		long mod = 1000000007;
		long ans = dfs(0,-1,K);
		System.out.println(ans);
	}
	public static long dfs(int fro,int to,int f)
	{
		long caseNum = f;
		int colorNum = K-1;
		if(f==K)
		{
			colorNum = K-2;
		}
		ArrayList<Integer> temp = graph.get(fro);
		for(int i=0;i<temp.size();i++)
		{
			if(temp.get(i)==to)
			{
				continue;
			}
			long pat = dfs(temp.get(i),fro,colorNum);
			if(pat==0)
			{
				caseNum = 0;
				break;
			}
			caseNum = (caseNum*pat)%mod;
			colorNum--;
		}
		return caseNum;
	}
}



Translate the above Java code to C++ and end with comment "