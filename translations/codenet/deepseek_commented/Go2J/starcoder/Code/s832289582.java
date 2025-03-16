package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int P = sc.nextInt();
		String S = sc.next();
		System.out.println(checkSubNumbers(N, P, S));
	}

	// checkSubNumbers determines whether P is 2 or 5 and calls the appropriate helper function.
	public static int checkSubNumbers(int N, int P, String S) {
		switch (P) {
		case 2, 5:
			return checkTwoOrFive(N, P, S); // If P is 2 or 5, call checkTwoOrFive.
		default:
			return checkNotTwoNorFive(N, P, S); // Otherwise, call checkNotTwoNorFive.
		}
	}

	// checkTwoOrFive iterates over the string S from the end to the beginning, checking if the last digit of each substring is divisible by P.
	public static int checkTwoOrFive(int N, int P, String S) {
		int answer = 0;
		int n;
		for (int i = N - 1; i >= 0; i--) {
			n = S.charAt(i) - '0'; // Convert the current character to an integer.
			if (n % P == 0) { // Check if the integer is divisible by P.
				answer += i + 1; // If it is, add the position to the answer.
			}
		}
		return answer;
	}

	// checkNotTwoNorFive uses a rolling hash approach to efficiently determine the number of substrings of S that are divisible by P.
	public static int checkNotTwoNorFive(int N, int P, String S) {
		int multiplier = 1; // 10^i % P
		int answer = 0;
		int[] remainderLookup = new int[P]; // Create a slice to store the counts of remainders.
		int prevRemaider = -1;
		int digit, remainder, count;
		for (int i = N - 1; i >= 0; i--) {
			digit = S.charAt(i) - '0'; // Convert the current character to an integer.
			if (prevRemaider == -1) { // If it's the first digit, calculate the remainder directly.
				remainder = digit % P;
			} else { // Otherwise, use the rolling hash approach.
				remainder = (((multiplier * digit) % P) + prevRemaider) % P;
			}
			if (remainder == 0) { // If the remainder is 0, increment the answer.
				answer++;
			}
			count = remainderLookup[remainder]; // Get the current count of this remainder.
			answer += count; // Add the count to the answer.
			count++; // Increment the count.
			remainderLookup[remainder] = count; // Update the count in the slice.
			prevRemaider = remainder; // Update the previous remainder.
			multiplier = (multiplier * 10) % P; // Update the multiplier for the next iteration.
		}
		return answer;
	}
}

