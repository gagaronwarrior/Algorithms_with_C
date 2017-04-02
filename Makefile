# Makefile to create static library and test client executable.

.PHONY:all

all:
	cd src/ && $(MAKE) all
		
.PHONY: clean

clean:
	cd src/ && $(MAKE) clean
    
