FLAGS = -std=c11 -g -Wall -Werror -Wextra
ASAN = #-fsanitize=address
TEST_LIBS = s21_math_test.c

LIBS_MACOS = -L /usr/local/lib -lcheck
LIBS_LINUX = -lcheck -lsubunit -lpthread -lrt -lm -D_GNU_SOURCE

OS = $(shell uname)
ifeq ($(OS), Darwin)
OPEN = open gcov_report/index.html
LIBS = $(LIBS_MACOS)
LEAK_CHECK = leaks --atExit -- ./test
endif

ifeq ($(OS), Linux)
OPEN = open gcov_report/index.html
LIBS = $(LIBS_LINUX)
LEAK_CHECK = valgrind --leak-check=full --show-leak-kinds=all -s ./test
endif

all: clean s21_math.a

test: clean s21_math.a
	gcc $(FLAGS) -g $(TEST_LIBS) -L. s21_math.a -lcheck --coverage -o test
	./test

s21_math.a:
	gcc $(FLAGS) -g -c s21_abs.c s21_acos.c s21_asin.c s21_atan.c s21_ceil.c s21_cos.c s21_exp.c s21_fabs.c s21_floor.c s21_pow.c s21_sin.c s21_sqrt.c s21_tan.c s21_fmod.c s21_log.c
	ar rcs s21_math.a s21*.o
	cp s21_math.a libs21_math.a

gcov_report: test
	gcov -fb $(TEST_LIBS)
	gcovr -r . --html --html-details -o coverage_report.html

check: clean s21_math.a cppcheck cpplint

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(TEST_LIBS) s21_math.h
cpplint:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm CPPLINT.cfg

clean:
	rm -rf *.o *.a *.html *.css *.info a.out *.gcov
	rm -rf test test_with_gcov
	rm -rf *.gcno *.gcda *.info
	rm -rf gcov_report
	rm -rf test
	rm  -rf test.dSYM