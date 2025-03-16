import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x, ans = 0;

		x = in.nextInt();

		ans = x + x*x + x*x*x;

		System.out.println(ans);
	}
}

