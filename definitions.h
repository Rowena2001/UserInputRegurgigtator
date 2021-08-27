/* CS2211a 2020 */
/* Rowena Shi */
/* November 16, 2020 */ 

// this file includes all the prototypes of the functions in functions.h

#include "structures.h"
#ifndef dH
    #define dH
    sentence* input(int *num_sentences);
    void print_words(sentence *sentence_mem, int num_sentences);
    void print_sentences(sentence *sentence_mem, int num_sentences);
    void search_word(sentence *sentence_mem, int num_sentences);
    void free_memory(sentence *sentence_mem, int *num_sentences);
#endif
