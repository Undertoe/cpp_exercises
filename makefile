default: build

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  build    - build the project"
	@echo "  clean    - clean the project"
	@echo "  help     - print this help message"


clean: 
	rm -rf build build_test;

build:
	mkdir build; cd build; cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo; make; cp ../ModernCPPChallenge/runTests.sh ./ModernCPPChallenge; cd ModernCPPChallenge/; ./runTests.sh
