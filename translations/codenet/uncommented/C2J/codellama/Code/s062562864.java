
public class Main {
    public static void main(String[] args) {
        int a, b, c, d, i, j;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        i = a * b;
        j = c * d;
        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }
    }
}

