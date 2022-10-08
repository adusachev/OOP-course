int gcd(unsigned a, unsigned b) {

    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a >= b) {
        return gcd(a % b, b);
    }
    if (b >= a) {
        return gcd(b % a, a);
    }
}