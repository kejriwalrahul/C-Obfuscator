import sys
file = sys.stdin

text = ""
for line in file:
	if line[0]!='#':
		text += line

file.close()

print text