#include "star.h"
star::star(std::string id, std::string hipID, std::string hdID, std::string hrID, std::string glID, std::string bfID,
           std::string commonName, double dist, double ascMotion, double decMotion, double radVelocity, double visMag,
           double absVisMag, std::string spect, double colorIndex, double xCord, double yCord, double zCord,
           double xVelo, double yVelo, double zVelo, double ascPos, double decPos, double ascPropMotion,
           double decPropMotion, std::string bayerDes, double flamNum, std::string constellAbv, std::string compID,
           std::string compPrimID, std::string baseID, double lum, std::string var, std::string varMin,
           std::string varMax) {
    this->id = id;
    this->hipID = hipID;
    this->hdID = hdID;
    this->hrID = hrID;
    this-> glID = glID;
    this->bfID = bfID;
    this->commonName = commonName;
    this->dist = dist;
    this->ascMotion = ascMotion;
    this->decMotion = decMotion;
    this->radVelocity = radVelocity;
    this->visMag = visMag;
    this->absVisMag = absVisMag;
    this->spect = spect;
    this->colorIndex = colorIndex;
    this->xCord = xCord;
    this->yCord = yCord;
    this->zCord = zCord;
    this->xVelo = xVelo;
    this->yVelo = yVelo;
    this->zVelo = zVelo;
    this->ascPos = ascPos;
    this->decPos = decPos;
    this->ascPropMotion = ascPropMotion;
    this->decPropMotion  = decPropMotion;
    this->bayerDes = bayerDes;
    this->flamNum = flamNum;
    this->constellAbv = constellAbv;
    this->compID = compID;
    this->compPrimID = compPrimID;
    this->baseID = baseID;
    this->lum = lum;
    this->var = var;
    this->varMin = varMin;
    this->varMax = varMax;
}

std::vector<star> star::makeStarVector(int numStars){
    for(int i = 0; i < numStars; i++){
        this->stars = this->stars.push_back(star());
    }
    return this->stars
}
