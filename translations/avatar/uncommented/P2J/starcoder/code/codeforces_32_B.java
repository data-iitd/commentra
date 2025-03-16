s = input ( )
result = ""
i = 0
while i < s.length ( ) :
    if s.charAt ( i ) == "." :
        result += '0'
    else :
        i += 1
        if s.charAt ( i ) == "." :
            result += '1'
        else :
            result += '2'
    i += 1
System.out.println ( result )

