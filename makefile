all:
	cd Layer1 && javac ParserMain.java
	cd Layer2 && javac ParserMain.java
	cd Layer3 && javac ParserMain.java
	cd Layer4 && javac ParserMain.java
	cd Layer6 && javac ParserMain.java

clean:
	rm tmp/*