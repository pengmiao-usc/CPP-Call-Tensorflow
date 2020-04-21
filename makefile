all:
	g++ -std=c++11 -Wall -O3 prediction.cpp -lpython3.6m -L/usr/include/python3.6m/ -I/usr/include/python3.6m/ -o pred_test
clean:
	rm pred_test
