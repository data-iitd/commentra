public class Main {
    // We declare and initialize some variables and arrays here.
    static int[] kekka = new int[2];
    static int[] prime_or_not = new int[1001];
    static int[] prime_list = new int[1001];
    static int prime_counter = 0;

    // This function calculates prime numbers up to 1000 and stores them in prime_list[].
    static void sosuubunnpu(){
        // Initialize prime_or_not[] to all zeros.
        for (int i = 1; i <= 1000; ++i) {
            prime_or_not[i] = 0;
        }
        // Mark non-prime numbers as 1 in prime_or_not[].
        for (int i = 2; i <= 1000; ++i) {
            for (int j = 2; j <= 1000/i; ++j) {
                if(prime_or_not[i]==0){
                    prime_or_not[i*j] = 1;
                }
            }
        }
        // Store prime numbers in prime_list[].
        for (int i = 2; i <= 1000; ++i) {
            if(prime_or_not[i]==0){
                prime_list[prime_counter] = i;
                prime_counter+=1;
            }
        }
    }

    // This function calculates the exponent of a prime number in a given number.
    static void innsuubunnkai(int N,int n){
        // Initialize time to 0.
        int time = 0;
        // Calculate the exponent of prime number n in N.
        while(true){
            if(N%n == 0){
                N = N/n;
                time++;
            }else{
                break;
            }
        }
        // Store the result in kekka[].
        kekka[0] = time;
        kekka[1] = N;
    }

    // This is the main function where we call sosuubunnpu() and perform the main calculation.
    public static void main(String[] args) {
        // Call sosuubunnpu() to calculate prime numbers.
        sosuubunnpu();
        // Read the input N from the standard input.
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        // Initialize innsuu[] and A[][] here.
        int[] innsuu = new int[11];
        int[][] A = new int[N+1][11];
        // Initialize prime_num[] to zeros.
        int[] prime_num = new int[1001];
        // Calculate prime_num[] using innsuubunnkai().
        for (int current_num = 2; current_num <= N; ++current_num) {
            kekka[1] = current_num;
            for (int i = 0; i < prime_counter; ++i) {
                innsuubunnkai(kekka[1],prime_list[i]);
                prime_num[i]+=kekka[0];
            }
        }
        // Calculate the final result.
        long result = 1;
        for (int current_num = 2; current_num <= N; ++current_num){
            for (int i = 0; i < 11; ++i){
                innsuu[i] += A[current_num][i];
            }
        }
        for (int i = 0; i < prime_counter; ++i){
            result = (result*(prime_num[i]+1))%1000000007;
        }
        // Output the final result.
        System.out.println(result);
    }
}
