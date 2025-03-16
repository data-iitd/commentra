
import java.util.Scanner;
public class s218426876{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x;
		int sum = 0;
		int flag = 0;
		while (true) {
			x = sc.nextLine();
			if (x.equals("0")) {
				break;
			}
			for (int i = 0; i < x.length(); i++) {
				sum += x.charAt(i) - '0';
			}
			System.out.println(sum);
			sum = 0;
		}
	}
}
