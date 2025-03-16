public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String ds = scanner.nextLine() + " " + scanner.nextLine();
        String[] dd = ds.split(" ");
        int[] dn = new int[dd.length];
        for (int i = 0; i < dd.length; i++) {
            dn[i] = Integer.parseInt(dd[i]);
        }

        int sum = 0;
        for (int i = 0; i < dn.length; i++) {
            for (int j = i + 1; j < dn.length; j++) {
                sum += dn[i] * dn[j];
            }
        }

        System.out.println(sum);
    }
}
