all: CParser.class

CParser.class: CParser.java visitor/Translator.java
	javac CParser.java

clean:
	rm *.class visitor/*.class syntaxtree/*.class