CC = g++
CFLAGS = $(DEBUG) -Wall
DEBUG = -g
DEFINES =
PROG1 = chocan
UNIT1 = functional
UNIT2 = person
UNIT3 = people
UNIT4 = service_item
UNIT5 = service_directory
UNIT6 = invoice
UNIT7 = invoice_chain

PROGS = $(PROG1) 

all: $(PROGS)


$(PROG1): $(PROG1).o $(UNIT1).o $(UNIT2).o $(UNIT3).o $(UNIT4).o $(UNIT5).o $(UNIT6).o $(UNIT7).o
	$(CC) $(CFLAGS) -o $@ $^
	chmod a+rx,g-w $@

$(PROG1).o:  $(PROG1).cpp $(PROG1).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT1).o:  $(UNIT1).cpp $(UNIT1).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT2).o:  $(UNIT2).cpp $(UNIT2).hpp $(UNIT1).o Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT3).o:  $(UNIT3).cpp $(UNIT3).hpp $(UNIT1).o $(UNIT2).o Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT4).o:  $(UNIT4).cpp $(UNIT4).hpp $(UNIT1).o Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT5).o:  $(UNIT5).cpp $(UNIT5).hpp $(UNIT1).o $(UNIT4).o Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT6).o:  $(UNIT6).cpp $(UNIT6).hpp $(UNIT1).o Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT7).o:  $(UNIT7).cpp $(UNIT7).hpp $(UNIT1).o $(UNIT6).o Makefile
	$(CC) $(CFLAGS) -c $<

opt: clean
	make DEBUG=-O#

tar: clean
	tar cvfz $(PROG1).tar.gz *.[ch] ?akefile

# clean up the compiled files and editor chaff
clean cls:
	rm -f $(PROGS) *.o *~ \#*
