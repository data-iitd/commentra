public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int N = scanner.nextInt();
        int A = Math.max(H, W);
        System.out.println((N + A - 1) / A);
    }
}

class Scanner {
    private java.util.Scanner scanner;

    public Scanner(java.io.InputStream source) {
        scanner = new java.util.Scanner(source);
    }

    public int nextInt() {
        return scanner.nextInt();
    }
}
