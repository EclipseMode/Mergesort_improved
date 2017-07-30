compile : improvedsort.c mergesort.c
	gcc -o improvedsort improvedsort.c
	gcc -o mergesort mergesort.c

execute : 
	./improvedsort && ./mergesort

clean :
	rm -f improvedsort mergesort
