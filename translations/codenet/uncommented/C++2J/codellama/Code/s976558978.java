/*
URL_HERE
*/
/*

*/
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner fin = new Scanner(System.in);
		PrintWriter fout = new PrintWriter(System.out);
		int a = fin.nextInt();
		int b = fin.nextInt();
		if (a < b) {
			for (int i = 0; i < b; ++i) {
				fout.print(a + " ");
			}
			fout.println();
		} else {
			for (int i = 0; i < a; ++i) {
				fout.print(b + " ");
			}
			fout.println();
		}
		fout.close();
	}
}
