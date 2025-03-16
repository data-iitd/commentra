public class Main {
    public static void main(String[] args) {
        int i, t, n;

        for(i=0; i<4; i++){
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            t = scanner.nextInt();
            n = scanner.nextInt();

            if(t==1){
                System.out.println(6000*n);
            }
            else if(t==2){
                System.out.println(4000*n);
            }
            else if(t==3){
                System.out.println(3000*n);
            }
            else if(t==4){
                System.out.println(2000*n);
            }
        }
    }
}
