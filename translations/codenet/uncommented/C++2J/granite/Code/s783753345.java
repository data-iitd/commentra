
import java.util.Scanner;
public class s783753345{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int a = sc.nextInt();
			String S = sc.next();
			int b = sc.nextInt();
			if (S.equals("+")) System.out.println(a + b);
			if (S.equals("-")) System.out.println(a - b);
			if (S.equals("*")) System.out.println(a * b);
			if (S.equals("/")) System.out.println(a / b);
			if (S.equals("?")) break;
		}
	}
}
