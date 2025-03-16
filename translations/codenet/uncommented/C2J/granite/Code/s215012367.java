
import java.util.Scanner;

public class s215012367{

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();

		int s = (a*b) - (a + b) + 1;

		System.out.println(s);

		sc.close();

	}

}

