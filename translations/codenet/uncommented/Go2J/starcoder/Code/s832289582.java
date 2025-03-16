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

    // N: [1, 2e5]
    // len(S) = N
    // P: [2, 10000], prime
    public static int checkSubNumbers(int N, int P, String S) {
        switch (P) {
            case 2:
            case 5:
                return checkTwoOrFive(N, P, S);
            default:
                return checkNotTwoNorFive(N, P, S);
        }
    }

    public static int checkTwoOrFive(int N, int P, String S) {
        int answer = 0;
        int n;
        for (int i = N - 1; i >= 0; i--) {
            n = Integer.parseInt(S.substring(i, i + 1));
            if (n % P == 0) {
                answer += i + 1;
            }
        }
        return answer;
    }

    public static int checkNotTwoNorFive(int N, int P, String S) {
        int multiplier = 1; // 10^i % P
        int answer = 0;
        int[] remainderLookup = new int[P];
        int prevRemaider = -1;
        int digit, remainder, count;
        for (int i = N - 1; i >= 0; i--) {
            digit = S.charAt(i) - '0';
            if (prevRemaider == -1) { // first digit
                remainder = digit % P;
            } else {
                remainder = (((multiplier * digit) % P) + prevRemaider) % P;
            }
            if (remainder == 0) {
                answer++;
            }
            count = remainderLookup[remainder];
            answer += count;
            count++;
            remainderLookup[remainder] = count;
            prevRemaider = remainder;
            multiplier = (multiplier * 10) % P;
        }
        return answer;
    }
}

