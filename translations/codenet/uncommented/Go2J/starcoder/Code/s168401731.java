import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = scanner.nextInt();
		scanner.nextLine();

		String ans = "second";
		for (int i = 0; i < n; i++) {
			int a = scanner.nextInt();
			if (a % 2 == 1) {
				ans = "first";
				break;
			}
		}
		writer.write(ans);
		writer.close();
	}
}

