#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "The factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}

/* ANOTHER METHOD

int factorial(int n){
    int result = 1;
    for(int i = 1; i<=n; i++){
        result = result * i;
    }
    return result;
}

*/
