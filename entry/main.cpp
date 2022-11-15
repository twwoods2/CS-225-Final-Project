#include "Airport.h"
#include <iostream>
int main() {
    std::cout << "main works" << std::endl;
    Airport test = Airport(5,3, "Ohare", "ORD");
    std::cout << test.get_id() << std::endl;
    return 0;
}