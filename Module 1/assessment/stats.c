/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * This file includes all the required implementation of the functions in the c1m1 assignment
 *
 * @author Peter Emad
 * @date 8/8/2024
 *
 */



#include <stdio.h>
#include <stdbool.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                 114, 88,   45,  76, 123,  87,  25,  23,
                                 200, 122, 150, 90,   92,  87, 177, 244,
                                 201,   6,  12,  60,   8,   2,   5,  67,
                                 7,  87, 250, 230,  99,   3, 100,  90};

    /* Other Variable Declarations Go Here */
    unsigned char minimum = 0;
    unsigned char maximum = 0;
    float mean = 0;
    unsigned char median = 0;

    /* Statistics and Printing Functions Go Here */
    printf("Array before sorting: \n");
    print_array((unsigned char *) &test, SIZE);
    median = find_median((unsigned char *) &test, SIZE);
    mean = find_mean((unsigned char *) &test, SIZE);
    maximum = find_maximum((unsigned char *) &test, SIZE);
    minimum = find_minimum((unsigned char *) &test, SIZE);
    print_statistics(minimum, maximum, mean, median);
    sort_array((unsigned char *) &test, SIZE);
    printf("Array after sorting: \n");
    print_array((unsigned char *) &test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char minimum, unsigned char maximum, float mean, unsigned char median) {
    printf("Minimum = %d\n", minimum);
    printf("Maximum = %d\n", maximum);
    printf("Mean = %f\n", mean);
    printf("Median = %d\n", median);

}

void print_array(unsigned char *array, unsigned int length) {
    for (int i = 0; i<length; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

unsigned char find_median (unsigned char *array, unsigned int length) {
    unsigned char median = 0;
    median = *(array + (length / 2 ) - 1);
    return median;
}

float find_mean (unsigned char *array, unsigned int length) {
    unsigned int acc = 0;
    float mean = 0;
    for (int i = 0; i<length; i++) {
        acc = acc + array[i];
    }
    mean = acc / ((float) length);
    return mean;
}

unsigned char find_maximum (unsigned char *array, unsigned int length) {
    unsigned char max = *array;
    for (int i = 1; i < length; i++) {
        if(*(array + i) > max) {
            max = * (array + i);
        }
    }
    return max;
}

unsigned char find_minimum (unsigned char *array, unsigned int length) {
    unsigned char min = *array;
    for (int i = 1 ; i<length; i++) {
        if(min > *(array + i)) {
            min = *(array + i);
        }
    }
    return min;
}

void sort_array (unsigned char *array, unsigned int length) {
    for (int i = 0; i<length - 1; i++) {
        if ( *(array + i) < *(array + i + 1)){
            unsigned char temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i = -1;
            continue;
        }
    }
}
