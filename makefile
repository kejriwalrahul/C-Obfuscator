all: 
	$(MAKE) -C Layer0
	$(MAKE) -C Layer1
	$(MAKE) -C Layer2
	$(MAKE) -C Layer3
	$(MAKE) -C Layer4
	$(MAKE) -C Layer6

clean:
	$(MAKE) -C Layer0 clean
	$(MAKE) -C Layer1 clean
	$(MAKE) -C Layer2 clean
	$(MAKE) -C Layer3 clean
	$(MAKE) -C Layer4 clean
	$(MAKE) -C Layer6 clean