
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner sc=new Scanner(System.in);
		int n,t;
		boolean st[]=new boolean[7];
		while(sc.hasNext()){
			n=sc.nextInt();
			if(n==-1)break;
			rep(i,7)st[i]=false;
			while(n--!=0){
				t=sc.nextInt();
				char ans[]=new char[8];
				rep(i,7){
					ans[i]=(st[i]^seg[t][i])?'1':'0';
					st[i]=seg[t][i];
				}
				System.out.println(new String(ans));
			}
		}
	}
	static boolean seg[][]=new boolean[][]{
		{0,1,1,1,1,1,1},
		{0,0,0,0,1,1,0},
		{1,0,1,1,0,1,1},
		{1,0,0,1,1,1,1},
		{1,1,0,0,1,1,0},
		{1,1,0,1,1,0,1},
		{1,1,1,1,1,0,1},
		{0,1,0,0,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,0,1,1,1,1}
	};
}

