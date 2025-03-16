import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			if(in.hasNextInt()) {
				int money = in.nextInt();
				int sum = 0;
				int[] num = new int[4];
				for(int i = 0; i < 4; ++i) {
					num[i] = in.nextInt();
					sum += num[i] * (10 << (i * 2));
				}

				int change = sum - money;
				for(int i = 3; i >= 0; --i) {
					if(change / (10 << (i * 2))) {
						num[i] = num[i] - change / (10 << (i * 2));
						change %= (10 << (i * 2));
					}
				}

				for(int i = 0; i < 4; ++i)
					if(num[i] > 0)
						System.out.println(10 << (i * 2) + " " + num[i]);
			}
			System.out.println();
		}
	}
}

