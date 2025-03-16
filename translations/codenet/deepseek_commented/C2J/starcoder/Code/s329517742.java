import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a,b;
		a = sc.nextInt();
		b = sc.nextInt();
		if(500*a>=b) System.out.println("Yes");
		else System.out.println("No");
	}
}
