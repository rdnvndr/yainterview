#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// Заполняет номер элемента
void fillNumber(const std::vector<int>::iterator &current, int step = 5) {
    auto next = current + 1;
    auto prev = current - 1;

    auto prevValue = (prev != current) ? *prev : 0;
    auto nextValue = (next != current) ? *next : 0;

    *current = prevValue + ((nextValue != 0)
                            ? static_cast<int>((nextValue - prevValue) / 2 + 1)
                            : step);
    if (*current == nextValue)
        fillNumber(next, step);
}

int main()
{
    std::vector<int> opers = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    std::cout << "Исходные   данные: ";
    std::copy(opers.begin(), opers.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    fillNumber(opers.emplace(opers.begin()));
    fillNumber(opers.emplace(opers.begin()));
    fillNumber(opers.emplace(opers.begin()));
    fillNumber(opers.emplace(opers.begin()));
    fillNumber(opers.emplace(opers.end()));

    std::cout << "Измененные данные: ";
    std::copy(opers.begin(), opers.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
