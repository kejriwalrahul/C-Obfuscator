# Tasks:
	# Check input syntax correctness 
	# gcc -fsyntax-only $1 
	# #include removal
	python Preprocessor/preprocess.py <$1 >tmp/preproc.c
	# Macro expansion
	gcc -E tmp/preproc.c -o tmp/macroexp.c 
