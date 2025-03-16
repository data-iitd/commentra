import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n,i,cnt;

		while(1){
			n = sc.nextInt();
			if(n == 0){
				break;
			}
			i = 2;
			cnt = 0;
			while(i*2 <= n){
				if(!isPrime(i) &&!isPrime(n-i)){
					cnt++;
				}
				i++;
			}
			System.out.println(cnt);
		}
	}

	public static boolean isPrime(int n){
		if(n == 1){
			return false;
		}
		if(n == 2){
			return true;
		}
		if(n%2 == 0){
			return false;
		}
		for(int i = 3;i*i <= n;i+=2){
			if(n%i == 0){
				return false;
			}
		}
		return true;
	}
}

