
public class Rectangle {
    public static void main(String[] args) {
        int a, b, ar, le;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        ar = a * b;
        le = 2 * (a + b);
        System.out.println(ar + " " + le);
    }
}
