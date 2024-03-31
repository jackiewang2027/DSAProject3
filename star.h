#include <iostream>
#include <string>
#include <map>
#include <vector>
#ifndef PROJECT3_STAR_H
#define PROJECT3_STAR_H
class star{
    std::string id, hipID, hdID, hrID, glID, bfID, commonName;
    double dist, ascMotion, decMotion, radVelocity, visMag, absVisMag;
    std::string spect;
    double colorIndex, xCord, yCord, zCord, xVelo, yVelo, zVelo, ascPos, decPos, ascPropMotion, decPropMotion;
    std::string bayerDes;
    double flamNum;
    std::string constellAbv, compID, compPrimID, baseID;
    double lum;
    std::string var, varMin, varMax;

public:
    std::vector<star> stars;
    std::map<std::string, std::pair<std::string, double>> starsGraph;
    star(std::string id = "", std::string hipID = "", std::string  hdID = "", std::string hrID = "", std::string glID = "", std::string bfID = "", std::string commonName = "",
         double dist = 0, double ascMotion = 0.0, double decMotion = 0.0, double radVelocity = 0.0, double visMag = 0.0, double absVisMag = 0.0, std::string spect = "",
         double colorIndex = 0.0, double xCord = 0.0, double yCord = 0.0, double zCord = 0.0, double xVelo = 0.0, double yVelo = 0.0, double zVelo = 0.0, double ascPos = 0.0,
         double decPos = 0.0, double ascPropMotion = 0.0, double decPropMotion = 0.0, std::string bayerDes = "", double flamNum = 0.0, std::string constellAbv = "",
         std::string compID = "", std::string compPrimID = "", std::string baseID = "", double lum = 0.0, std::string var = "", std::string varMin = "", std::string varMax = "");

    std::vector<star> makeStarVector(int numStars);
};
#endif //PROJECT3_STAR_H
