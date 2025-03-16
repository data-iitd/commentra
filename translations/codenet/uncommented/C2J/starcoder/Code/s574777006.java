
import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		int n, i, j, q, x[], y[], sum = 0;
		
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		
		x = new int[n];
		
		for( i = 0; i < n; i++) {
			x[i] = sc.nextInt();
		}
		
		q = sc.nextInt();
		
		y = new int[q];
		
		for( i = 0; i < q; i++) {
			y[i] = sc.nextInt();
		}
		
		for( i = 0; i < q; i++) {
			for( j = 0; j < n; j++) {
				if( y[i]==x[j]) {
				sum = sum + 1;
				break ;
				}
			}
		}
		
		System.out.println(sum);
		
	}

}

