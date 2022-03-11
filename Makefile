CC=gcc
CFLAGS=-Wall -ggdb
RM=/bin/rm -f

.PHONY: tidy

wyla_: wyls tidy

wyls: wyls.c
	$(CC) $(CFLAGS) wyls.c -o wyls -I. 
tidy:
	$(RM) a.out core.*
