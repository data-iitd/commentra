
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// Your code goes here
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] here = new int[100001];
			int[] dp1 = new int[100001];
			int[] dp2 = new int[100001];
			for(int i=0;i<100001;i++){
				here[i]=dp1[i]=dp2[i]=0;
			}
			boolean dpflg = false;
			for(int i=0;i<m;i++){
				int a = sc.nextInt();
				here[a]=1;
				if(a==0) dpflg=true;
			}
			int maxi1 = 0;
			for(int i=1;i<=n;i++){
				if(here[i]==1)dp1[i] = dp1[i-1]+1;
				maxi1 = Math.max(dp1[i], maxi1);
			}
			int maxi2 = 0;
			for(int i=1;i<=n;i++){
				if(here[i]==1)dp2[i] = dp2[i-1]+1;
				else dp2[i] = dp1[i-1]+1;
				maxi2 = Math.max(dp2[i], maxi2);
			}
			if(!dpflg){
				System.out.println(maxi1);
			}else{
				System.out.println(maxi2);
			}
		}
	}
}

