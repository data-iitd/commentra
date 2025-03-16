import java.util.Arrays;
import java.util.Scanner;

class TSize {
    int r;
    int c;

    TSize() {
        this.r = 0;
        this.c = 0;
    }

    TSize(int Ar, int Ac) {
        this.r = Ar;
        this.c = Ac;
    }
}

class TMcmSolver {
    private int[][] FMemo;
    private final TSize[] FChain;

    private static int count(TSize left, TSize right) {
        return left.r * right.c * left.c;
    }

    private int solve(int s, int l) {
        assert s <= l;
        if (s == l) return 0;
        if (FMemo[s][l] != 0) return FMemo[s][l];
        if (s + 1 == l) {
            FMemo[s][l] = count(FChain[s], FChain[l]);
        } else {
            int min = Integer.MAX_VALUE;
            for (int i = s; i < l; ++i) {
                int c = solve(s, i) + count(new TSize(FChain[s].r, FChain[i].c), new TSize(FChain[i + 1].r, FChain[l].c)) + solve(i + 1, l);
                min = Math.min(min, c);
            }
            FMemo[s][l] = min;
        }
        return FMemo[s][l];
    }

    public TMcmSolver(TSize[] chain) {
        this.FChain = chain;
        this.FMemo = new int[chain.length][chain.length];
    }

    public int answer() {
        return solve(0, FMemo.length - 1);
    }

    public void print() {
        for (int s = 0; s < FMemo.length; s++) {
            for (int l = 0; l < FMemo[0].length; l++) {
                System.out.print(FMemo[s][l] + "\t");
            }
            System.out.println();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        TSize[] chain = new TSize[n];
        for (int i = 0; i < n; ++i) {
            chain[i] = new TSize(scanner.nextInt(), scanner.nextInt());
        }
        TMcmSolver solver = new TMcmSolver(chain);
        
        System.out.println(solver.answer());
        // solver.print();
    }
}

// <END-OF-CODE>
