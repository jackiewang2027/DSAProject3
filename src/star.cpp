#include "star.h"
star::star(std::string id , std::string hipID , std::string  hdID , std::string hrID , std::string glID , std::string bfID , std::string asc , std::string dec ,
           std::string commonName , std::string dist , std::string ascMotion , std::string decMotion , std::string radVelocity , std::string visMag , std::string absVisMag ,
           std::string spect , std::string colorIndex , std::string xCord , std::string yCord , std::string zCord , std::string xVelo , std::string yVelo , std::string zVelo ,
           std::string ascPos ,std::string decPos , std::string ascPropMotion , std::string decPropMotion , std::string bayerDes , std::string flamNum , std::string constellAbv ,
           std::string compID , std::string compPrimID , std::string baseID , std::string lum , std::string var , std::string varMin , std::string varMax ) {
    this->id = id;
    this->hipID = hipID;
    this->hdID = hdID;
    this->hrID = hrID;
    this-> glID = glID;
    this->bfID = bfID;
    this->commonName = commonName;
    this->asc = asc;
    this->dec = dec;
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






