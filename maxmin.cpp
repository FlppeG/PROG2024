#include <iostream>
#include <limits>

int main () {
// smallest negative value:
std::cout << "lowest:  " <<
std::numeric_limits<long long>::lowest() << '\n'
;
// float/double: smallest value > 0
// integers: smallest value
std::cout << "min:     " <<
std::numeric_limits<long long>::min() << '\n'
;
// largest positive value:
std::cout << "max:     " <<
std::numeric_limits<long long>::max() << '\n'
;
// smallest difference btw. 1 and next value:
std::cout << "epsilon: " <<
std::numeric_limits<long long>::epsilon() << '\n';

}