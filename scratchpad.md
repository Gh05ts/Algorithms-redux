Q1 Claim 2^n+10 = O(2^n)
Proof: find c, n0 s.t. 2^(n+10) <= c.2^n for every n >= n0
2^10.2^n = 1024.2^n
so, c = 1024, n >= 1 holds

Q2 2^10n is not O(2^n)
Proof: by contradiction If 2^10n = O(2^n), then there existws constants c, n0 > 0 s.t. 2^10n <= c.2^n for every n >= n0
2 ^ 9n <= c for ever n >= 1