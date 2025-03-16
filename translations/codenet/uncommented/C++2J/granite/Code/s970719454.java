
import java.util.*;
import java.io.*;

class s970719454{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(true){
			int n = in.nextInt();
			int m = in.nextInt();
			if(n==0 && m==0)break;
			
			boolean[] here = new boolean[n+1];
			int[] dp1 = new int[n+1];
			int[] dp2 = new int[n+1];
			
			boolean dpflg = false;
			
			for(int i=0;i<m;i++){
				int a = in.nextInt();
				if(a==0) dpflg=true;
				
				here[a]=true;
			}
			
			int maxi1 = 0;
			int maxi2 = 0;
			
			for(int i=1;i<=n;i++){
				if(here[i]){
					dp1[i] = dp1[i-1]+1;
				}
				maxi1 = Math.max(dp1[i], maxi1);
			}
			
			for(int i=1;i<=n;i++){
				if(here[i]){
					dp2[i] = dp2[i-1]+1;
				}else{
					dp2[i] = dp1[i-1]+1;
				}
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

