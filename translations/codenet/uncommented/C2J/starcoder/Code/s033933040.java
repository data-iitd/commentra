
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a,b,mawari,menseki;
		
		a = in.nextInt();
		b = in.nextInt();
		mawari=a+a+b+b;
		menseki=a*b;
		System.out.println(menseki+" "+mawari);
	}
}

