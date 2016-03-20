Kelly Maclauchlan
Katherine Beltran

This program is a modification of a4:
This is a program that manages pirates in cells on the brig.
The user can add and remove pirates to the cells and check to see a
manifest of pirates in the brig divided by cells.

The polymorphic feature that we have added is that each type of pirate 
has a different weapon to fight with. The user can prompt 2 different 
pirates to fight against each other. The way the fighting function 
works is that it works in a rock, paper, scissor kind of manner
in which a swords beats a cannon, a cannon beats a riffle, and a riffle
beats a sword. The different types of Pirates are the concrete classes
and the Pirate class is the abstract class with a pure virtual function
of getWeapon. 

UML diagram is also in the tar folder

The source files used in this project are:
Brig.cc
Brig.h
BrigManager.cc
BrigManager.h
Cell.cc
Cell.h
defs.h
main.cc
Pirate.cc
Pirate.h
Borcs.h
Borcs.cc
Dorcs.h
Dorcs.cc
Porcs.h
Porcs.cc
PArray.h
random.cc
Storage.cc
Storage.h
UImanager.cc
UImanager.h

to run simply go to the folder where the code is located and type in: make ,to compile
then type in: ./a5 ,to run the program
