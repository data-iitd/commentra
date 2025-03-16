// Read two integers n and k from input, where n is the total number of elements 
// and k is the number of smallest elements to sum.
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int k = sc.nextInt();

// Read a list of n integers from input, convert them to integers, and sort the list.
// Then, take the first k elements from the sorted list.
// Finally, calculate the sum of these k smallest elements.
int[] arr = new int[n];
for (int i = 0; i < n; i++) {
    arr[i] = sc.nextInt();
}
Arrays.sort(arr);
int sum = 0;
for (int i = 0; i < k; i++) {
    sum += arr[i];
}
System.out.println(sum);

