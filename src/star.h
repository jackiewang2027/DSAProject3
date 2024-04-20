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
    // Declare private star attributes
    std::string id, hipID, hdID, hrID, glID, bfID, asc, dec, commonName,
            dist, ascMotion, decMotion, radVelocity, visMag, absVisMag, spect,
            colorIndex, xCord, yCord, zCord, xVelo, yVelo, zVelo, ascPos, decPos,
            ascPropMotion, decPropMotion, bayerDes, flamNum, constellAbv, compID,
            compPrimID, baseID, lum, var, varMin, varMax;

    /*** Function that reads Star Data.csv file and makes a bunch of star objects and returns a vector of them*/
    std::vector<star> readStarFile();

    /*** Function that helps merge sort */
    std::vector<star> mergeSortHelper(std::vector<star>& stars, std::vector<star>& temp, std::string attribute, int left, int right);

    /*** Function that merges two sub vectors and sorts them*/
    void merge(std::vector<star>& stars, std::vector<star>& temp, int left, int mid, int right, std::string attribute);
public:

    // Vector of star objects
    std::vector<star> stars;

    /*** Constructor for star objects*/
    star(std::string id = "", std::string hipID = "", std::string  hdID = "", std::string hrID = "", std::string glID = "", std::string bfID = "", std::string asc = "", std::string dec = "",
         std::string commonName = "", std::string dist = "", std::string ascMotion = "", std::string decMotion = "", std::string radVelocity = "", std::string visMag = "", std::string absVisMag = "",
         std::string spect = "", std::string colorIndex = "", std::string xCord = "", std::string yCord = "", std::string zCord = "", std::string xVelo = "", std::string yVelo = "", std::string zVelo = "",
         std::string ascPos = "",std::string decPos = "", std::string ascPropMotion = "", std::string decPropMotion = "", std::string bayerDes = "", std::string flamNum = "", std::string constellAbv = "",
         std::string compID = "", std::string compPrimID = "", std::string baseID = "", std::string lum = "", std::string var = "", std::string varMin = "", std::string varMax = "");

    /*** Getter for the vector of star objects*/
    std::vector<star> getStarVector();

    /*** Performs shell sort on a given vector based on an atttribute*/
    std::vector<star> shellSort(const std::vector<star>& stars, std::string atribute);

    /*** Performs merge sort on a given vector based on an atttribute*/
    std::vector<star> mergeSort(std::vector<star>& stars, std::string attribute);

    /*** Getter function for attributes */
    std::string getAttribute(std::string attribute){
        if(attribute == "commonName")
            return asc;  // WARNING commonName saves under asc
        if(attribute == "id")
            return id;
        if(attribute == "dist")
            return dist;
        if(attribute == "radVelocity")
            return radVelocity;
        if(attribute == "visMag")
            return visMag;
        if(attribute == "colorIndex"){
            if(!colorIndex.empty()){
                return colorIndex;
            }else{
                return "0";
            }
        }
        if(attribute == "lum")
            return lum;

        return "0";
    }

};
#endif //PROJECT3_STAR_H