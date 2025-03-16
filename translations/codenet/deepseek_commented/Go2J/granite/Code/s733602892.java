
import java.util.*;

public class s733602892{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] As = new int[N];
        int[] Fs = new int[N];
        for (int i = 0; i < N; i++) {
            As[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            Fs[i] = sc.nextInt();
        }
        Arrays.sort(As);
        Arrays.sort(Fs);
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            scores[i] = As[i] * Fs[N - 1 - i];
        }
        Arrays.sort(scores);
        int ok = scores[N - 1];
        int ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            boolean isOK = true;
            int k = K;
            for (int i = 0; isOK && i < N; i++) {
                if (As[i] * Fs[N - 1 - i] > mid) {
                    k -= As[i] - mid / Fs[N - 1 - i];
                }
                if (k < 0) {
                    isOK = false;
                }
            }
            if (isOK) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        System.out.println(ok);
    }
}

// ReadInts reads a list of integers from stdin
public static int[] ReadInts(int n) {
    int[] ret = new int[n];
    for (int i = 0; i < n; i++) {
        ret[i] = ReadInt();
    }
    return ret;
}

// Initialize the scanner with buffer and word split function
static {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    scanner.useDelimiter("\\A");
    buffer = scanner.hasNext()? scanner.next() : "";
}

public static String Read() {
    java.util.regex.Matcher matcher = pattern.matcher(buffer);
    if (!matcher.find())
        throw new RuntimeException("No input");
    String ret = matcher.group(1);
    buffer = buffer.substring(matcher.end());
    return ret;
}

public static int ReadInt() {
    return Integer.parseInt(Read());
}

