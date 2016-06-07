#!/usr/bin/python 2.7
from __future__ import division
import math
import fileinput
import mmap

# Implement Tarantula using gcov, and describe the process of using it to
# localize a bug in Dominion. Write this up as tarantula.txt, and include any  
# relevant code or files. This will require:
#      1) generating gcov files for each test somehow (these could be random
#         tests defined by their seeds)
#      2) attaching information on whether these tests pass or fail to each
#         test somehow
#      3) parsing the gcov files and using the tarantula formula.

spliced = []

# Parsing randomtestadventurer.out
advfails = 0
advpass = 0
with open('rtresults/randomtestadventurer.out', 'r') as adv:
    print 'FILE OPENED: ', adv.name
    for line in adv:
      if 'Tests run: ' in line:
          spliced = line.split()
          atests = spliced[2]
          print "Total tests run for adventurer: ", atests
      advfails += line.count("FAILURE FOUND")
    advpass = int(atests) - advfails
print "Passing tests: ", advpass
print "Number of failures in ``adventurer``: ", advfails, '\n'
adv.close()

# Parsing randomtestcard1.out
cutfails = 0
cutpass = 0
with open('rtresults/randomtestcard1.out', 'r') as cutpurse:
    print 'FILE OPENED: ', cutpurse.name
    for line in cutpurse:
      if 'Tests run: ' in line:
          spliced = line.split()
          ctests = spliced[2]
          print "Total tests run for cutpurse: ", ctests
      cutfails += line.count("FAILURE FOUND")
    cutpass = int(ctests) - cutfails
print "Passing tests: ", cutpass
print "Number of failures in ``cutpurse``: ", cutfails, '\n'
cutpurse.close()

# Parsing randomtestcard2.out
smithfails = 0
smithpass = 0
with open('rtresults/randomtestcard2.out', 'r') as smithy:
    print 'FILE OPENED: ', smithy.name
    for line in smithy:
        if 'Tests run: ' in line:
            spliced = line.split()
            stests = spliced[2]
            print "Total tests run for smithy: ", stests
        smithfails += line.count("FAILURE FOUND")
    smithpass = int(stests) - smithfails
print "Passing tests: ", smithpass
print "Number of failures in ``smithy``: ", smithfails
smithy.close()

# Not very pretty but functional enough - tarantula math?
totalpassed = 0
totalfailed = 0

totalpassed = advpass + cutpass + smithpass
totalfailed = advfails + cutfails + smithfails

print
print "Total passed: ", totalpassed
print "Total failed: ", totalfailed
print

suspect_adventurer = 0
suspect_cutpurse = 0
suspect_smithy = 0

adv_denom = (advpass/totalpassed)+(advfails/totalfailed)
suspect_adventurer = ((advfails/totalfailed))/adv_denom
print "suspicious adventurer: ", suspect_adventurer

cut_denom = (cutpass/totalpassed)+(cutfails/totalfailed)
suspect_cutpurse =((cutfails/totalfailed))/cut_denom
print "suspicious cutpurse: ", suspect_cutpurse

smith_denom = (smithpass/totalpassed)+(smithfails/totalfailed)
suspect_smithy =((smithfails/totalfailed))/smith_denom
print "suspicious smithy: ", suspect_smithy
print

parsed = open('rtresults/rc2_dominion.c.gcov', 'r')
pcontent = parsed.read().splitlines()
for line in pcontent:
    if '875' in line:
        spliced = line.split(':')
    smith_tot = spliced[0]
float(smith_tot)
print "smithy total: ", smith_tot
parsed.close()

parsed = open('rtresults/rc1_dominion.c.gcov', 'r')
pcontent = parsed.read().splitlines()
for line in pcontent:
    if '705' in line:
        spliced = line.split(':')
    cut_tot = spliced[0]
float(cut_tot)
print "cutpurse total: ", cut_tot
parsed.close()

parsed = open('rtresults/adv_dominion.c.gcov', 'r')
pcontent = parsed.read().splitlines()
for line in pcontent:
    if '757' in line:
        spliced = line.split(':')
    adv_tot = spliced[0]
float(adv_tot)
print "adventurer total: ", adv_tot
parsed.close()
