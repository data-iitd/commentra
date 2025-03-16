import java.util.*;
import java.io.*;
public class Main{
	public static void main(String[] args) throws Exception{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		E[] data=new E[n];
		rep(i,0,n){
			data[i]=new E();
			data[i].s=sc.next();
			data[i].p=sc.nextLong();
			data[i].i=i;
		}
		Arrays.sort(data,new Comparator<E>(){
			public int compare(E a,E b){
				if(a.s.compareTo(b.s)==0){
					if(a.p<b.p)return -1;
					if(a.p>b.p)return 1;
					return 0;
				}
				return a.s.compareTo(b.s);
			}
		});
		rep(i,0,n)System.out.println(data[i].i+1);
	}
	static class E{
		String s;
		long p;
		int i;
	}
}

