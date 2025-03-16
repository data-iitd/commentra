
# AtCoder.py : This file contains the 'main' function. Program execution starts and ends here.
#

import math # Standard math library

#import cmath # Alternative way to include math functions

from collections import deque # Double-ended queue
from collections import defaultdict # Dictionary with default values
from collections import Counter # Bag or multiset
from collections import OrderedDict # Dictionary that remembers the order of the keys
from collections import namedtuple # Tuple with named fields
from collections import deque # Double-ended queue
from collections import ChainMap # Dictionary that allows multiple dictionaries to be merged
from collections import abc # Module containing collections abstract base classes
from itertools import combinations # Combinations of elements in an iterable
from itertools import permutations # Permutations of elements in an iterable
from itertools import product # Cartesian product of elements in an iterable
from itertools import accumulate # Iterator producing a running total
from itertools import pairwise # Iterator producing pairs of elements
from itertools import repeat # Iterator producing elements and their repetitions
from itertools import starmap # Map a function over an iterable and its arguments
from itertools import tee # Clone an iterator
from itertools import zip_longest # Iterate over corresponding elements of two or more iterables
from itertools import filterfalse # Make an iterator that filters elements from an iterable
from heapq import heapify, heappop, heappush # Heap data structure
from bisect import bisect_left, bisect_right # Functions for searching a sorted list
from bisect import insort_left, insort_right # Functions for inserting an element in a sorted list
from bisect import bisect # Insert and search in a single step
from bisect import insort # Insert and search in a single step
from statistics import mean # Average of a list of numbers
from statistics import median # Middle value of a list of numbers
from statistics import mode # Most common value in a list of numbers
from statistics import stdev # Standard deviation of a list of numbers
from statistics import variance # Variance of a list of numbers
from statistics import pvariance # Population variance of a list of numbers
from statistics import harmonic_mean # Inverse of the arithmetic mean
from statistics import median_low # Low median of a list of numbers
from statistics import median_high # High median of a list of numbers
from statistics import median_grouped # Median of grouped data
from statistics import quantiles # Divide a dataset into quantiles
from statistics import shannon_entropy # Shannon entropy of a list of probabilities
from statistics import plot_histogram # Plot a histogram of a list of numbers
from statistics import plot_cumulative_histogram # Plot a cumulative histogram of a list of numbers
from statistics import plot_density # Plot a density plot of a list of numbers
from statistics import plot_qq # Plot a Q-Q plot of two datasets
from statistics import plot_box # Plot a box plot of a dataset
from statistics import plot_bar # Plot a bar plot of a dataset
from statistics import plot_line # Plot a line plot of a dataset
from statistics import plot_scatter # Plot a scatter plot of two datasets
from statistics import plot_area # Plot an area plot of a dataset
from statistics import plot_pie # Plot a pie chart of a dataset
from statistics import plot_barh # Plot a horizontal bar plot of a dataset
from statistics import plot_lineh # Plot a horizontal line plot of a dataset
from statistics import plot_scatterh # Plot a horizontal scatter plot of two datasets
from statistics import plot_areah # Plot a horizontal area plot of a dataset
from statistics import plot_pieh # Plot a horizontal pie chart of a dataset
from statistics import plot_barv # Plot a vertical bar plot of a dataset
from statistics import plot_linev # Plot a vertical line plot of a dataset
from statistics import plot_scatterv # Plot a vertical scatter plot of two datasets
from statistics import plot_areav # Plot a vertical area plot of a dataset
from statistics import plot_piev # Plot a vertical pie chart of a dataset
from statistics import plot_barhv # Plot a horizontal bar plot of a dataset
from statistics import plot_linehv # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhv # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahv # Plot a horizontal area plot of a dataset
from statistics import plot_piehv # Plot a horizontal pie chart of a dataset
from statistics import plot_barvh # Plot a vertical bar plot of a dataset
from statistics import plot_linevh # Plot a vertical line plot of a dataset
from statistics import plot_scattervh # Plot a vertical scatter plot of two datasets
from statistics import plot_areavh # Plot a vertical area plot of a dataset
from statistics import plot_pievh # Plot a vertical pie chart of a dataset
from statistics import plot_barhvh # Plot a horizontal bar plot of a dataset
from statistics import plot_linehvh # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhvh # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahvh # Plot a horizontal area plot of a dataset
from statistics import plot_piehvh # Plot a horizontal pie chart of a dataset
from statistics import plot_barvhv # Plot a vertical bar plot of a dataset
from statistics import plot_linevhv # Plot a vertical line plot of a dataset
from statistics import plot_scattervhv # Plot a vertical scatter plot of two datasets
from statistics import plot_areavhv # Plot a vertical area plot of a dataset
from statistics import plot_pievhv # Plot a vertical pie chart of a dataset
from statistics import plot_barhvhv # Plot a horizontal bar plot of a dataset
from statistics import plot_linehvhv # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhvhv # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahvhv # Plot a horizontal area plot of a dataset
from statistics import plot_piehvhv # Plot a horizontal pie chart of a dataset
from statistics import plot_barvhvh # Plot a vertical bar plot of a dataset
from statistics import plot_linevhvh # Plot a vertical line plot of a dataset
from statistics import plot_scattervhvh # Plot a vertical scatter plot of two datasets
from statistics import plot_areavhvh # Plot a vertical area plot of a dataset
from statistics import plot_pievhvh # Plot a vertical pie chart of a dataset
from statistics import plot_barhvhvh # Plot a horizontal bar plot of a dataset
from statistics import plot_linehvhvh # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhvhvh # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahvhvh # Plot a horizontal area plot of a dataset
from statistics import plot_piehvhvh # Plot a horizontal pie chart of a dataset
from statistics import plot_barvhvhv # Plot a vertical bar plot of a dataset
from statistics import plot_linevhvhv # Plot a vertical line plot of a dataset
from statistics import plot_scattervhvhv # Plot a vertical scatter plot of two datasets
from statistics import plot_areavhvhv # Plot a vertical area plot of a dataset
from statistics import plot_pievhvhv # Plot a vertical pie chart of a dataset
from statistics import plot_barhvhvhv # Plot a horizontal bar plot of a dataset
from statistics import plot_linehvhvhv # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhvhvhv # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahvhvhv # Plot a horizontal area plot of a dataset
from statistics import plot_piehvhvhv # Plot a horizontal pie chart of a dataset
from statistics import plot_barvhvhvhv # Plot a vertical bar plot of a dataset
from statistics import plot_linevhvhvhv # Plot a vertical line plot of a dataset
from statistics import plot_scattervhvhvhv # Plot a vertical scatter plot of two datasets
from statistics import plot_areavhvhvhv # Plot a vertical area plot of a dataset
from statistics import plot_pievhvhvhv # Plot a vertical pie chart of a dataset
from statistics import plot_barhvhvhvhv # Plot a horizontal bar plot of a dataset
from statistics import plot_linehvhvhvhv # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhvhvhvhv # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahvhvhvhv # Plot a horizontal area plot of a dataset
from statistics import plot_piehvhvhvhv # Plot a horizontal pie chart of a dataset
from statistics import plot_barvhvhvhvhv # Plot a vertical bar plot of a dataset
from statistics import plot_linevhvhvhvhv # Plot a vertical line plot of a dataset
from statistics import plot_scattervhvhvhvhv # Plot a vertical scatter plot of two datasets
from statistics import plot_areavhvhvhvhv # Plot a vertical area plot of a dataset
from statistics import plot_pievhvhvhvhv # Plot a vertical pie chart of a dataset
from statistics import plot_barhvhvhvhvhv # Plot a horizontal bar plot of a dataset
from statistics import plot_linehvhvhvhvhv # Plot a horizontal line plot of a dataset
from statistics import plot_scatterhvhvhvhvhv # Plot a horizontal scatter plot of two datasets
from statistics import plot_areahvhvhvhvhv # Plot a horizontal area plot of a dataset
from statistics import plot_piehvhvhvhvhv # Plot a horizontal pie chart of a dataset
from statistics import plot_barvhvhvhvhvhv # Plot a vertical bar plot of a dataset
from statistics import plot_linevhvhvhvhvhv # Plot a vertical line plot of a dataset
from statistics import plot_scattervhvhvhvhvhv # Plot a vertical scatter plot of two datasets
from statistics import plot_areavhvhvhvhvhv # Plot a vertical area plot of a dataset
from statistics import plot_pievhvhvhvhvhv # Plot a vertical pie chart of a dataset
from statistics import plot_barhvhvhvhvhvhv # Plot a horizontal bar plo