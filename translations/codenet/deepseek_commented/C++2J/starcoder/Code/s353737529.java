
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		if(n == 0){
			System.out.println('0');
			return;
		}

		String s = "";

		while(n!= 0){
			if(n % 2 == 0){
				s += '0';
			} else {
				s += '1';
			}

			n -= Math.abs(n % 2);

			n /= -2;
		}

		System.out.println(new StringBuilder(s).reverse());
	}
}

