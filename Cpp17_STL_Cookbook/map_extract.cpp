#include "fanze.h"

int main()
{
    map<int, string> a{
        {1, "a"},
        {2, "b"},
        {3, "c"},
    };

    auto a1(a.extract(1));
    auto a2(a.extract(2));

    swap(a1.key(), a2.key());

    a.insert(move(a1));
    a.insert(move(a2));

    return 0;
}