#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
bool isPrime(long long n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

long long pollardRho(long long N)
{
    long long x = rand() % (N - 2) + 2;
    long long y = x;
    long long c = rand() % (N - 1) + 1;
    long long d = 1;

    while (d == 1)
    {
        x = (x * x + c) % N;
        y = (y * y + c) % N;
        y = (y * y + c) % N;
        d = gcd(abs(x - y), N);
    }

    return d;
}


void factorize(long long N, unordered_map<long long, int> &factors)
{
    if (N == 1)
        return;

    if (N % 2 == 0)
    {
        factors[2]++;
        factorize(N / 2, factors);
        return;
    }

    if (isPrime(N))
    {
        factors[N]++;
        return;
    }

    long long factor = pollardRho(N);
    factorize(factor, factors);
    factorize(N / factor, factors);
}

int main()
{
    long long N;
    // cout << "Enter a number: ";
    cin >> N;

    unordered_map<long long, int> factors;
    factorize(N, factors);

    cout << "Prime factors of " << N << " are: ";
    for (auto factor : factors)
    {
        for (int i = 0; i < factor.second; i++)
        {
            cout << factor.first << " ";
        }
    }
    cout << endl;

    return 0;
}
