/* CS2211a 2020 */
/* Rowena Shi */
/* November 16, 2020 */ 

// this file contains all the functions needed for the program
// main.c calls these functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#ifndef func1
#define func1

sentence* input(int *num_sentences) {

    sentence *sentence_mem = (sentence *)malloc(sizeof(sentence));
    int sentence_count = 0;
    char str[1000]; // character array for user input
    
    do {
        printf("\nPlease enter a string: ");
        gets(str);

        int letter_count = 0;
        int word_count = 0;

        word w; // initializes a word
        sentence s; // initializes a sentence
        s.num_words = 0;
        s.word_ptr = (word *)malloc(sizeof(word)); // dynamically allocates word memory for s.word_ptr
        w.ptr = (char *)malloc(sizeof(char)); // dynamically allocates character memory for w.ptr

        int i = 0;
        while(i <= strlen(str)) {
            if(str[i] != ' ' && str[i] != '\0') { // s[i] is a letter inside a word
                *(w.ptr + letter_count) = str[i]; // sets the value of str[i] to the memory space allocated for w.ptr
                letter_count++;
                w.ptr = (char *)realloc(w.ptr, (letter_count+1)*sizeof(char)); // dynamically adds a new memory space for a character
            }
            else if (str[i] == ' ') { // str[i] is a space (next letter starts a new word)
                if(letter_count == 0) { // ignores whitespace in front of the word
                    s.num_words = 0;
                    s.pos_in_collection = sentence_count;
                }
                else {
                    *(w.ptr + letter_count) = '\0'; // sets the last value of the word as null
                    *(s.word_ptr + word_count) = w; // sets the memory of the proper s address to w
                    word_count++;
                    s.word_ptr = (word *)realloc(s.word_ptr, (word_count+1)*sizeof(word)); // adds a new memory space in s for a word
                    w.ptr = (char *)malloc(sizeof(char)); // creates a new character space for a word
                    w.pos_in_sentence = word_count;
                    w.num_char = letter_count;
                    letter_count = 0; // resets letter count for new word
                }
            }
            else { // str[i] is null (end of str)
                *(w.ptr + letter_count) = '\0'; 
                *(s.word_ptr + word_count) = w;
                word_count++;
                w.pos_in_sentence = word_count;
                w.num_char = letter_count;
                s.pos_in_collection = sentence_count; // updates the position of s
                s.num_words = word_count;
                word_count = 0; // resets word count
                w.pos_in_sentence = word_count;
            }
            i++;
        }
        sentence_count++;
        s.pos_in_collection = sentence_count;
        sentence_mem = (sentence *)realloc(sentence_mem, (sentence_count+1)*sizeof(sentence));
        *(sentence_mem + sentence_count) = s;
    }
    while(strcmp(str, "") != 0); // while str is not empty, keep doing the stuff above
    *num_sentences = sentence_count; // updates what's stored in the address of num_sentences 
    return sentence_mem; // returns the entire sentence_mem;
}

void print_words(sentence *sentence_mem, int num_sentences) {
    printf("\nThese are all the words entered:\n\n");
    int i = 0;
    while(i < num_sentences) {
        for(int j = 0; j < (sentence_mem[i].num_words); j++) {
            printf("%s\n", (sentence_mem[i].word_ptr[j]).ptr);
        }
        i++;
    }
}

void print_sentences(sentence *sentence_mem, int num_sentences) {
    printf("\nThese are all the sentences entered: \n");
    int i = 0;
    while(i < num_sentences) {
        for(int j = 0; j < (sentence_mem[i].num_words); j++) {
            printf("%s ", sentence_mem[i].word_ptr[j].ptr);
        }
        printf("\n");
        i++;
    }
}

void search_word(sentence *sentence_mem, int num_sentences) {
    char str[1000];

    do {
        bool found = false;
        printf("\nPlease enter a word to search for: ");
        gets(str);

        if(strcmp(str, "") == 0) { // breaks if user did not enter anything
            printf("\nThank you for embarking on this journey, have a nice day! :)\n\n");
            break;
        }

        for(int i = 0; i < num_sentences; i++) {
            for(int j = 0; j < sentence_mem[i].num_words; j++) {
                if(strcmp(((sentence_mem[i].word_ptr[j]).ptr), str) == 0) {
                    if(i == 1 && j == 0) {
                        printf("%s found in line 1 position 1\n", str);
                    }
                    else {
                        printf("%s found in line %d position %d\n", str, sentence_mem[i].pos_in_collection, ((sentence_mem[i].word_ptr[j]).pos_in_sentence)+1);
                    }
                    found = true;
                }
            }
        }
        if(found == false) {
            printf("%s was not found in the lines entered.\n", str);
        }
    }
    while(strcmp(str, "") != 0);
}

void free_memory(sentence *sentence_mem, int *num_sentences) {
    int i = 0;
    while(i < *num_sentences) { // loops through sentences
        for(int j = 0; j < (sentence_mem[i].num_words); j++) { // loops through words in sentence
            free(sentence_mem[i].word_ptr[j].ptr); // frees char pointer
        }
        free(sentence_mem[i].word_ptr); // frees word pointer
        i++;
    }
    free(sentence_mem); // frees string pointer
}

#endif
