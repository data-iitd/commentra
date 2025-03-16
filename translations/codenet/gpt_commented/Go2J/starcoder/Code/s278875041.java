import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = a.replaceAll("1", "0");
		String ans = b.replaceAll("9", "1");
		ans = ans.replaceAll("0", "9");
		System.out.println(ans);
	}
}

