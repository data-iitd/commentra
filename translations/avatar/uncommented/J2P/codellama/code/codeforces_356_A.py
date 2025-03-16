
import sys
import math
import string
import bisect
import itertools
import statistics
import functools
import operator
import heapq
import collections
import random
import re
import array
import copy
import time
import queue
import threading
import numpy as np
import scipy as sp
import scipy.sparse
import scipy.special
import scipy.stats
import scipy.optimize
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import matplotlib.patches as patches
import matplotlib.path as mpath
import matplotlib.collections as mcoll
import matplotlib.colors as mcolors
import matplotlib.gridspec as gridspec
import matplotlib.animation as manimation
import matplotlib.image as mimage
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_qt4 as qt4
import matplotlib.backends.backend_wx as wx
import matplotlib.backends.backend_gtk as gtk
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt5 as qt5
import matplotlib.backends.backend_qt5agg as qt5agg
import matplotlib.backends.backend_cairo as cairo
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
import matplotlib.backends.backend_gtkagg as gtkagg
import matplotlib.backends.backend_tkagg as tkagg
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_pdf as pdf
import matplotlib.backends.backend_pgf as pgf
import matplotlib.backends.backend_svg as svg
import matplotlib.backends.backend_ps as ps
import matplotlib.backends.backend_agg as agg
import matplotlib.backends.backend_cairoagg as cairoagg
import matplotlib.backends.backend_webagg_core as webagg_core
import matplotlib.backends.backend_webagg as webagg
import matplotlib.backends.backend_nbagg as nbagg
import matplotlib.backends.backend_mixed as mixed
import matplotlib.backends.backend_qt4agg as qt4agg
import matplotlib.backends.backend_wxagg as wxagg
imp