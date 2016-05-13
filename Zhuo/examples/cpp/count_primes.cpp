/// @example count_primes.cpp
/// This example shows how to count primes.

#include <primesieve.hpp>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
extern uint64_t numPrimeWithSeven; /// by Zhuo
int main(int, char** argv)
{
  /// uint64_t count = primesieve::count_primes(0, 1000);
  /// std::cout << "Primes below 1000 = " << count << std::endl;
  
  uint64_t start = 1;
  uint64_t stop = 1000000000;
  if (argv[1])
    start = std::atol(argv[1]);
  if (argv[2])
    stop = std::atol(argv[2]);
  /// use multi-threading for large intervals
  uint64_t count = primesieve::parallel_count_primes(start, stop);
  /// uint64_t count = primesieve::count_primes(start, stop);
  // std::cout << "The result is " << count << std::endl;
  // std::cout << "Count of primes with 7 as digit = " << numPrimeWithSeven << std::endl;
  std::cout << count - numPrimeWithSeven << std::endl;
  /// std::cout << "Primes below 10^9 = " << count << std::endl;

  return 0;
}
