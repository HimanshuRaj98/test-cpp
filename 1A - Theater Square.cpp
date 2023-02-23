#include <iostream>

using namespace std;

int main()
{
    long long n, m, a, number;
    const int size = 1e6 + 2 ;
    cin >> n >> m >> a;
    number = ((n + a - 1)) / a * ((m + a - 1) / a);
    cout << number << " " <<size << endl;
    return 0;
}
