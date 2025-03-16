import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		long[] a=new long[n];
		for(int i=0;i<n;i++)a[i]=sc.nextLong();
		PriorityQueue<Long> pq=new PriorityQueue<Long>();
		for(int i=0;i<n;i++)pq.add(a[i]);
		for(int i=0;i<m;i++){
			long tm=pq.poll();
			tm/=2;
			pq.add(tm);
		}
		long ans=0;
		while(!pq.isEmpty())ans+=pq.poll();
		System.out.println(ans);
	}
}

