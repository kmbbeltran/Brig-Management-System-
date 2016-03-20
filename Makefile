OBJ = main.o BrigManager.o Brig.o Cell.o Pirate.o Borcs.o Dorcs.o Porcs.o UImanager.o random.o
a5:	$(OBJ)
	g++ -o a5 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BrigManager.o:	BrigManager.cc BrigManager.h 
	g++ -c BrigManager.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

Cell.o:	Cell.cc Cell.h defs.h PArray.h
	g++ -c Cell.cc

Brig.o:	Brig.cc Brig.h defs.h
	g++ -c Brig.cc

Pirate.o:	Pirate.cc Pirate.h
	g++ -c Pirate.cc
    
Dorcs.o:	Dorcs.cc Dorcs.h
	g++ -c Dorcs.cc

Borcs.o:	Borcs.cc Borcs.h
	g++ -c Borcs.cc

Porcs.o:	Porcs.cc Porcs.h
	g++ -c Porcs.cc

random.o:	random.cc
	g++ -c random.cc

clean:
	rm -f *.o a5

