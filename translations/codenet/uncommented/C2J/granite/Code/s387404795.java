
import java.util.Scanner;

public class s387404795{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		String tmp = sc.next();
		String p = tmp + str;
		int slen = p.length();
		int plen = tmp.length();
		int i, j, flag = 0;
		
		for (i = 0; i < slen - plen; i++) {
			if (p.substring(i, i + plen).equals(tmp)) flag = 1;
		}
		
		if (flag == 1) System.out.println("Yes");
		else System.out.println("No");
		
		sc.close();
	}
}
