# Define type aliases for convenience
from collections import deque, defaultdict, Counter, OrderedDict, namedtuple, deque, ChainMap
from itertools import product, permutations, combinations, combinations_with_replacement, accumulate, groupby
from bisect import bisect_left, bisect, bisect_right
from math import gcd, lcm, factorial, ceil, floor, sqrt, sin, cos, tan, degrees, radians, log2, log10, pi
from fractions import Fraction
from decimal import Decimal
from sys import setrecursionlimit, maxsize
from heapq import heapify, heappop, heappush, heappushpop, heapreplace, merge, nlargest, nsmallest
from operator import itemgetter, attrgetter, methodcaller
from functools import reduce
from string import ascii_uppercase, ascii_lowercase, ascii_letters, digits, hexdigits, octdigits
from string import punctuation, printable
from time import time, sleep
from random import randint, randrange, choice, choices, sample, shuffle, seed
from pprint import pprint
from os import system, name, getenv, getcwd
from io import StringIO, BytesIO, IOBase
from re import search, sub, findall, finditer, match, fullmatch, split, subn, escape, purge, compile, IGNORECASE, DOTALL, MULTILINE, VERBOSE
from builtins import pow, round, input, print, range, min, max, abs, sum, any, all, enumerate, sorted, map, filter, zip, reversed, list, tuple, set, dict
from statistics import mean, median, mode, stdev, variance, pvariance, harmonic_mean, median_grouped, median_high, median_low, median_grouped
from statistics import quantiles, median_grouped, median_high, median_low, median_grouped
from statistics import NormalDist, ExponentialDist, ParetoDist, WeibullDist, GammaDist, LogNormalDist, ChiSquaredDist, StudentsTDist, TriangularDist
from statistics import UniformDist, VonMisesDist, PERTDist, BetaDist, DiceDist, FDist, GumbelDist, LogisticDist, PoissonDist, RayleighDist, TriangularDist
from statistics import WaldDist, ZetaDist, ZigguratDist, GeometricDist, HypergeometricDist, BernoulliDist, BinomialDist, NegativeBinomialDist, HypergeometricDist
from statistics import BivariateNormalDist, MultivariateNormalDist, PearsonCorr, SpearmanCorr, KendallCorr, PointBiserialCorr, PearsonChiSqCorr, KendallTauCorr
from statistics import ConfidenceInterval, NormalApproximation, PValue, SignTest, TTest, ZTest, ChiTest, Anova, Kruskal, Friedman, MannWhitney, Wilcoxon, RankSum
from statistics import CorrelationTest, Regress, LeastSquares, PearsonRegress, SimpleLinearRegress, MultipleLinearRegress, PolynomialRegress, ExponentialRegress
from statistics import LogisticRegress, PowerRegress, QuadraticRegress, QuarticRegress, CubicRegress, QuinticRegress, FactorialRegress, BinomialRegress, GammaRegress
from statistics import ExponentialDist, FDist, GDist, TDist, ChiDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import NormalDist, ChiSquaredDist, FDist, GDist, TDist, WeibullDist, RayleighDist, PowerDist, BetaDist, GammaDist, LogNormalDist, ExponentialDist
from statistics import N