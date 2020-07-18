#include <stdio.h>
#include <stdlib.h>
#include <string.h>  /* this library file is used to use all the
string operators */
#include <assert.h> /* this library is used to use assert
statement in program */
int elementry_sorting(int k[], int counter); /* function to use
minimum sorting */
int bubble_sorting(int k[], int counter); /* function to use
 bubble_sorting method */
int usage_message(char *name); /* function to print
usage_message in program */
int usage_message(char *name) /* usage_message program start from here */
{
fprintf(stderr, "usage: %s[-b] [-q] number1 [number2...](maximum 32 numbers)\n", name);
exit(EXIT_FAILURE); /* this will exit the program abnormally, as required */
}
int main(int argc, char *argv[])
{
int bubble = 0; /* flag to indicate bubble method */
int noprint = 0; /* flag to suppress the printing */
int i = 1; /* loop counter */
int counter = 0; /* countes the number of integers in char array */
int k[32]; /* integer array to store the integers from character array */
while (i < (argc)) /* loop to go through all the elements in char array */
{
if (strcmp(argv[i], "-b") == 0) /* this condition checkes weather
bubble_sorting is used or not */
{
bubble = 1; /* changes the bubble flag to true case */
}
else if(strcmp(argv[i], "-q") == 0) /* condition check to suppress the
 output or not */
{
noprint = 1; /* suppresses the output */
}
else
{
k[counter] = atoi(argv[i]); /* changes string to integer and store them
in integer array */
counter = counter + 1; /* number of integers */
}
i = i + 1; /* loop counter updation */
if(counter > 32) /* checks number of integers in new array */
{
usage_message(argv[0]); /* prints usage message when number of
integers increased from 32 */
exit(1); /* exits abnormally */
}
}
if(counter == 0) /* to check minimum number of integers */
{
usage_message(argv[0]);
exit(1);
}
if (bubble == 1)
{
bubble_sorting(k, counter); /* function call to use bubble sorting */
}
else
{
elementry_sorting(k, argc); /* function call to use minimum sorting */
}
int l ;
if(noprint != 1) /* true case suppresses output */
{
for(l = 0; l < counter; l++) /* prints sorted integer */
{
printf("%d \n", k[l]);
}
}
/*
int p;
for(p = 0; p < counter; p++)
{
assert (k[p] < k[p + 1]);
} */
exit(0);
}

int elementry_sorting(int k[], int counter)
/* this is the minimum sorting method provided in
lab slides */
{
int i, j, temp, smallest = 0;
for(i = 0; i < counter - 1; i++)
{
for(j = i + 1; j < counter - 1; j++)
{
if(k[i] > k[j])
{
temp = k[i] ;
k[i] = k[j] ;
k[j] = temp ;
}
}
}
return 0;
}

int bubble_sorting(int k[], int counter)
/* this is the bubble sorting function required in lab in which
two elements are compared
and the next upto the end */
{
int index, swap;
int check = 1;
while (check == 1)
{
check = 0;
for (index = 1; index < counter; index++)
{
if (k[index - 1] > k[index])
{
swap = k[index];
k[index] = k[index - 1];
k[index - 1] = swap;
check = 1;
}
}
}
return 0;
}
