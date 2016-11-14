all: ParserMain.class

ParserMain.class: ParserMain.java visitor/Pass1.java visitor/Pass2.java
	javac ParserMain.java

clean:
	rm *.class visitor/*.class syntaxtree/*.class helper/*.class