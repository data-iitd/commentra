public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble();
        }
        for (int i = 0; i + 1 < n; i++) {
            java.util.Arrays.sort(a);
            double[] na = new double[a.length - 1];
            for (int j = 2; j < a.length; j++) {
                na[j - 2] = a[j];
            }
            na = java.util.Arrays.copyOf(na, na.length + 1);
            na[na.length - 1] = (a[0] + a[1]) / 2;
            a = na;
        }
        System.out.println(a[0]);
    }
}
