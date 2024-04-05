#include <iostream>
#include "star.h"
int main(){
    star s;
    std::vector<star> stars = s.getStarVector();
    std::cout << stars.size();
    return 0;
}
