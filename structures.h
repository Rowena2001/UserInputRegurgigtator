/* CS2211a 2020 */
/* Rowena Shi */
/* November 16, 2020 */ 

// this file defines the structures word and sentences

#ifndef structures
#define structures
typedef struct word {
    char *ptr;
    int num_char;
    int pos_in_sentence;
} word;

typedef struct sentence {
    word *word_ptr;
    int num_words;
    int pos_in_collection;
} sentence;

#endif
