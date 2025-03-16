
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws java.lang.Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		double a = d*2+1;
		System.out.println(Math.ceil(n/a));
	}
}

