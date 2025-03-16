
import sys
import math
import bisect
import itertools
import decimal
import statistics
import collections
import fractions
import array
import heapq
import re
import copy
import time
import functools
import operator
import os
import io
import string
import random
import queue
import threading
import resource
import struct
import sys
import traceback
import unittest
import queue
import doctest
import profile
import pstats
import linecache
import shlex
import textwrap
import xml.etree.ElementTree as ET
import xml.dom.minidom as MD
import xml.sax.saxutils as SU
import csv
import json
import curses
import locale
import lzma
import base64
import binascii
import codecs
import difflib
import fnmatch
import getpass
import glob
import inspect
import marshal
import optparse
import os.path
import platform
import readline
import shlex
import signal
import socket
import sqlite3
import string
import subprocess
import tarfile
import telnetlib
import tempfile
import termios
import timeit
import tokenize
import zipfile
import zipimport
import cmath
import datetime
import fractions
import imghdr
import ipaddress
import mailbox
import mimetypes
import netrc
import operator
import optparse
import os
import pwd
import py_compile
import pyclbr
import pydoc
import pyexpat
import queue
import quopri
import random
import reprlib
import rlcompleter
import runpy
import shelve
import shlex
import shutil
import signal
import site
import smtpd
import smtplib
import sndhdr
import socket
import socketserver
import sqlite3
import string
import stringprep
import sunau
import symtable
import tabnanny
import tarfile
import telnetlib
import tempfile
import textwrap
import this
import time
import timeit
import token
import tokenize
import trace
import traceback
import unittest
import urllib
import urlparse
import user
import uuid
import warnings
import wave
import weakref
import webbrowser
import whichdb
import wsgiref
import xdrlib
import zipfile
import zipimport
import zlib

# Define the main function, which is the entry point of the program
def main ( ):
    # Read the number of elements N from the standard input
    N = int ( input ( ) ) ;

    # Create an integer array A of size N to store the elements
    A = [ ] ;

    # Use a for loop to read each element from the standard input and store it in the corresponding index of the array A
    for n in range ( N ) :
        A.append ( int ( input ( ) ) ) ;

    # Use the sorted() function to sort the elements in the array A in ascending order
    A = sorted ( A ) ;

    # Initialize two variables, min and max, to store the minimum and maximum elements in the array A, respectively
    min = A [ 0 ] ;
    max = A [ N - 1 ] ;

    # Use a for loop to iterate through each element in the array A and perform some checks
    mins = 0 ;
    maxs = 0 ;
    for value in A :
        if ( value == min ) : # If the current element is equal to the minimum element min, increment the variable mins by 1
            mins += 1 ;
        if ( value == max ) : # If the current element is equal to the maximum element max, increment the variable maxs by 1
            maxs += 1 ;

    # Check if the minimum and maximum elements are the same
    if ( min == max ) :
        result = ( max - min ) + 1 ; # Calculate the difference between the minimum and maximum elements, plus 1
        result *= mins ; # Multiply the result by the number of occurrences of the minimum element
        result -= mins * ( mins - 1 ) / 2 ; # Subtract the number of combinations of pairs of minimum elements
        print ( result ) ; # Print the output
    else :
        result = ( max - min ) ; # Calculate the difference between the minimum and maximum elements
        result *= mins ; # Multiply the result by the number of occurrences of the minimum element
        result *= maxs ; # Multiply the result by the number of occurrences of the maximum element
        print ( result ) ; # Print the output

# Call the main function to start the program
if __name__ == "__main__" :
    main ( ) ;