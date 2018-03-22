
bin/dameo: obj/main.o obj/plateau.o obj/pions.o obj/joueur.o
	g++ -o bin/dameo obj/main.o obj/plateau.o obj/pions.o obj/joueur.o

obj/plateau.o: src/plateau.cpp header/plateau.h
	g++ -o obj/plateau.o -c src/plateau.cpp

obj/pions.o: src/pions.cpp header/pions.h
	g++ -o obj/pions.o -c src/pions.cpp

obj/joueur.o: src/joueur.cpp header/joueur.h
	g++ -o obj/joueur.o -c src/joueur.cpp



obj/main.o: src/main.cpp header/joueur.h
	g++ -o obj/main.o -c src/main.cpp

clean:
	rm -rf obj/*.o

mrproper: clean
	rm -rf bin/dameo
