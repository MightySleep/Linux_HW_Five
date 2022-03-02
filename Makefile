CC=g++
CFLAGS=-Wall -ggdb
RM=/bin/rm -f

.PHONY: tidy

wycat_: wycat tidy

wycat: wycat.c
	$(CC) $(CFLAGS) wycat.c -o wycat -I. 
tidy:
	$(RM) a.out core.*
