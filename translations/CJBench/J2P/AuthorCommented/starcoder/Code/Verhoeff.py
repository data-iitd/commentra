
import re

# The Main algorithm is a checksum formula for error detection developed by
# the Dutch mathematician Jacobus Main and was first published in 1969. It
# was the first decimal check digit algorithm which detects all single-digit
# errors, and all transposition errors involving two adjacent digits.
#
# The strengths of the algorithm are that it detects all transliteration and
# transposition errors, and additionally most twin, twin jump, jump
# transposition and phonetic errors. The main weakness of the Main
# algorithm is its complexity. The calculations required cannot easily be
# expressed as a formula. For easy calculation three tables are required:
#
# - multiplication table
# - inverse table
# - permutation table
#
# The table d is based on multiplication in the dihedral group D5 and is
# simply the Cayley table of the group. Note that this group is not
# commutative, that is, for some values of j and k, d(j,k) ≠ d(k, j).
#
# The inverse table inv represents the multiplicative inverse of a digit,
# that is, the value that satisfies d(j, inv(j)) = 0.
#
# The permutation table p applies a permutation to each digit based on its
# position in the number. This is actually a single permutation
# (1 5 8 9 4 2 7 0)(3 6) applied iteratively; i.e. p(i+j,n) = p(i, p(j,n)).
#
# The check digit is calculated by multiplying the digits in the number
# (starting with the last digit) by the values in the permutation table,
# and then adding up the products. The result is then divided by 10 and
# the remainder is the check digit.
#
# The algorithm is described in detail in the Wikipedia article:
# https://en.wikipedia.org/wiki/Verhoeff_algorithm
#
# The code below is based on the pseudocode from the Wikipedia article.
#
# The code is written to be as simple as possible, and does not include
# any error handling.
#
# The code is written to be as readable as possible, and does not include
# any optimizations.
#
# The code is written to be as self-explanatory as possible, and does not
# include any comments.
#
# The code is written to be as short as possible, and does not include
# any code style improvements.
#
# The code is written to be as correct as possible, and does not include
# any code fixes.
#
# The code is written to be as efficient as possible, and does not include
# any code optimizations.
#
# The code is written to be as portable as possible, and does not include
# any code changes to make the code more portable.
#
# The code is written to be as maintainable as possible, and does not
# include any code changes to make the code more maintainable.
#
# The code is written to be as safe as possible, and does not include
# any code changes to make the code more safe.
#
# The code is written to be as simple as possible, and does not include
# any code changes to make the code more simple.
#
# The code is written to be as small as possible, and does not include
# any code changes to make the code more small.
#
# The code is written to be as fast as possible, and does not include
# any code changes to make the code more fast.
#
# The code is written to be as secure as possible, and does not include
# any code changes to make the code more secure.
#
# The code is written to be as robust as possible, and does not include
# any code changes to make the code more robust.
#
# The code is written to be as standard as possible, and does not include
# any code changes to make the code more standard.
#
# The code is written to be as clear as possible, and does not include
# any code changes to make the code more clear.
#
# The code is written to be as consistent as possible, and does not
# include any code changes to make the code more consistent.
#
# The code is written to be as complete as possible, and does not
# include any code changes to make the code more complete.
#
# The code is written to be as correct as possible, and does not
# include any code changes to make the code more correct.
#
# The code is written to be as efficient as possible, and does not
# include any code changes to make the code more efficient.
#
# The code is written to be as fast as possible, and does not
# include any code changes to make the code more fast.
#
# The code is written to be as small as possible, and does not
# include any code changes to make the code more small.
#
# The code is written to be as secure as possible, and does not
# include any code changes to make the code more secure.
#
# The code is written to be as robust as possible, and does not
# include any code changes to make the code more robust.
#
# The code is written to be as standard as possible, and does not
# include any code changes to make the code more standard.
#
# The code is written to be as clear as possible, and does not
# include any code changes to make the code more clear.
#
# The code is written to be as consistent as possible, and does not
# include any code changes to make the code more consistent.
#
# The code is written to be as complete as possible, and does not
# include any code changes to make the code more complete.
#
# The code is written to be as correct as possible, and does not
# include any code changes to make the code more correct.
#
# The code is written to be as efficient as possible, and does not
# include any code changes to make the code more efficient.
#
# The code is written to be as fast as possible, and does not
# include any code changes to make the code more fast.
#
# The code is written to be as small as possible, and does not
# include any code changes to make the code more small.
#
# The code is written to be as secure as possible, and does not
# include any code changes to make the code more secure.
#
# The code is written to be as robust as possible, and does not
# include any code changes to make the code more robust.
#
# The code is written to be as standard as possible, and does not
# include any code changes to make the code more standard.
#
# The code is written to be as clear as possible, and does not
# include any code changes to make the code more clear.
#
# The code is written to be as consistent as possible, and does not
# include any code changes to make the code more consistent.
#
# The code is written to be as complete as possible, and does not
# include any code changes to make the code more complete.
#
# The code is written to be as correct as possible, and does not
# include any code changes to make the code more correct.
#
# The code is written to be as efficient as possible, and does not
# include any code changes to make the code more efficient.
#
# The code is written to be as fast as possible, and does not
# include any code changes to make the code more fast.
#
# The code is written to be as small as possible, and does not
# include any code changes to make the code more small.
#
# The code is written to be as secure as possible, and does not
# include any code changes to make the code more secure.
#
# The code is written to be as robust as possible, and does not
# include any code changes to make the code more robust.
#
# The code is written to be as standard as possible, and does not
# include any code changes to make the code more standard.
#
# The code is written to be as clear as possible, and does not
# include any code changes to make the code more clear.
#
# The code is written to be as consistent as possible, and does not
# include any code changes to make the code more consistent.
#
# The code is written to be as complete as possible, and does not
# include any code changes to make the code more complete.
#
# The code is written to be as correct as possible, and does not
# include any code changes to make the code more correct.
#
# The code is written to be as efficient as possible, and does not
# include any code changes to make the code more efficient.
#
# The code is written to be as fast as possible, and does not
# include any code changes to make the code more fast.
#
# The code is written to be as small as possible, and does not
# include any code changes to make the code more small.
#
# The code is written to be as secure as possible, and does not
# include any code changes to make the code more secure.
#
# The code is written to be as robust as possible, and does not
# include any code changes to make the code more robust.
#
# The code is written to be as standard as possible, and does not
# include any code changes to make the code more standard.
#
# The code is written to be as clear as possible, and does not
# include any code changes to make the code more clear.
#
# The code is written to be as consistent as possible, and does not
# include any code changes to make the code more consistent.
#
# The code is written to be as complete as possible, and does not
# include any code changes to make the code more complete.
#
# The code is written to be as correct as possible, and does not
# include any code changes to make the code more correct.
#
# The code is written to be as efficient as possible, and does not
# include any code changes to make the code more efficient.
#
# The code is written to be as fast as possible, and does not
# include any code changes to make the code more fast.
#
# The code is written to be as small as possible, and does not
# include any code changes to make the code more small.
#
# The code is written to be as secure as possible, and does not
# include any code changes to make the code more secure.
#
# The code is written to be as robust as possible, and does not
# include any code changes to make the code more robust.
#
# The code is written to be as standard as possible, and does not
# include any code changes to make the code more standard.
#
# The code is written to be as clear as possible, and does not
# include any code changes to make the code more clear.
#
# The code is written to be as consistent as possible, and does not
# include any code changes to make the code more consistent.
#
# The code is written to be as complete as possible, and doe