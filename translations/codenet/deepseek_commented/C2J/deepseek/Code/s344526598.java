public class Main {
    public static void main(String[] args) {
        int[] x = new int[10000];
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int i = 0;

        while (true) {
            x[i] = scanner.nextInt();
            if (x[i] == 0) {
                break;
            }
            i++;
        }

        for (int j = 0; j < i; j++) {
            System.out.println("Case " + (j + 1) + ": " + x[j]);
        }
    }
}
