
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// Your code goes here
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ta = sc.nextInt();
		int ao = sc.nextInt();
		ta--; ao--;
		ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<n;i++)
			g.add(new ArrayList<Integer>());
		for(int i=0;i<n-1;i++)
		{
			int a = sc.nextInt();
			int b = sc.nextInt();
			g.get(a-1).add(b-1);
			g.get(b-1).add(a-1);
		}
		int[] ta_dist = new int[n];
		int[] ao_dist = new int[n];
		ta_dist[ta] = 0;
		ao_dist[ao] = 0;
		dfs(g,ta,ta_dist);
		dfs(g,ao,ao_dist);
		int res = 0;
		for(int i=0;i<n;i++)
		{
			if(ta_dist[i]==-1 || ao_dist[i]==-1 || ta_dist[i]>ao_dist[i])
				continue;
			res = Math.max(res,ao_dist[i]);
		}
		System.out.println(res-1);
	}
	public static void dfs(ArrayList<ArrayList<Integer>> g,int node,int[] dist)
	{
		for(int v:g.get(node))
		{
			if(dist[v]!=-1)
				continue;
			dist[v] = dist[node]+1;
			dfs(g,v,dist);
		}
	}
}

