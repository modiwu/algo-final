# Algo-final pre

## code

- Variables 
  - `n`: input <u>integer</u>
  - `UPPER_BOUND`: input <u>integer</u>
  - `primeTable`: a <u>vector</u> of booleans indicating whether each number up to `UPPER_BOUND` is prime or not
  - `dp`: a <u>map</u> that associates integers with strings, where `dp[i]` will store the required string for integer `i`



- Functions 

  - `generate_primeTable()`: 

    precomputes a boolean table (`primeTbale`) using the Sieve of Eratosthenes algorithm

    - initializes `primeTable` with `true` for all values initially
    - marks the multiples of each number starting from 2 as `false`, indicating that they are not prime.

  - `minstring(string s1, string s2)`: 

    takes two strings 's1' and 's2' as input and returns the shorter or smaller of the two strings

    - first checks if the lengths of the two strings are different. If they are, it returns the shorter string
    - if the lengths are the same, it returns the string that maps to a smaller integer value(binary value)

  - `shortestAnswerString`:

    uses dynamic programming to solve a problem and returns the required string

    - initializes a boolean flag `flag` to keep track of whether a prime less than `UPPER_BOUND` has been found

    - initializes a string `ans` consisting of `UPPER_BOUND-n` '1' characters

    

    - initializes the `dp` map with base cases
      - `dp[n+1]='1'`  `dp[n+2]='11'` $\cdots$  `dp[n+n]='11...1'`
      - `dp[2n+1]='0'` 
    - iterates over integers form $2n + 2$ to `UPPER_BOUND` and calculates the required strings using dynamic programming logic
      - if i is even: `dp[i]='1'+dp[i-1]`
      - if i is odd: `dp[i]=minstring('0'+dp[(i-1)/2], '1'+dp[i-1])`

    

    - iterates over integers from $n +1$ to `UPPER_BOUND` and checks for prime numbers. If a prime is found, it updates `ans` using the `minstring` function
    - if no prime number is found, it sets `ans` to "-" as specified in the problem

