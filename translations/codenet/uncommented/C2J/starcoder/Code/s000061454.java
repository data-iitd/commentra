import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			int n=sc.nextInt();
			a-=a/b*b;
			int sum=0;
			for(int i=1;i<=n;i++) {
				a*=10;
				for(int j=9;j>=0;j--) {
					if(b*j<=a)break;
				}
				a-=b*j;
				sum+=j;
			}
			System.out.println(sum);
		}
	}
}
