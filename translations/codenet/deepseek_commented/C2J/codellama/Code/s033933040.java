
public class Main {
    public static void main(String[] args) {
        int a, b, mawari, menseki;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        mawari = 2 * (a + b);
        menseki = a * b;
        System.out.println(menseki + " " + mawari);
    }
}

