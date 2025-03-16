import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int count=0;
		while(sc.hasNextInt()){
			count++;
			int n=sc.nextInt();
			int cnt=0;
			for(int i=n;i>0;i--){
				if(isPrime(i)){
					cnt++;
				}
			}
			System.out.println(cnt);
			if(count==30)break;
		}
	}
	public static boolean isPrime(int n){
		if(n==1)return false;
		if(n==2)return true;
		for(int i=2;i*i<=n;i++){
			if(n%i==0)return false;
		}
		return true;
	}
}
