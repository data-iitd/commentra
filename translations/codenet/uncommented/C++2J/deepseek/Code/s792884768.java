public class MatrixChainMultiplication {
    static class TSize {
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

    static class TMcmSolver {
        private final int[][] FMemo;
        private final TSize[] FChain;

        private static int Count(TSize Left, TSize Right) {
            return Left.r * Right.c * Left.c;
        }

        private int Solve(int s, int l) {
            assert s <= l;
            if (s == l) return 0;
            if (FMemo[s][l] != 0) return FMemo[s][l];
            if (s + 1 == l) {
                FMemo[s][l] = Count(FChain[s], FChain[l]);
            } else {
                int min = Integer.MAX_VALUE;
                for (int i = s; i < l; ++i) {
                    int c = Solve(s, i) + Count(new TSize(FChain[s].r, FChain[i].c), new TSize(FChain[i + 1].r, FChain[l].c)) + Solve(i + 1, l);
                    min = Math.min(min, c);
                }
                FMemo[s][l] = min;
            }
            return FMemo[s][l];
        }

        public TMcmSolver(TSize[] Chain) {
            this.FChain = Chain;
            this.FMemo = new int[Chain.length][Chain.length];
        }

        public int Answer() {
            return Solve(0, FMemo.length - 1);
        }

        public void Print() {
            for (int s = 0; s < FMemo.length; ++s) {
                for (int l = 0; l < FMemo[0].length; ++l) {
                    System.out.print(FMemo[s][l] + "\t");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        TSize[] Chain = new TSize[n];
        for (int i = 0; i < n; ++i) {
            Chain[i] = new TSize(scanner.nextInt(), scanner.nextInt());
        }
        TMcmSolver Solver = new TMcmSolver(Chain);
        System.out.println(Solver.Answer());
        // Solver.Print();
    }
}
