all: main.o time.o city.o core.o funcCity.o funcTrain.o functions.o menu.o passenger.o train.o funcPassenger.o
	g++ main.o time.o city.o core.o funcCity.o funcTrain.o functions.o menu.o passenger.o train.o funcPassenger.o -o Project_Train

main.o: main.cpp
	g++ -c main.cpp

time.o: time.cpp
	g++ -c time.cpp

city.o: city.cpp
	g++ -c city.cpp

core.o: core.cpp
	g++ -c core.cpp

funcCity.o: funcCity.cpp
	g++ -c funcCity.cpp

funcTrain.o: funcTrain.cpp
	g++ -c funcTrain.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

passenger.o: passenger.cpp
	g++ -c passenger.cpp

train.o: train.cpp
	g++ -c train.cpp

funcPassenger.o: funcPassenger.cpp
	g++ -c funcPassenger.cpp

clean:
	rm -rf *.o Project_Train

refresh:
	rm -rf *.o Project_Train
