import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main ( String[] args ) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ta = sc.nextInt();
		int ao = sc.nextInt();
		ta--;
		ao--;
		ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<n;i++){
		    g.add(new ArrayList<Integer>());
		}
		for(int i=0;i<n-1;i++){
		    int a = sc.nextInt();
		    int b = sc.nextInt();
		    a--;
		    b--;
		    g.get(a).add(b);
		    g.get(b).add(a);
		}
		int[] ta_dist = new int[n];
		ta_dist[ta] = 0;
		int[] ao_dist = new int[n];
		ao_dist[ao] = 0;
		dfs(ta,ta_dist,g);
		dfs(ao,ao_dist,g);
		int res = 0;
		for(int i=0;i<n;i++){
		    if(ta_dist[i]>ao_dist[i]) continue;
		    res = Math.max(res,ao_dist[i]);
		}
		System.out.println(res-1);
	}
	public static void dfs(int node,int[] dist,ArrayList<ArrayList<Integer>> g){
	    for(int v:g.get(node)){
	        if(dist[v]!=0) continue;
	        dist[v] = dist[node]+1;
	        dfs(v,dist,g);
	    }
	}
}
