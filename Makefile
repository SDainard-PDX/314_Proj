DEBUG = -g
DEFINES =
CFLAGS = $(DEBUG) -Wall
PROG1 = chocan
PROG2 = functional
PROG3 = person
PROG4 = people

PROGS = $(PROG1) $(PROG2) $(PROG3) $(PROG4)

all: $(PROGS)


$(PROG1): $(PROG1).o $(PROG2).o $(PROG3).o $(PROG4).o
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
