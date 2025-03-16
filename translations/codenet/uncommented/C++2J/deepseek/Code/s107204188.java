public class Main {
    public static void main(String[] args) {
        int minA = (int) Math.pow(10, 9) + 1;
        int num = 0;
        
        int n = 0, t = 0, f = 0;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        t = scanner.nextInt();
        int[] A = new int[n];
        
        for(int i = 0; i < n; i++){
            A[i] = scanner.nextInt();
        }
        
        for(int i = 0; i < n; i++){
            if(minA > A[i]){
                minA = A[i];
            }else{
                
                if(f == A[i] - minA)num++;
                else if(f < A[i] - minA){
                    num = 1;
                    f = A[i] - minA;
                }
                
            }
        }
        
        System.out.println(num);
    }
}
