vector<int> suffix(n);

suffix[n - 1] = arr[n - 1];

for (int i = n - 2; i >= 0; i--)
{
    suffix[i] = suffix[i + 1] + arr[i];
}