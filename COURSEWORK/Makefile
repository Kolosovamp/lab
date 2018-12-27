all: start make clean

start:  analysis_of_text.o sort_of_text.o print_unique_words.o replace_date.o delete_some_sent.o compare_str.o get_sentence.o main.o
	gcc analysis_of_text.o compare_str.o sort_of_text.o print_unique_words.o replace_date.o delete_some_sent.o get_sentence.o main.o -o main
compare_str.o: compare_str.c
	gcc -c compare_str.c
main.o: main.c
	gcc -c main.c
analysis_of_text.o: analysis_of_text.c compare_str.o
	gcc -c analysis_of_text.c compare_str.o
sort_of_text.o: sort_of_text.c
	gcc -c sort_of_text.c
print_unique_words.o: print_unique_words.c
	gcc -c print_unique_words.c
replace_date.o: replace_date.c
	gcc -c replace_date.c 
delete_some_sent.o: delete_some_sent.c
	gcc -c delete_some_sent.c
get_sentence.o: get_sentence.c
	gcc -c get_sentence.c
clean:
	rm -f *.o main
make:
	./main
