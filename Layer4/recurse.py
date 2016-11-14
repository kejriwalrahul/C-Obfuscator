from subprocess import call
import sys
import filecmp

call("java ParserMain <../tests/testflattened.c >../tmp/temp1.c", shell=True)
call("java ParserMain <../tests/temp1.c >../tmp/temp2.c", shell=True)

flag = True
while not filecmp.cmp("../tmp/temp1.c", "../tmp/temp2.c"):
	print "iterating"
	if flag:
		call("java ParserMain <../tmp/temp2.c   >../tmp/temp1.c", shell=True)
	else:
		call("java ParserMain <../tests/temp1.c >../tmp/temp2.c", shell=True)
	flag = not flag