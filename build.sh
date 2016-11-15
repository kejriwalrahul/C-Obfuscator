# Tasks:

	# Check input syntax correctness 
	# gcc -fsyntax-only $1 
	
	# #include removal
	python Preprocessor/preprocess.py <$1 >tmp/preproc.c

	# Macro expansion
	gcc -E tmp/preproc.c -o tmp/macroexp.c
	
	# Conversion from C to subset of C (removes const etc and fully parenthasizes)
	cd Layer0 && echo "Executing Layer0" && java CParser < ../tmp/macroexp.c > ../tmp/temp0.c 
	cd ..

	# Identifier renaming
	cd Layer1 && echo "Executing Layer1" && java ParserMain <../tmp/temp0.c >../tmp/temp1.c
	cd ..

	# Declarations moved to topmost scope
	cd Layer2 && echo "Executing Layer2" && java ParserMain <../tmp/temp1.c 	>../tmp/temp2.c
	cd ..

	# Statement independentisation
	cd Layer3 && echo "Executing Layer3" && java ParserMain <../tmp/temp2.c 	>../tmp/temp3.c
	cd ..

	# Statement transformations
	cd Layer4 && echo "Executing Layer4" && python recurse.py
	
	# Reordering statements
	cd ../Layer6 && echo "Executing Layer6" && java ParserMain < ../tmp/temp4.c > ../tmp/temp5.c
	
	# Restore #includes
	cd ../tmp && cat deps temp5.c >output.c

	# Remove all the temporary files
	# rm temp*.c deps macroexp.c preproc.c
