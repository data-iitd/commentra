
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int P = sc.nextInt();
        String S = sc.next();
        int answer = checkSubNumbers(N, P, S);
        System.out.println(answer);
    }

    public static int checkSubNumbers(int N, int P, String S) {
        int answer = 0;
        switch (P) {
            case 2:
            case 5:
                answer = checkTwoOrFive(N, P, S);
                break;
            default:
                answer = checkNotTwoNorFive(N, P, S);
                break;
        }
        return answer;
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
        int answer = 0;
        int multiplier = 1;
        int[] remainderLookup = new int[P];
        int prevRemaider = -1;
        int digit, remainder, count;
        for (int i = N - 1; i >= 0; i--) {
            digit = Integer.parseInt(S.substring(i, i + 1));
            if (prevRemaider == -1) {
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

