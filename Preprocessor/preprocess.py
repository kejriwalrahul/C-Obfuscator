import re
import sys

dependencies = []
def getdep(s):
	dependencies.append(s.group())
	return ''

def extractdep(text, regex):
	found = True
	while found:
		res = re.sub(regex, getdep, text, 0, 0)
		found = (text != res)
		text = res

	return text

file = sys.stdin

text = ""
for line in file:
	text += line

file.close()

stdlib = r'#\s*include\s*<[a-zA-Z0-9_./]*>'
usrlib = r'#\s*include\s*"[a-zA-Z0-9_./]*"'

text = extractdep(text, stdlib)
text = extractdep(text, usrlib)

print text
# print dependencies

file = open('../deps', 'w')
for dep in dependencies:
	file.write(dep + "\n")
file.close()