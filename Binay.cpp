#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Function to find all possible combinations of words formed by replacing
// given positive numbers with the corresponding character of the English alphabet

void recur(vector<int> const &digits, int i, string str)
{
    int n = digits.size();
 
    // base case: all digits are processed in the current configuration
    if (i == n)
    {
        // print the string
        cout << str << endl;
        return;
    }
 
    static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sum = 0;
 
    // process the next two digits (i'th and (i+1)'th)
    for (int j = i; j <= min(i + 1, n - 1); j++)
    {
        sum = (sum * 10) + digits[j];
 
        // if a valid character can be formed by taking one or both digits,
        // append it to the output and recur for the remaining digits
        if (sum <= 26) {
            recur(digits, j + 1, str + alphabet[sum - 1]);
        }
    }
}
 
void findCombinations(vector<int> const &digits)
{
    // base case
    if (digits.size() == 0) {
        return;
    }
 
    recur(digits, 0, "");
}
 
int main()
{
    vector<int> digits = { 1, 2, 2 };
 
    findCombinations(digits);
 
    return 0;
}
