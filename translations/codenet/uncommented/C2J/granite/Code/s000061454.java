
import java.util.Scanner;

public class s000061454{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int n = sc.nextInt();
			int sum = 0;
			for(int i=1;i<=n;i++) {
				a *= 10;
				int j = 0;
				while(b*j<=a) {
					j++;
				}
				a -= b*j;
				sum += j;
			}
			System.out.println(sum);
		}
		sc.close();
	}
}
