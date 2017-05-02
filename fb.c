/*
 * Fizz-Buzz without 'if'
 * (c) 2013-2017 Marc Santoro <marc.santoro@gmail.com>
 * 
 *
 * There's lots of branching here, but no explicit conditional
 * logic. This is really just a use of tail recursion and a
 * pair of manually-constructed jump tables. 
 *
 */

#include <stdio.h> // for printf
#include <stdlib.h>  // for exit

// every function except for main conforms to this prototype
typedef void (*fptr1)(int);

void fizz(int n) {
  printf("Fizz\n");
}

void buzz(int n) {
  printf("Buzz\n");
}

void fizzbuzz(int n) {
  printf("FizzBuzz\n");
}

void prnt(int n) {
  printf("%d\n", n);
}

void iter(int n) {
  /* Magic Part 1. Use a 4-element jump
   * table to branch to the appropriate printing
   * function based on whether the number is
   * divisible by 15, 5, 3, or none.
   */
  fptr1 pts[] = { fizzbuzz, buzz, fizz, prnt };
  int a = ((n % 3) + 2) / 3; // Not divisible by 3? 
  int b = ((n % 5) + 4) / 5; // Not divisible by 5?
  /* c is the index into the jump table pts. 
   * Generated in this way so that I don't need
   * to use the equality operator.
   */
  int c = b * 2 + a;
  pts[c](n);
}

void finish(int n) {
  exit(0);
}

void loop(int n) {
  /* Magic Part 2. Use tail recursion and a small jump
   * table to evaluate a function over the first one-hundred positive
   * integers.
   */
  fptr1 pts2[] = { iter, finish };
  pts2[n/101](n);
  loop(n + 1);
}

int main() {
  loop(1);
  return 0;
}
