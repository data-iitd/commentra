import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		E[] data=new E[n];
		for(int i=0;i<n;i++){
			data[i]=new E();
			data[i].s=sc.next();
			data[i].p=sc.nextLong();
			data[i].i=i;
		}
		Arrays.sort(data,new Comparator<E>(){
			public int compare(E a,E b){
				if(a.s.compareTo(b.s)==0)
					return a.p<b.p?-1:a.p>b.p?1:0;
				return a.s.compareTo(b.s);
			}
		});
		for(int i=0;i<n;i++)
			System.out.println(data[i].i+1);
	}
}
