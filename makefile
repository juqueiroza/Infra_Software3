bin: main.c
	gcc -lpthread -o $@ $<

.PHONY: run clean 

run: 
	./bin

clean: 
	rm bin
