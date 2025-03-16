
import java.util.Scanner;

public class s783753345{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while (true) {
			int a = scanner.nextInt();
			char S = scanner.next().charAt(0);
			int b = scanner.nextInt();
			
			if (S == '+') System.out.println(a + b);
			if (S == '-') System.out.println(a - b);
			if (S == '*') System.out.println(a * b);
			if (S == '/') System.out.println(a / b);
			
			if (S == '?') break;
		}
	}
}
// END-OF-CODE