
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int d = in.nextInt();

		double a = d*2+1;
		System.out.println( (int) Math.ceil(n/a) );
	}
}

