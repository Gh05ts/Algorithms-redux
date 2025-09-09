#include <iostream>
#include <vector>

/*
    X = A B       Y = E F
        C D           G H

    7 Products P1 = A(F-H)
               P2 = (A + B)H
               P3 = (C + D)E
               P4 = D(G - E)
               P5 = (A + D)(E + H)
               P6 = (B - D)(G + H)
               P7 = (A -C)(E + F)

    X.Y = AE + BG  AF + BH = P5 + P4 - P2 + P6   P1 + P2
          CE + DG  CF + DH   P3 + P4             P1 + P5 - P3 - P7
*/

int main() {
    return 0;
}