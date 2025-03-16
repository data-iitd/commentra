
import java.util.Scanner;

public class s663381244{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean first = true;
		while(sc.hasNextInt()) {
			if(!first)
				System.out.println();

			first = false;
			int sum = 0;
			int[] num = new int[4];
			for(int i = 0; i < 4; ++i) {
				num[i] = sc.nextInt();
				sum += num[i] * 10;
			}

			int change = sum - sc.nextInt();
			for(int i = 3; i >= 0; --i) {
				if(change / 10 >= 1) {
					num[i] = num[i] - change / 10;
					change %= 10;
				}
			}

			for(int i = 0; i < 4; ++i)
				if(num[i] > 0)
					System.out.println(10 + " " + num[i]);
		}
		sc.close();
	}
}

