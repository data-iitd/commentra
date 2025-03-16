public class Main {
    public static void main(String[] args) {
        Input input = new Input(System.in);
        int n = input.nextInt();
        long[] s = input.nextLongArray();
        boolean[] u = new boolean[n];
        long m = 0, f = 0;
        for (int c = 1; c < n - 1; c++) {
            f = 0;
            for (int k = 0; c < n - 1 - k * c; k++) {
                u[k * c] = true;
                if (u[n - 1 - k * c]) break;
                f += s[n - 1 - k * c] + s[k * c];
                if (m < f) m = f;
            }
            for (int k = 0; k * c < n - 1; k++) u[k * c] = false;
        }
        System.out.println(m);
    }
}

class Input {
    private java.util.Scanner scanner;

    public Input(java.io.InputStream inputStream) {
        this.scanner = new java.util.Scanner(inputStream);
    }

    public String nextLine() {
        return scanner.nextLine();
    }

    public int nextInt() {
        return scanner.nextInt();
    }

    public long[] nextLongArray() {
        String[] s = nextLine().split(" ");
        long[] a = new long[s.length];
        for (int i = 0; i < s.length; i++) {
            a[i] = Long.parseLong(s[i]);
        }
        return a;
    }
}
