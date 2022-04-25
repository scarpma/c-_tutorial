#include <string.h>
#include <iostream>
using namespace std;

// declare header in order to let main know
// what functions will come next
int *compute_first_n_primes(int n);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "wrong number of arguments !\n";
        return 1;
    }
    // convert array of char to int
    int n = atoi(argv[1]);
    assert(n > 0);
    int *prime_nums = compute_first_n_primes(n);

    for (int i = 0; i < n; i++) {
        printf("%3d  %4d\n", i, prime_nums[i]);
    }

    delete[] prime_nums;
}

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


