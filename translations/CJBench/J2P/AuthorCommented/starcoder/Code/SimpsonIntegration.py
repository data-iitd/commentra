
import math
import sys

# Calculate definite integrals by using Composite Simpson's rule.
# Wiki: https://en.wikipedia.org/wiki/Simpson%27s_rule#Composite_Simpson's_rule
# Given f a function and an even number N of intervals that divide the integration interval
# e.g. [a, b], we calculate the step h = (b-a)/N and create a table that contains all the x
# points of the real axis xi = x0 + i*h and the value f(xi) that corresponds to these xi.
#
# To evaluate the integral i use the formula below:
# I = h/3 * {f(x0) + 4*f(x1) + 2*f(x2) + 4*f(x3) +... + 2*f(xN-2) + 4*f(xN-1) + f(xN)}
#
# 