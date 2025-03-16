
t , m = map ( int , input ( ).split ( ) )
# Read the number of operations and the size of the memory

alocuente = [ 0 ] * m
# Initialize an array to keep track of memory allocation, all elements set to 0

ind = 1
# Initialize the ID counter for allocated memory blocks

for i in range ( t ) :
    # Loop through each operation
    op = input ( ).split ( )
    # Read the operation and split it into parts
    if op [ 0 ] == 'alloc' :
        # If the operation is to allocate memory
        pos = 0
        # Initialize a position counter
        for j in range ( m ) :
            # Loop through each memory block
            if alocuente [ j ] == 0 :
                # Check if the memory block is free
                pos += 1
                # Increment the position counter
                if pos == int ( op [ 1 ] ) :
                    # If a contiguous block of the required size is found
                    alocuente [ j - int ( op [ 1 ] ) + 1 : j + 1 ] = [ ind ] * int ( op [ 1 ] )
                    # Allocate the memory block with the current ID
                    print ( ind )
                    ind += 1
                    break
            else :
                pos = 0
                # Reset the position counter if a free block is interrupted
        else :
            print ( "NULL" )
            # If no contiguous block is found, print "NULL"
    if op [ 0 ] == 'erase' :
        # If the operation is to erase a memory block
        pos = 0
        if int ( op [ 1 ] ) not in alocuente or int ( op [ 1 ] ) == 0 :
            # Check if the specified memory block is allocated and not already free
            print ( 'ILLEGAL_ERASE_ARGUMENT' )
            # If not, print "ILLEGAL_ERASE_ARGUMENT"
        else :
            for j in range ( m ) :
                if int ( op [ 1 ] ) > 0 and alocuente [ j ] == int ( op [ 1 ] ) :
                    alocuente [ j ] = 0
                    # Free the specified memory block
    if op [ 0 ] == "defragment" :
        # If the operation is to defragment the memory
        cnt = 0
        cnt = alocuente.count ( 0 )
        # Count the number of free memory blocks
        alocuente = [ j for j in alocuente if j != 0 ]
        # Remove free memory blocks from the array
        for j in range ( cnt ) :
            alocuente.append ( 0 )
            # Append the free memory blocks at the end of the array

