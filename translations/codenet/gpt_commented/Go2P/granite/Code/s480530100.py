
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n  # Create a list to hold the tree data

    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r-1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generi