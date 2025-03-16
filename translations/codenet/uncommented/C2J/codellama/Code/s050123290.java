#include<stdio.h>
#define N 1000 

public class Main{
	public static void main(String[] args){
		char su[]=new char[N];
		int susum=0;
		int j=0;
		
		while(1){
			for(j=0;j<=N;j++){
				su[j]=System.in.read();
				if(su[j]=='\n')break;
				susum=susum+(su[j]-'0');
			}	
			if(su[0]=='0')break;
			System.out.println(susum);
			susum=0;
		}
	}
}

