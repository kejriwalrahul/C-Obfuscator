all: ParserMain.class

ParserMain.class: ParserMain.java visitor/GJDepthFirst.java 
	javac ParserMain.java

clean:
	rm *.class visitor/*.class syntaxtree/*.class