/* Дан вектор, надо удалить из него нули, сохранив порядок остальных элементов.
*/

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 0, 2};
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    auto end = std::remove(v.begin(), v.end(), 0);
    std::copy(v.begin(), end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
