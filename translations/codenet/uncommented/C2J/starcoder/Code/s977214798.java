import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] a = new int[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n-1; j++){
				a[i][j] = sc.nextInt()-1;
			}
		}
		int[] e1 = new int[n*n];
		int[] e2 = new int[n*n];
		int[] d = new int[n*n];
		boolean[] b = new boolean[n*n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n-2; j++){
				int from = i*n+a[i][j];
				int to = i*n+a[i][j+1];
				if(e1[from]==0){
					e1[from]=to;
				}else if(e2[from]==0){
					e2[from]=to;
				}else{
					System.out.println("-1");
					return;
				}
			}
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int from = i*n+a[i][0];
			int now=0;
			while(true){
				if(b[from]) break;
				if(d[from]!=0) break;
				b[from]=true;
				int to;
				to = e1[from];
				int max=0;
				if(to!=0){
					int now2=now;
					now=d[to];
					if(now<0) break;
					if(now>max) max=now;
					if(now2>max) max=now2;
				}
				to = e2[from];
				if(to!=0){
					int now2=now;
					now=d[to];
					if(now<0) break;
					if(now>max) max=now;
					if(now2>max) max=now2;
				}
				b[from]=false;
				d[from]=max+1;
				now++;
			}
			if(now<0){
				ans=-1;
				break;
			}
			if(now>ans) ans=now;
		}
		System.out.println(ans);
	}
}

