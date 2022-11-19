CC = g++
CFLAGS = $(DEBUG) -Wall
DEBUG = -g
DEFINES =
PROG1 = chocan
PROG2 = functional
PROG3 = person
PROG4 = people
PROG5 = service_item
PROG6 = service_directory
PROG7 = invoice
PROG8 = invoice_chain

PROGS = $(PROG1) #$(PROG2) $(PROG3) $(PROG4) $(PROG5) $(PROG6) $(PROG7) $(PROG8)

all: $(PROGS)


$(PROG1): $(PROG1).o $(PROG2).o $(PROG3).o $(PROG4).o $(PROG5).o $(PROG6).o $(PROG7).o $(PROG8).o
	$(CC) $(CFLAGS) -o $@ $^
	chmod a+rx,g-w $@

$(PROG1).o:  $(PROG1).cpp $(PROG1).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG2).o:  $(PROG2).cpp $(PROG2).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG3).o:  $(PROG3).cpp $(PROG3).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG4).o:  $(PROG4).cpp $(PROG4).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG5).o:  $(PROG5).cpp $(PROG5).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG6).o:  $(PROG6).cpp $(PROG6).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG7).o:  $(PROG7).cpp $(PROG7).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(PROG8).o:  $(PROG8).cpp $(PROG8).hpp Makefile
	$(CC) $(CFLAGS) -c $<

opt: clean
	make DEBUG=-O3

tar: clean
	tar cvfz $(PROG1).tar.gz *.[ch] ?akefile

# clean up the compiled files and editor chaff
clean cls:
	rm -f $(PROGS) *.o *~ \#*

ci:
	if [ ! -d RCS ] ; then mkdir RCS; fi
	ci -t-none -m"lazy-checkin" -l *.[ch] ?akefile *.bash

# if you are in more of a git Boom Boom Pow mood.
# "Gotta git [sic] that"
#   https://www.youtube.com/watch?v=4m48GqaOz90
git get gat:
	if [ ! -d .git ] ; then git init; fi
	git add *.[ch] ?akefile
	git commit -m"Gotta git that"
