#include <iostream>
#include "star.h"
int main(){
    star s;
    std::vector<star> stars = s.getStarVector();
    std::cout << "Number of stars: " << stars.size() << std::endl;

    // Test getter functions
    for(int i = 0; i < stars.size(); i++){
        if(!stars[i].getCommonName().empty()){
            std::cout << stars[i].getID()<< " " << stars[i].getCommonName() << " is "<< stars[i].getDist() << " parsecs from earth!" << std::endl;
        }

    }




    return 0;
}
