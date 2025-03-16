
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n,t; boolean st[]=new boolean[7];
		while(true){
			st=new StringTokenizer(br.readLine());
			n=Integer.parseInt(st.nextToken());
			if(n==-1)break;
			for(int i=0;i<7;i++)st[i]=false;
			for(int i=0;i<n;i++){
				t=Integer.parseInt(st.nextToken());
				char ans[]=new char[8];
				for(int i=0;i<7;i++){
					ans[i]=st[i]^seg[t][i]?'1':'0';
					st[i]=seg[t][i];
				}
				System.out.println(ans);
			}
		}
	}
	
	static boolean seg[][]=new boolean[10][7];
	static{
		seg[0][0]=seg[0][1]=seg[0][2]=seg[0][3]=seg[0][4]=seg[0][5]=seg[0][6]=true;
		seg[1][0]=seg[1][1]=seg[1][2]=seg[1][3]=seg[1][4]=seg[1][5]=false;
		seg[2][0]=seg[2][1]=seg[2][2]=seg[2][3]=seg[2][4]=seg[2][5]=true;
		seg[2][6]=true;
		seg[3][0]=seg[3][1]=seg[3][2]=seg[3][3]=seg[3][4]=seg[3][5]=true;
		seg[3][6]=true;
		seg[4][0]=seg[4][1]=seg[4][2]=seg[4][3]=seg[4][4]=seg[4][5]=true;
		seg[4][6]=true;
		seg[5][0]=seg[5][1]=seg[5][2]=seg[5][3]=seg[5][4]=seg[5][5]=true;
		seg[5][6]=true;
		seg[6][0]=seg[6][1]=seg[6][2]=seg[6][3]=seg[6][4]=seg[6][5]=true;
		seg[6][6]=true;
		seg[7][0]=seg[7][1]=seg[7][2]=seg[7][3]=seg[7][4]=seg[7][5]=true;
		seg[7][6]=true;
		seg[8][0]=seg[8][1]=seg[8][2]=seg[8][3]=seg[8][4]=seg[8][5]=true;
		seg[8][6]=true;
		seg[9][0]=seg[9][1]=seg[9][2]=seg[9][3]=seg[9][4]=seg[9][5]=true;
		seg[9][6]=true;
	}
}

