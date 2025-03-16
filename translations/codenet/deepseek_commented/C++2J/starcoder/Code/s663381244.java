import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int money = sc.nextInt();
			if(money == 0)
				break;

			if(!first)
				System.out.println();
			first = false;

			int sum = 0;
			int[] num = new int[4];
			for(int i = 0; i < 4; ++i) {
				num[i] = sc.nextInt();
				sum += num[i] * m[i];
			}

			int change = sum - money;
			for(int i = 3; i >= 0; --i) {
				if(change / m[i]) {
					num[i] = num[i] - change / m[i];
					change %= m[i];
				}
			}

			for(int i = 0; i < 4; ++i)
				if(num[i] > 0)
					System.out.println(m[i] + " " + num[i]);
		}
	}
}

