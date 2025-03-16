
package main;

import java.io.*;
import java.util.*;

public class HelloWorld {

	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);

		String sage = stdin.nextLine();

		switch (sage) {
		case "1":
			System.out.println("Hello World");
			break;
		case "2":
			int sum = 0;
			for (int i = 0; i < 2; i++) {
				int num = Integer.parseInt(stdin.nextLine());
				sum += num;
			}
			System.out.println(sum);
			break;
		}
	}
}

// End of code

