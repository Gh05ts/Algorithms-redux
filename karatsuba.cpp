#include <cmath>
#include <iostream>

typedef unsigned long long ull;
using namespace std;

ull karatsuba(ull x, ull y) {
    if (x < 10 || y < 10) {
        return x * y;
    }
    
    int xLen = static_cast<int>(floor(log10(x))) + 1;
    int yLen = static_cast<int>(floor(log10(y))) + 1;
    int maxLen = max(xLen, yLen);
    int halfMaxLen = maxLen/2;

    // 1234 / 10^2 = 12 -> x1
    // 1234 % 10^2 = 34 -> x0
    ull x1 = x / (ull) pow(10, halfMaxLen);
    ull x0 = x % (ull) pow(10, halfMaxLen);
    ull y1 = y / (ull) pow(10, halfMaxLen);
    ull y0 = y % (ull) pow(10, halfMaxLen);

    // 1234 * 5678
    // (1200 + 34) * (5600 * 78)
    // 12*56 * 10^4 + (12*78 + 34*56) * 10^2 + 34*78
    // x1*y1 * 10^4 + (x1y0 + x0y1) * 10^2 + x0*y0
    // (x0 + x1) * (y0 + y1) = x0y0 + x0y1 + x1y0 + x1y1
    // (x0 + x1) * (y0 + y1) - x0y0 - x1y1 = x0y1 + x1y0
    ull upperBitsProduct = karatsuba(x1, y1);
    ull upperLowerBitsSumProduct = karatsuba(x0 + x1, y0 + y1);
    ull lowerBitsProduct = karatsuba(x0, y0);

    return (ull) pow(10, halfMaxLen * 2) * upperBitsProduct 
         + (ull) pow(10, halfMaxLen) * (upperLowerBitsSumProduct - upperBitsProduct - lowerBitsProduct) 
         + (ull) lowerBitsProduct;
}

int main() {
    ull a, b;
    cin >> a >> b;
    cout << karatsuba(a ,b) << endl;
    return 0;
}