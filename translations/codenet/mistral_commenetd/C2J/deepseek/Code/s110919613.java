public class Kaprekar {
    public static void main(String[] args) {
        // Declare variables
        int i, j, k, L, tmp, d, def, end, aj, max, min;

        // Infinite loop to read input
        for(;;){
            int[] an = new int[20];
            int[] a1 = new int[6];
            int[] a2 = new int[6];
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            an[0] = scanner.nextInt();
            L = scanner.nextInt();
            if(L == 0) break; // Exit the loop if the input length is zero

            aj = an[0]; end = 0;

            // Iterate through each number in the input array
            for(k = 1; k < 20; k++){
                // Iterate through each digit in the number from right to left
                for(i = L - 1; i >= 0; i--, aj /= 10){
                    a1[i] = aj % 10; a2[i] = aj % 10;
                }
                // Sort the digits in both arrays in ascending order
                for(i = 1; i < L; i++){
                    for(j = 1; j < L; j++){
                        if(a1[j - 1] < a1[j]){ // Swap adjacent digits if they are in the wrong order
                            int temp = a1[j - 1];
                            a1[j - 1] = a1[j];
                            a1[j] = temp;
                        }
                        if(a2[j - 1] > a2[j]){ // Swap adjacent digits if they are in the wrong order
                            int temp = a2[j - 1];
                            a2[j - 1] = a2[j];
                            a2[j] = temp;
                        }
                    }
                }
                // Calculate the difference between the two numbers
                d = 1; max = 0; min = 0;
                for(i = L - 1; i >= 0; i--, d *= 10){
                    max += (a1[i] % 10) * d;
                    min += (a2[i] % 10) * d;
                }
                def = max - min; // Store the difference in a variable

                // Check if the difference has already been encountered in the array 'an'
                for(i = 0; i < k; i++){
                    if(def == an[i]){ // If a match is found, print the result and exit the loop
                        System.out.println(i + " " + def + " " + (k - i));
                        end = 1; break;
                    }
                }
                if(end == 1) break; // Exit the loop if a match is found
                an[k] = def; aj = def; // Update the array and the variable for the next iteration
            }
        }
    }
}
