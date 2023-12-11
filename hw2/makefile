# target : dependencies / prereq

flags = -std=c++20 -I .

test_compute : test_compute.cc operator_functions.cc
	g++ $(flag) $^ -o $@

test :
	./test_compute
