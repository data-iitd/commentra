Scanner scanner = new Scanner ( System.in );
String s = scanner.nextLine ( );
String result = "Yes".equals ( s ) && s.contains ( "A" ) && s.contains ( "B" ) ? "Yes" : "No";
System.out.println ( result );
