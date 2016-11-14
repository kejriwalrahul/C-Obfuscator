all: 
	cd Layer0 && javac CParser.java
	cd Layer1 && javac ParserMain.java
	cd Layer2 && javac ParserMain.java
	cd Layer3 && javac ParserMain.java
	cd Layer4 && javac ParserMain.java
	cd Layer6 && javac ParserMain.java

clean:
	rm tmp/* Layer*/*.class Layer*/vistor/*.class Layer*/syntaxtree/*.class Layer*/helper/*.class