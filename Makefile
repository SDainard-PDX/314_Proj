CC = g++
CFLAGS = $(DEBUG) -Wall
DEBUG = -g
DEFINES =
PROG1 = chocan
UNIT[1] = functional
UNIT[2] = person
UNIT[3] = people
UNIT[4] = service_item
UNIT[5] = service_directory
UNIT[6] = invoice

PROGS = $(PROG1) 

all: $(PROGS)


$(PROG1): $(PROG1).o $(UNIT[1]).o $(UNIT[2]).o $(UNIT[3]).o $(UNIT[4]).o $(UNIT[5]).o $(UNIT[6]).o
	$(CC) $(CFLAGS) -o $@ $^
	chmod a+rx,g-w $@

$(PROG1).o:  $(PROG1).cpp $(PROG1).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT[1]).o:  $(UNIT[1]).cpp $(UNIT[1]).hpp Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT[2]).o:  $(UNIT[2]).cpp $(UNIT[2]).hpp $(UNIT) Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT[3]).o:  $(UNIT[3]).cpp $(UNIT[3]).hpp $(UNIT1) $(UNIT2) Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT[4]).o:  $(UNIT[4]).cpp $(UNIT[4]).hpp $(UNIT1) Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT[5]).o:  $(UNIT[5]).cpp $(UNIT[5]).hpp $(UNIT1) $(UNIT4) Makefile
	$(CC) $(CFLAGS) -c $<

$(UNIT[6]).o:  $(UNIT[6]).cpp $(UNIT[6]).hpp $(UNIT1) Makefile
	$(CC) $(CFLAGS) -c $<

opt: clean
	make DEBUG=-O#

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
#   https://www.youtube.com/watch?v=#m#8GqaOz90
git get gat:
	if [ ! -d .git ] ; then git init; fi
	git add *.[ch] ?akefile
	git commit -m"Gotta git that"
