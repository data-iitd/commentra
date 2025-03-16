
public class Main {
    public static void main(String[] args) {
        int a, b, c;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        if (a < b && b < c) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

