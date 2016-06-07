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

#parsed = open('parsed_utr.out', 'w+')
#
#with open('utresults/unittestresults.out', 'r') as f:
##    print 'FILED OPENED: ', f.name, "\n"
#    #content = [x.strip('\n') for x in f.readlines()]
#    # Reads text until the end of the block
#    content = f.read().splitlines()
#    for line in content:
#        if line.strip() == 'Starting game.':
#            break
##        print "Read line: ", (line)
#        parsed.write(line)
#        parsed.write('\n')

#    for line in content:    
#        if line.strip() == 'GCOV AFTER PLAYING A GAME':
#            break
#        print "Read line: ", (line)

## Close opened files
#f.close()
#parsed.close()

spliced = []

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
#print "denom:", adv_denom
suspect_adventurer = ((advfails/totalfailed))/adv_denom
print "sa: ", suspect_adventurer

cut_denom = (cutpass/totalpassed)+(cutfails/totalfailed)
suspect_cutpurse =((cutfails/totalfailed))/cut_denom
print "sc: ", suspect_cutpurse

smith_denom = (smithpass/totalpassed)+(smithfails/totalfailed)
suspect_smithy =((smithfails/totalfailed))/smith_denom
print "ss: ", suspect_smithy

#failures = open('failed.out', 'w+')
#start_print = False
#
#parsed = open('parsed_utr.out')
#pcontent = parsed.read().splitlines()
#s = mmap.mmap(parsed.fileno(), 0, access=mmap.ACCESS_READ)
#if s.find('FAILED ASSERTION') != -1:
#    for aline in pcontent:
#        if start_print or 'FAILED ASSERTION' in aline:
#            failures.write(aline)
#            failures.write('\n')
#            # print aline
#            start_print = True
#            if "Creating 'dominion.c.gcov'" in aline:
#                start_print = False
#
## Close opened files
#parsed.close()
#failures.close()
#
#spliced = []
#ft = []
#
#failures = open('failed.out', 'r')
#fcontent = failures.read().splitlines()
#n = mmap.mmap(failures.fileno(), 0, access=mmap.ACCESS_READ)
#if n.find('Testing') != -1:
#    for mline in fcontent:
#        if 'Testing' in mline:
#            spliced =  mline.split()
#            ft.append(spliced[1])
#print ft
#
## Closed opened file
#failures.close()

# auggggggggh
