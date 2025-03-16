
import java.util.Scanner;

public class s832289582{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        String S = scanner.next();
        int answer = checkSubNumbers(N, P, S);
        System.out.println(answer);
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

    // checkTwoOrFive iterates over the string S from the end to the beginning, checking if the last digit of each substring is divisible by P.
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

    // checkNotTwoNorFive uses a rolling hash approach to efficiently determine the number of substrings of S that are divisible by P.
    public static int checkNotTwoNorFive(int N, int P, String S) {
        int multiplier = 1; // 10^i % P
        int answer = 0;
        int[] remainderLookup = new int[P]; // Create a slice to store the counts of remainders.
        int prevRemaider = -1;
        int digit, remainder, count;
        for (int i = N - 1; i >= 0; i--) {
            digit = Integer.parseInt(S.substring(i, i + 1));
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

