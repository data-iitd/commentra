import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		int a, b, c, ans=0;
		for(a=1;a<=k;a++){
			for(b=1;b<=k;b++){
				for(c=1;c<=k;c++){
					ans+=gcd(a, gcd(b, c));
				}
			}
		}
		System.out.println(ans);
	}
	public static int gcd(int a, int b){
		if(b==0) return a;
		return gcd(b, a%b);
	}
}
