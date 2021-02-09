#include "fanze.h"

template <typename T>
class addable
{
    T val;

public:
    addable(T v) : val(v) {}

    template <typename U>
    T add(U x) const
    {
        if constexpr (std::is_same_v<T, std::vector<U>>)
        {
            auto copy(val);
            for (auto &n : copy)
            {
                n += x;
            }
            return copy;
        }
        return val + x;
    }
};

int main()
{
    auto res1 = addable<int>(1).add(2);

    vector<int> v = {1, 2, 3};
    auto res = addable<vector<int>>{v}.add(2);

    return 0;
}