#include "fanze.h"

struct coord
{
    int x, y;
};

bool operator==(const coord &l, const coord &r)
{
    return l.x == r.x && l.y == r.y;
}

namespace std
{
    template <>
    struct hash<coord>
    {
        size_t operator()(const coord &c) const
        {
            return c.x + c.y;
        }
    };
}

int main()
{
    unordered_map<coord, int> m{
        {0, 1},
        1,
    };
    return 0;
}