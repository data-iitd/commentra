public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            int m = scanner.nextInt();
            int f = scanner.nextInt();
            int r = scanner.nextInt();
            if (m == -1 || f == -1) {
                System.out.println("F");
            } else if (m + f >= 80) {
                System.out.println("A");
            } else if (m + f >= 65) {
                System.out.println("B");
            } else if (m + f >= 50 || r >= 50) {
                System.out.println("C");
            } else if (m + f >= 30) {
                System.out.println("D");
            } else {
                System.out.println("F");
            }
        }
    }
}
