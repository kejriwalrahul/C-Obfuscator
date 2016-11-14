from subprocess import call
import sys
import filecmp

call(["ls","-l"])
print "here"
call(["java", "ParserMain", "<"+sys.argv[1], ">../tmp/temp1.c"])
print "here2"
call(["java", "ParserMain", "<../tmp/temp1.c", ">../tmp/temp2.c"])
print "here3"

flag = True
while not filecmp.cmp("../tmp/temp1.c", "../tmp/temp2.c"):
	print "iterating"
	if flag:
		call(["java", "ParserMain", "<../tmp/temp2.c", ">../tmp/temp1.c"])
	else:
		call(["java", "ParserMain", "<../tmp/temp1.c", ">../tmp/temp2.c"])
	flag = not flag