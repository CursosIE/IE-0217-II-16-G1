all:
	gcc -o suma suma.c
	g++ -o suma+ suma.c++

.PHONY: clean
clean:
	rm suma suma+

.PHONY: run
run:
	./suma $(ARGS)
	./suma+ $(ARGS)
	python suma.py $(ARGS)
