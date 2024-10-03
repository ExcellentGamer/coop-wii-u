#!/usr/bin/env python3

import os

os.system('make clean')
os.system('make TARGET_WII_U=1 -j2')