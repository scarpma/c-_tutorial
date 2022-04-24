#include <string.h>
#include <iostream>
using namespace std;

int *compute_first_n_primes(int n) {
    int *primeNums;
    int foundNums = 1;
    int currentNum = 2;
    bool divides = false;
    int nOps = 0;
    primeNums = new int[n];
    primeNums[0] = 1;

    while (foundNums < n) {
        currentNum++;
        divides = false;
        for (int i=currentNum-1;i>1;i--) {
            nOps++;
            if (currentNum%i==0) {
                divides = true;
                break;
            }
        }
        if (not divides) {
            primeNums[foundNums] = currentNum;
            foundNums++;
        }
    }
    cout << "#################################\n";
    printf("number of operations: %d\n", nOps);
    cout << "#################################\n";
    return primeNums;
}

int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);
    int *prime_nums = compute_first_n_primes(n);

    for (int i = 0; i < n; i++) {
        printf("%3d  %4d\n", i, prime_nums[i]);
    }
}

