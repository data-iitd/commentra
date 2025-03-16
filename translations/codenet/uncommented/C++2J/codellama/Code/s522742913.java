import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String source = sc.next();
		if (source.length() > 10 || source.length() < 1) {
			System.out.println("-1");
			return;
		}
		int max_i = (int) Math.pow(2, source.length() - 1);
		double sum = 0;
		for (int i = 0; i < max_i; ++i) {
			String plus = Integer.toBinaryString(i);
			String working = source;
			while (plus.length() > 0) {
				int i = 0;
				while (plus.charAt(i) == '0')
					++i;
				sum += Double.parseDouble(working.substring(0, i + 1));
				plus = plus.substring(i + 1);
				working = working.substring(i + 1);
			}
			sum += Double.parseDouble(working);
		}
		System.out.printf("%.0f\n", sum);
	}
}

