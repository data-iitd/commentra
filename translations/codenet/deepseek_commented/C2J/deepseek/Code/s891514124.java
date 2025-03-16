public class TimeConverter {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int S = scanner.nextInt();

        if (S < 60) {
            System.out.println("0:0:" + S);
        } else if (S < 3600) {
            System.out.println("0:" + (S / 60) + ":" + (S % 60));
        } else {
            System.out.println((S / 3600) + ":" + ((S % 3600) / 60) + ":" + (S % 60));
        }
    }
}
