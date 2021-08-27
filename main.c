/* CS2211a 2020 */
/* Rowena Shi */
/* November 16, 2020 */ 

// this is the main file
// it executes the functions in functions.h

#include "headers.h"

int main() {
    int num_sentences;
    printf("\nWelcome to an abnormally hard assignment. I would like to thank you for embarking on this journey with me.\n");

    sentence *sentence_mem = input(&num_sentences);
    print_words(sentence_mem, num_sentences);
    print_sentences(sentence_mem, num_sentences);
    search_word(sentence_mem, num_sentences);
    free_memory(sentence_mem, &num_sentences);
    return 0;
}
