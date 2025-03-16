
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        sc.close();

        // Sorting the list A
        Arrays.sort(A);

        // Binary search setup
        long ll = -1000000000000000000L;
        long rr = 1000000000000000000L;

        // Binary search execution
        while (ll + 1 < rr) {
            long x = (ll + rr) / 2;
            long tot = 0;

            // Counting valid pairs for each element in A
            for (int i = 0; i < N; i++) {
                if (A[i] < 0) {
                    int l = -1;
                    int r = N;
                    while (l + 1 < r) {
                        int c = (l + r) / 2;
                        if (A[i] * A[c] < x) {
                            r = c;
                        } else {
                            l = c;
                        }
                    }
                    tot += N - r;
                } else {
                    int l = -1;
                    int r = N;
                    while (l + 1 < r) {
                        int c = (l + r) / 2;
                        if (A[i] * A[c] < x) {
                            l = c;
                        } else {
                            r = c;
                        }
                    }
                    tot += r;
                }

                if (A[i] * A[i] < x) {
                    tot--;
                }
            }

            tot /= 2;

            // Adjusting the search range based on the total count
            if (tot < K) {
                ll = x;
            } else {
                rr = x;
            }
        }

        System.out.println(ll);
    }
}

