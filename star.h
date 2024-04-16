#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#ifndef PROJECT3_STAR_H
#define PROJECT3_STAR_H
class star{
    std::string id, hipID, hdID, hrID, glID, bfID, asc, dec, commonName,
    dist, ascMotion, decMotion, radVelocity, visMag, absVisMag, spect,
    colorIndex, xCord, yCord, zCord, xVelo, yVelo, zVelo, ascPos, decPos,
    ascPropMotion, decPropMotion, bayerDes, flamNum, constellAbv, compID,
    compPrimID, baseID, lum, var, varMin, varMax;

    std::vector<star> readStarFile();
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> starsList;

public:
    std::vector<star> stars;
    std::map<std::string, std::pair<std::string, std::string>> starsGraph;
    star(std::string id = "", std::string hipID = "", std::string  hdID = "", std::string hrID = "", std::string glID = "", std::string bfID = "", std::string asc = "", std::string dec = "",
         std::string commonName = "", std::string dist = "", std::string ascMotion = "", std::string decMotion = "", std::string radVelocity = "", std::string visMag = "", std::string absVisMag = "",
         std::string spect = "", std::string colorIndex = "", std::string xCord = "", std::string yCord = "", std::string zCord = "", std::string xVelo = "", std::string yVelo = "", std::string zVelo = "",
         std::string ascPos = "",std::string decPos = "", std::string ascPropMotion = "", std::string decPropMotion = "", std::string bayerDes = "", std::string flamNum = "", std::string constellAbv = "",
         std::string compID = "", std::string compPrimID = "", std::string baseID = "", std::string lum = "", std::string var = "", std::string varMin = "", std::string varMax = "");

    std::vector<star> getStarVector();

    std::vector<star> shellSort(const std::vector<star>& stars, std::string atribute);

    //Getter functions
    std::string getCommonName() const {
        return asc;  // WARNING commonName saves under asc
    }
    std::string getDist() const {
        return dist;
    }
    std::string getID() const {
        return id;
    }
};
#endif //PROJECT3_STAR_H
