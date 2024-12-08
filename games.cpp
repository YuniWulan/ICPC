#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int team;
    cin >> team;

    int number(0);
    vector<int> h(team), a(team);
    for (int i = 0; i < team; ++i)
    {
        cin >> h[i] >> a[i];
        for (int j = 0; j < i; ++j)
        {
            if (h[i] == a[j])
            {
                number += 1;
            }
            if (a[i] == h[j])
            {
                number += 1;
            }
        }
    }
    cout << number << endl;
    return 0;
}
