/**
Online Judge : HackerRank
Problem No   : 
Problem Name : The Coin Change Problem
Author       : Zubayer Rahman
Email        : zubayer.csesust@gmail.com
CPU          : 
Memory       : 
Algorithm    : Coin Change
*/

#include<bits/stdc++.h>

#define MAX_COIN 50
#define MAX_CHANGE 250

using namespace std;

int n,m;

int coin[MAX_COIN+1];
long long ara[MAX_COIN+1][MAX_CHANGE+1];

void reset()
{
    int i,j;

    for(i=0; i<=m; i++)
        for(j=0; j<=n; j++)
            ara[i][j] = -1;
}

long long coin_change(int i, int val)
{
    if(i>m)
    {
        if(val==n)
            return 1;
        return 0;
    }

    if(ara[i][val] != -1)
        return ara[i][val];

    long long result1=0,result2=0;

    if(val+coin[i] <= n)
        result1 = coin_change(i, val+coin[i]);

    result2 = coin_change(i+1, val);

    return ara[i][val] = result1 + result2;
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        int i;

        for(i=1; i<=m; i++)
            scanf("%d", &coin[i]);

        reset();

        long long result = coin_change(1, 0);

        printf("%lld\n", result);
    }
    return 0;
}
