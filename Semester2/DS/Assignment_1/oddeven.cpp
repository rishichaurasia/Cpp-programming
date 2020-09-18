#include <iostream>
using namespace std;
void odd_even(int a[], int len, int i = 0, int odd = 0)
{
    if (i == len)
    {
        return;
    }
    if (a[i] % 2 == 1)
    {
        int temp = a[odd];
        a[odd] = a[i];
        a[i] = temp;
        odd++;
    }
    odd_even(a, len, i + 1, odd);
}
int main()
{
    int len;
    cout << "Enter the size of array: ";
    cin >> len;
    int a[len];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    odd_even(a, len);
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}