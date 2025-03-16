
// Define variables x and y by unpacking the tuple returned by the map function
int x, y;
Scanner sc = new Scanner(System.in);
x = sc.nextInt();
y = sc.nextInt();

// Helper functions for simplifying input process
int num_inp() {
    return sc.nextInt();
}

int[] arr_inp() {
    return Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int[] sp_inp() {
    return Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}

String str_inp() {
    return sc.nextLine();
}

// Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
System.out.println(Math.max(x + y - 3 + ((y - x) % 3 > 0), 0));

