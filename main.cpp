#include <iostream>
#include "star.h"
int main(){
    star s;
    std::vector<star> stars = s.getStarVector();
    std::cout << "Number of stars: " << stars.size() << std::endl;

    // Test Shell sort (Prints named stars in order by distance)
    std::vector<star> sortedStars = s.shellSort(stars,"temp");
    for(int i = 0; i < sortedStars.size(); i++){
        if(!sortedStars[i].getCommonName().empty()){
            std::cout << sortedStars[i].getCommonName() << " is "<< sortedStars[i].getDist() << " parsecs from earth!" << std::endl;
        }
    }
    return 0;
}
