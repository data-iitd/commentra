
public class Main {
    public static void main(String[] args) {
        int a, b;
        a = 0;
        b = 0;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        if((a*b)%2 == 0){
            System.out.println("Even");
        }else{
            System.out.println("Odd");
        }
    }
}

