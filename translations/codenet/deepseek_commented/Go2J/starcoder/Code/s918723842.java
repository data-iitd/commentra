package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// Reads three integers H, W, and N from the standard input.
		int H = sc.nextInt();
		int W = sc.nextInt();
		int N = sc.nextInt();
		
		// Determines the maximum of H and W and assigns it to A.
		int A = Math.max(H, W);
		
		// Calculates the result by dividing N by A and rounding up.
		// This is done by adding N-1 to the division result and then performing integer division by A.
		System.out.println((N + A - 1) / A);
	}
}

