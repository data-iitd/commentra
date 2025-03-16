import java.util.*;
import java.io.*;
public class Main{
	static int n,tot;
	static int[] a,q;
	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(br.readLine());
		a=new int[n+1];
		q=new int[n+1];
		for(int i=1;i<=n;++i)	a[i]=Integer.parseInt(br.readLine());
		Arrays.sort(a,1,n+1);
		for(int i=1;i<=n;++i)	if (a[i]==a[i+1])	q[++tot]=a[i],i++;
		System.out.println(q[tot]*q[tot-1]);
	}
}
