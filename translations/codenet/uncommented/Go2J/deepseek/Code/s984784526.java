public class Main {
    public static void main(String[] args) {
        int[] a = new int[3];
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        for (int i = 0; i < 3; i++) {
            a[i] = scanner.nextInt();
        }

        int five = 0;
        int seven = 0;

        for (int i = 0; i < 3; i++) {
            if (a[i] == 5) {
                five++;
            }
            if (a[i] == 7) {
                seven++;
            }
        }

        if (five == 2 && seven == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
