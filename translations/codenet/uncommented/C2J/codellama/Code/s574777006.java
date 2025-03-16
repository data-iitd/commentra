
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[] x = new int[10000];
		
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}
		
		int q = sc.nextInt();
		int[] y = new int[500];
		
		for(int i = 0; i < q; i++) {
			y[i] = sc.nextInt();
		}
		
		int sum = 0;
		
		for(int i = 0; i < q; i++) {
			for(int j = 0; j < n; j++) {
				if(y[i] == x[j]) {
					sum = sum + 1;
					break;
				}
			}
		}
		
		System.out.println(sum);
		
		sc.close();
	}
}

