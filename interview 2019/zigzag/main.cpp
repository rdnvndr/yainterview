/* Дано два массива:

v1 = [1, 2]
v2 = [3, 4, 5, 6]

Необходимо реализовать класс ZigzagIterator , в котором определены методы:
    bool hasNext() - указывает ли итератор на элемент или на std::end;
    int next()     - возвращает текущий элемент (если он существует).

Последовательный вызов next() выводит элементы массивов v1 и v2 в следующем
порядке:
    [1, 3, 2, 4, 5, 6]
*/

#include <algorithm>
#include <iterator>
#include <iostream>

class ZigzagIterator: public std::iterator<std::input_iterator_tag, int>
{
public:
    template <size_t N1, size_t N2>
    explicit ZigzagIterator(int (&v1)[N1], int (&v2)[N2]) {
        m_it1 = std::begin(v1);
        m_it2 = std::begin(v2);
        m_end1 = std::end(v1);
        m_end2 = std::end(v2);
        m_isOne = false;
    }

    bool hasNext() {
        return m_it1 != m_end1 || m_it2 != m_end2;
    }

    int nextOne(int **it1, int **end1, int **it2, int **end2){
        int result = -1;
        if (*it1 != *end1) {
            result = **it1;
            ++*it1;
        } else if (*it2 != *end2) {
            result = **it2;
            ++*it2;
        }
        return result;
    }

    int next() {
        return (m_isOne = !m_isOne)
                    ? nextOne(&m_it1, &m_end1, &m_it2, &m_end2)
                    : nextOne(&m_it2, &m_end2, &m_it1, &m_end1);
    }
private:
    int *m_it1;
    int *m_it2;
    int *m_end1;
    int *m_end2;
    bool m_isOne;
};

int main(int argc, char *argv[])
{
    int v1[2] = {1, 2};
    int v2[4] = {3, 4, 5, 6};
    ZigzagIterator zigzag(v1, v2);
    while (zigzag.hasNext()) {
        std::cout << zigzag.next() << " ";
    }
}
