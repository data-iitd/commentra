// Step 1: Take two integers as input and assign them to x and y.
Scanner sc = new Scanner ( System.in );
int x = sc.nextInt ( );
int y = sc.nextInt ( );

// Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
int max = Math.max ( x + y - 3 + ( ( y - x ) % 3 > 0 ) , 0 );
System.out.println ( max );

// Step 3: Define lambda functions for taking different types of inputs.
Function<Integer> num_inp = ( ) -> Integer.parseInt ( sc.next ( ) );
Function<Integer[]> arr_inp = ( ) -> Arrays.stream ( sc.nextLine ( ).split ( " " ) ).mapToInt ( Integer::parseInt ).toArray ( );
Function<Integer[]> sp_inp = ( ) -> Arrays.stream ( sc.nextLine ( ).split ( " " ) ).mapToInt ( Integer::parseInt ).toArray ( );
Function<String> str_inp = ( ) -> sc.nextLine ( );

