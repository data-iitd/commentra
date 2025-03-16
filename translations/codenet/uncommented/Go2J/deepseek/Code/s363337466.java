public class Main {
    public static int walkOnMultiplicationTable(int num) {
        int div = 0;
        for (int i = (int) Math.sqrt(num); i > 1; i--) {
            if (num % i == 0) {
                div = i;
                break;
            }
        }
        if (div == 0) {
            return num - 1;
        }
        return div + num / div - 2;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        System.out.println(walkOnMultiplicationTable(a));
    }
}
