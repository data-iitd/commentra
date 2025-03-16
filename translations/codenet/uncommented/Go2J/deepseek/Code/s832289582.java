public class Main {
    public static void main(String[] args) {
        InputScanner sc = new InputScanner(true, 256);
        int N = sc.nextInt();
        int P = sc.nextInt();
        String S = sc.nextStr();
        int answer = checkSubNumbers(N, P, S);
        System.out.println(answer);
    }

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
            n = S.charAt(i) - '0';
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

class InputScanner {
    private java.util.Scanner scanner;

    public InputScanner(boolean enabledScanWords, int sizeInKB) {
        scanner = new java.util.Scanner(System.in);
        if (enabledScanWords) {
            scanner.useDelimiter("\\s+");
        }
        scanner.useDelimiter("\\A");
        scanner.bufferSize(sizeInKB * 1024);
    }

    public int nextInt() {
        return Integer.parseInt(scanner.next());
    }

    public long nextUInt64() {
        return Long.parseLong(scanner.next());
    }

    public String nextStr() {
        return scanner.next();
    }
}
