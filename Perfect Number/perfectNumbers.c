/**
 * Algorithms to show, return and check if a number is a
 * Perfect Number. A perfect number, sum(n) == n (excludeing n)
 * is the summation of n's divisors, is a number whos even
 * divisors sum to the number (n). The number (n) is not
 * included in the summation.
 * These algorithsm are unable to calculate past the 5th
 * perfect number as such a number exceedes the size of a
 * long integer.
 */

// TODO: Comment code
#include <math.h>
#include <stdio.h>

// Function definitions
void printPerfects(long, long);
long checkIfPerfect(long); // Requires a positive number greater than 1.
void nthPerfectNumber(int);

int main() {
    // Code to show results of functions
    printPerfects(0, 10000);

    puts("");

    long isItPerfect = 33550336;
    long perfectNumber = checkIfPerfect(isItPerfect);

    if (perfectNumber)
        printf("%li is Perfect\n", isItPerfect);
    else
        printf("%li is not Perfect\n", isItPerfect);

    puts("");

    isItPerfect = 33550335;
    perfectNumber = checkIfPerfect(isItPerfect);

    if (perfectNumber)
        printf("%li is Perfect\n", isItPerfect);
    else
        printf("%li is not Perfect\n", isItPerfect);

    puts("");

    nthPerfectNumber(4);

    return 0;
}

/**
 * Prints all perfect number from start to stop
 */
void printPerfects(long start, long stop) {
    // Iterate form star to stopt
    while (start <= stop) {
        // Set divisors summation value to 0
        long divisors = 0;

        // Check for perfect divisors, add to divisors if found
        // Stop half way to current start value as no perfect
        // divisors exist past the half of start value
        for (long i = 1; i <= (start / 2) + 1; ++i)
            divisors += (start % i == 0) ? i : 0;

        // Check if divisors sum is equal to the start value
        // print if it is true.
        // By definition perfect numbers are greater than 1.
        if ((divisors == start) && (start > 1))
            printf("%li is Perfect\n", start);

        // Goto the next number
        ++start;
    }
}

/**
 * Checks if the passed number is a perfect number
 * returns 1 if true 0 if false
 */
long checkIfPerfect(long n) {
    // Set divisors summation to 0
    long divisors = 0;

    // Iterate through all possible perfect divisors.
    // Check if it is a perfect divisor.
    // Add the divisor to divisor variable if it is perfect.
    // Stop half was to the passed number as there are no
    // perfect divisors beyond this point.
    for (long i = 1; i <= (n / 2) + 1; ++i)
        divisors += (n % i == 0) ? i : 0;

    // return 1 if perfect else return 0
    return (divisors == n) ? 1 : 0;
}

void nthPerfectNumber(int n) {
    int numPerfectNums = 0;
    long checkNum = 0;

    while (numPerfectNums < n) {
        long divisors = 0;

        ++checkNum;

        for (long i = 1; i <= (checkNum / 2) + 1; ++i)
            divisors += (checkNum % i == 0) ? i : 0;

        if ((divisors == checkNum) && (checkNum > 1))
            ++numPerfectNums;
    }

    printf("The %i-th perfect number is %li\n", n, checkNum);
}

