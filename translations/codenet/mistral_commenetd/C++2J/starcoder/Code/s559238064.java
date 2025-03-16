import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String z = in.next();
		int a = z.length();
		for (int i = 0; i < a - 1; i++) {
			if (z.charAt(i) == z.charAt(i + 1)) {
				System.out.println("Bad");
				return;
			}
		}
		System.out.println("Good");
	}
}

