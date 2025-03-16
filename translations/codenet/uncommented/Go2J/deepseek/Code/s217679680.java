public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int[] arr = readArrayInt(scanner);
        int a = arr[0];
        int b = arr[1];
        int tap = 0;
        int consent = 1;
        while (consent < b) {
            consent = consent + a - 1;
            tap++;
        }
        System.out.println(tap);
    }

    private static int[] readArrayInt(java.util.Scanner scanner) {
        String[] parts = scanner.nextLine().split(" ");
        int[] ret = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            ret[i] = Integer.parseInt(parts[i]);
        }
        return ret;
    }
}
