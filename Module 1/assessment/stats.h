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
 * @file stats.h
 * @brief Definitions and macros required for the c1m1 assignment.
 *
 *
 * @author Peter Emad
 * @date 8/8/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief Prints the statistics of a given array
 *
 * This function takes the resulting statistics done on an array
 * which are: minimum, maximum, mean and median, and print those
 * values on the screen
 *
 * @param minimum The minimum number of the given array
 * @param maximum The maximum number of the given array
 * @param mean The mean of the given array
 * @param median The median of the given array
 *
 * @return void
 */
void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median);

/**
 * @brief Prints the contents of a given array
 *
 * This function takes the given array and prints it to the screen.
 *
 * @param array The first element of the array to be printed
 * @param length The length of the array
 *
 * @return void
 */
void print_array (unsigned char *array, unsigned int length);

/**
 * @brief Finds the median of the given array
 *
 * This function takes the given array adn finds its median.
 *
 * @param array The first element of the array to be processed
 * @param length The length of the array
 *
 * @return median The median value of the given array.
 */
unsigned char find_median (unsigned char *array, unsigned int length);

/**
 * @brief Finds the mean of the given array.
 *
 * This function takes the given array and finds its mean.
 *
 * @param array The first element of the array to be processed.
 * @param length The length of the array.
 *
 * @return mean The mean value of the given array.
 */
float find_mean (unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum of the given array.
 *
 * This function takes the given array and finds its minimum.
 *
 * @param array The first element of the array to be processed
 * @param length The length of the array.
 *
 * @return minimum THe minimum value of the given array
 */
unsigned char find_maximum (unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum of the given array
 *
 * This function takes the given array and finds its minimum.
 *
 * @param array The first element of the array to be processed.
 * @param length The length of the array
 *
 * @return minimum THe minimum value of the given array.
 */
unsigned char find_minimum (unsigned char *array, unsigned int length);

/**
 * @brief Sorts the given array from the largest to smalles
 *
 * This function takes the given array and its length, sorts the array from
 * the largest to smallest using bubble sort and returns the sorted array.
 *
 * @param array The first element of the array to be processed
 * @param length The length of the array
 *
 * @return void
 */
void sort_array (unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */