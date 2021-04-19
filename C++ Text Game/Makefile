output: main.o getNum.o Menu.o Space.o Bar.o Game.o Car.o Courtyard.o Museum.o Player.o
	g++ main.o getNum.o Menu.o Space.o Bar.o Game.o Car.o Courtyard.o Museum.o Player.o -o output

main.o: main.cpp
	g++ -c main.cpp

getNum.o: getNum.cpp getNum.hpp
	g++ -c getNum.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

Bar.o: Bar.cpp Bar.hpp
	g++ -c Bar.cpp

Car.o: Car.cpp Car.hpp
	g++ -c Car.cpp

Courtyard.o: Courtyard.cpp Courtyard.hpp
	g++ -c Courtyard.cpp

Museum.o: Museum.cpp Museum.hpp
	g++ -c Museum.cpp
	
Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp
	
make clean: 
	rm *.o output
	
