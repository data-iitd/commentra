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

    private static int checkSubNumbers(int N, int P, String S) {
        if (P == 2 || P == 5) {
            return checkTwoOrFive(N, P, S);
        } else {
            return checkNotTwoNorFive(N, P, S);
        }
    }

    private static int checkTwoOrFive(int N, int P, String S) {
        int answer = 0;
        for (int i = N - 1; i >= 0; i--) {
            int n = S.charAt(i) - '0';
            if (n % P == 0) {
                answer += i + 1;
            }
        }
        return answer;
    }

    private static int checkNotTwoNorFive(int N, int P, String S) {
        int multiplier = 1; // 10^i % P
        int answer = 0;
        int[] remainderLookup = new int[P];
        int prevRemainder = -1;
        int digit, remainder, count;

        for (int i = N - 1; i >= 0; i--) {
            digit = S.charAt(i) - '0';
            if (prevRemainder == -1) { // first digit
                remainder = digit % P;
            } else {
                remainder = ((multiplier * digit) % P + prevRemainder) % P;
            }
            if (remainder == 0) {
                answer++;
            }
            count = remainderLookup[remainder];
            answer += count;
            count++;
            remainderLookup[remainder] = count;
            prevRemainder = remainder;
            multiplier = (multiplier * 10) % P;
        }
        return answer;
    }
}

// <END-OF-CODE>
