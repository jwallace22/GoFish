goFish: go_fish.o deck.o card.o player.o
	g++ -o goFish go_fish.o deck.o card.o player.o
demo.o: go_fish.cpp card.h deck.h player.h
	g++ -c go_fish.cpp
player.o: player.cpp deck.h card.h player.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -c card.cpp

