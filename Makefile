OBJ = main.o BrigManager.o Brig.o Cell.o Pirate.o Borcs.o Dorcs.o Porcs.o UImanager.o random.o CArray.o PArray.o

a4:	$(OBJ)
	g++ -o a4 $(OBJ)

main.o:	main.cc
	g++ -c main.cc

BrigManager.o:	BrigManager.cc BrigManager.h 
	g++ -c BrigManager.cc

UImanager.o:	UImanager.cc UImanager.h 
	g++ -c UImanager.cc

Cell.o:	Cell.cc Cell.h defs.h
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
    
PArray.o:	PArray.cc PArray.h
	g++ -c PArray.cc

CArray.o:	CArray.cc CArray.h
	g++ -c CArray.cc

random.o:	random.cc
	g++ -c random.cc

clean:
	rm -f *.o a4

