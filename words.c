#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"


char **read_words(const char *input_filename, int *nPtr){
	FILE *fptr;
	    fptr = fopen(input_filename,"r");

	    fscanf(fptr, "%d", nPtr);

    char **word_list;

    word_list = (char**)malloc(*nPtr *sizeof(char*));
        char str[1000];

        for(int i=0; i<*nPtr; i++) {
                fscanf(fptr,"%s",str);
                int length = strlen(str);
                word_list[i] = (char*)calloc(length+1, sizeof(char));
                // length+1 characters are needed to store string
                // length characters are of string and remaining one is terminating null character that is present at end of strings

                strcpy(word_list[i],str);
            }


    return word_list;

}

int compare_str(const char *str1,const char *str2){

	// alphabetically compares two strings.
    //If str2 is alphabetically smaller than str1 function returns 1 and if str1 is smaller function returns 0

	    int length1 = strlen(str1);
	    int length2 = strlen(str2);
	    int min;
	    if(length1 < length2) {
	        min = length1;
	    }
	    else{
	        min = length2;
	    }
	    for(int i=0; i<min; i++){
	        if(str1[i]<str2[i]){
	        	 return 1;
	        }
	        else if(str1[i]>str2[i]){
	        	 return 0;
	        }
	     }
	        	    if(min == length1){
	        	    	return 1;
	        	    }

	        	    else{
	        	    	return 0;
	        	    }
    
}


void sort_words(char **words, int size){
	//  insertion sort algorithm
	    int i,j;
	    char* key;
	    for (i = 1; i < size; i++) {
	        key = words[i];
	        j = i - 1;

	        while (j >= 0) {
	            //  compare to strings
	            if(strcmp(words[j],key)==-1) {
	                break;
	            }
	            words[j + 1] = words[j];
	            j = j - 1;
	        }
	        words[j + 1] = key;
	    }
}


void sort2_words(char **words, int size){

	// use  selection sort algorithm
	    int i, j, min_idx;

	    for (i = 0; i < size; i++) {
	        min_idx = i;
	        for (j = i+1; j < size-1; j++) {
	            if((words[j]<words[min_idx])) {
	                min_idx = j;
	            }
	        }

	        // Swap the found minimum element with the first element
	    }

	    char* tempr = words[min_idx];
	    	         words[min_idx] = words[i];
	    	         words[i] = tempr;

}


