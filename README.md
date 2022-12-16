# pretty_number_counter
## Task details
Calculate the number of pretty numbers of length *N* (including leading zeros) in a base *B* numeral system. The number is considered pretty if the sum of the first *M* digits equals to the sum of the last *M* digits.

## Solution
Lets divide the number into 3 parts: starting region (the first *M* digits), unused digits and ending region (the last *M* digits).

![pnc1](https://user-images.githubusercontent.com/8525363/208158610-547b6b02-a201-4a88-b20e-e2ad7b4640ad.PNG)

We can assume that starting and ending regions do not overlap because there is no difference whether the digits in the middle contribute to both sums or to none of them.

Lets denote the number of different digit sequences of length *L* with sum *S* as *sums(L, S)*. We can easily calculate all *sums(M, 0 ≤ S < B*M)* using dynamic programming and the following recursive formula:

![pnc2](https://user-images.githubusercontent.com/8525363/208158646-bfefbf2e-17c1-4a10-ae82-de1d561690ba.PNG)

For each sum *S*, there are *sums(M, S)* different starting regions with sum *S* and *sums(M, S)* different ending regions with sum *S* - *sums(M, S)^2* combinations in total. We can calculate the total number of "pretty" combinations by iterating over all possible sums *S*.

Finally, we neet to take unused digits into account. They can be anything, so for each unused digit, we need to multiply the result by *B*. This gives final answer.

For example, for *B=13*, *N=13*, *M=6* there are *1107623942191* "pretty" numbers according to this algorithm.
