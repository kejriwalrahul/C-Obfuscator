from subprocess import call
import sys
import filecmp

call("java ParserMain <../tmp/temp3.c >../tmp/t1.c", shell=True)
call("java ParserMain <../tmp/t1.c >../tmp/t2.c", shell=True)

flag = True
f = open("../tmp/count", "r")

count = int(f.readline())-1

while count:
	print "iterating"
	if flag:
		call("java ParserMain <../tmp/t2.c   >../tmp/t1.c", shell=True)
	else:
		call("java ParserMain <../tmp/t1.c >../tmp/t2.c", shell=True)
	flag = not flag
	count -= 1

if flag:
	call("mv ../tmp/t2.c ../tmp/temp4.c" , shell=True)
	call("rm ../tmp/t1.c", shell=True)
else:
	call("mv ../tmp/t1.c ../tmp/temp4.c" , shell=True)
	call("rm ../tmp/t2.c", shell=True)

call("rm ../tmp/count", shell=True)