
def bubbleSort( cards ):
    """
    This function sorts an array of cards using the bubble sort algorithm.
    """
    n = len( cards )
    """
    The variable 'n' stores the length of the 'cards' list.
    """
    for i in range( 0, n ):
        """
        The outer loop runs from the first index to the second last index.
        """
        for j in range( n-1 , i, -1 ):
            """
            The inner loop compares adjacent elements and swaps them if they are in the wrong order.
            """
            if int( cards[j][1] ) < int( cards[ j-1 ][1] ):
                """
                If the current element is smaller than the previous one, swap them.
                """
                cards[j], cards[ j-1 ] = cards[ j-1 ], cards[j]
 
    """
    After sorting, print the sorted list of cards.
    """
    print( " ".join( map( str, cards ) ) )

def selectionSort( cards ):
	"""
	This function sorts an array of cards using the selection sort algorithm.
	"""
	n = len( cards )
	"""
	The variable 'n' stores the length of the 'cards' list.
	"""
	for i in range( 0, n ):
		"""
		The variable 'mini' stores the index of the minimum element in the unsorted part of the list.
		"""
		mini = i
		for j in range( i , n ):
			"""
			The inner loop finds the index of the minimum element in the unsorted part of the list.
			"""
			if int( cards[j][1] ) < int( cards[ mini ][1] ):
				"""
				If the current element is smaller than the 'mini' element, update the index of 'mini'.
				"""
				mini = j
		if mini != i:
			"""
			If 'mini' is not equal to 'i', swap the elements at indices 'i' and 'mini'.
			"""
			cards[i], cards[ mini ] = cards[ mini ], cards[i]

	"""
	After sorting, print the sorted list of cards.
	"""
	print( " ".join( map( str, cards ) ) )


n = int( input( ) )
"""
The variable 'n' stores the number of cards.
"""
cards = input( ).split( " " )
"""
The 'cards' list stores the initial list of cards.
"""
cards2 = list( cards )
"""
The 'cards2' list is a copy of the 'cards' list for sorting using a different algorithm.
"""
bubbleSort( cards )
"""
Sort the 'cards' list using bubble sort algorithm.
"""
print( "Stable" )
"""
Since bubble sort is a stable sorting algorithm, print 'Stable'.
"""
selectionSort( cards2 )
"""
Sort the 'cards2' list using selection sort algorithm.
"""
if " ".join( map( str, cards2 ) ) == " ".join( map( str, cards ) ):
	"""
	If both sorted lists are equal, print 'Stable'.
	"""
	print( "Stable" )
else:
	"""
	If both sorted lists are not equal, print 'Not stable'.
	"""
	print( "Not stable" )