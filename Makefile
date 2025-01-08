PROJECT = SmartCalc
CC = g++
CCFLAGS = -I../src -Wall -Werror -Wextra -std=c++17
VIEW = view/*.cpp view/*.h
CONTROLLER = controller/*.cc controller/*.h
MODEL = model/*.cc model/*.h
TESTS_H = tests/*.h
TESTS_CC = tests/*.cc
SOURCE_CODE= $(VIEW) $(CONTROLLER) $(MODEL) $(TESTS_H)
TESTS = tests/*.cc model/*.cc
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -fPIC -O0
TESTFLAGS = -lgtest

all: install open

install:
	-mkdir build
	cd build && cmake ../CMakeLists.txt && make

open:
	open build/$(PROJECT).app

uninstall:
	-rm -rf build

clean:
	-rm -rf */*.DS_Store
	-rm -rf */*.o */*.a
	-rm -rf *gcno *.gcda *.info *.out *.gcov
	-rm -rf ./report
	-rm -rf *.zip */*.user
	-rm -rf ../build
	-rm -rf build
	-rm -rf gcov_report
	-rm -rf docs/html
	-rm -rf docs/docs

dvi:
	cd docs && doxygen Doxyfile
	open docs/html/index.html

dist: clean
	zip -r $(PROJECT).zip .

test:
	$(CC) $(CCFLAGS) $(TESTS) $(TESTFLAGS) -o test.out
	./test.out

gcov_report: clean
	mkdir $@
	$(CC) $(CCFLAGS) $(GCOV_FLAGS) $(TESTS) $(TESTFLAGS) -o $@.out
	./$@.out
	gcovr --exclude-unreachable-branches \
	--exclude-noncode-lines \
	--html-details \
	--html-theme github.dark-green \
	--html-title $(PROJECT) \
	-r . -o $@/$@.html -e 'tests' -e ".*\.h"
	rm -rf *.gc*
	open $@/$@.html

reinstall: uninstall clean install

style:
	clang-format -n --style=Google $(VIEW) $(CONTROLLER) $(MODEL) $(TESTS_H) $(TESTS_CC)

format:
	clang-format -i --style=Google $(VIEW) $(CONTROLLER) $(MODEL) $(TESTS_H) $(TESTS_CC)

valgrind: test
	$@ --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test.out
