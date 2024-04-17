#include <iostream>
#include "star.h"
int main(){
    star s;
    std::vector<star> stars = s.getStarVector();
    std::cout << "Number of stars: " << stars.size() << std::endl;

    // Test Shell sort (Prints named stars in order by attribute)
    // Possible: dist, radVelocity, visMag, colorIndex, lum
    std::string attribute = "lum";
    std::vector<star> sortedStars = s.shellSort(stars,attribute);
    for(int i = 0; i < sortedStars.size(); i++){
        if(!sortedStars[i].getAttribute("commonName").empty()){
            std::cout << sortedStars[i].getAttribute("commonName") << " has "<< attribute << " " << sortedStars[i].getAttribute(attribute) << std::endl;
        }
    }
    return 0;
}
