const lli MLOG = 20;
const lli MAXN = (1 << MLOG);

void forward1(lli dp[]) { // adding element to all its super set
  fr(bit, MLOG) fr(i, MAXN) if (i & (1 << bit)) {
    dp[i] += dp[i ^ (1 << bit)];
  }
}

void backward1(lli dp[]) { //add a[i] to all j & i = i
  fr(bit, MLOG) per(i, MAXN - 1, 0) if (i & (1 << bit)) {
    dp[i] -= dp[i ^ (1 << bit)];
  }
}

void forward2(lli dp[]) { // add elements to its subsets
  fr(bit, MLOG) per(i, MAXN - 1, 0) if (i & (1 << bit)) {
    dp[i ^ (1 << bit)] += dp[i];
  }
}

void backward2(lli dp[]) {
  fr(bit, MLOG) fr(i, MAXN) if (i & (1 << bit)) {
    dp[i ^ (1 << bit)] -= dp[i];
  }
}
