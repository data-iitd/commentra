// The main function from where the execution begins
public static void main(String[] args){
    // Declare variables
    int n;          // Number of elements in the array
    double avg;     // Average of the elements in the array
    double s;       // Difference between the first element and the average
    double ans;     // Index of the element with the maximum difference from the average

    // Initialize variables
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    int a[] = new int[100];

    // Calculate the average of the elements in the array
    for(int i = 0; i < n; i++){
        a[i] = sc.nextInt();
        avg += a[i];
    }

    // Calculate the average and divide it by the number of elements
    avg /= n;

    // Initialize the difference between the first element and the average
    s = Math.abs(a[0] - avg);

    // Initialize the index of the element with the maximum difference from the average
    ans = 0;

    // Find the index of the element with the maximum difference from the average
    for(int i = 1; i < n; i++){
        if(s > Math.abs(a[i] - avg)){
            s = Math.abs(a[i] - avg);
            ans = i;
        }
    }

    // Print the index of the element with the maximum difference from the average
    System.out.println(ans);

    // Terminate the program
    sc.close();
}

