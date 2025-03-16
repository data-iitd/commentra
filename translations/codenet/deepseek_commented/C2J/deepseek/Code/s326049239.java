public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            if (a < 3) {
                System.out.println("0");
            } else {
                int b = a;
                int c = 0, k = 0;
                while (a-- > 0) {
                    b--;
                    c++;
                    if (c == 3) {
                        k++;
                        c = 0;
                    }
                }
                System.out.println(k);
            }
        }
    }
}
