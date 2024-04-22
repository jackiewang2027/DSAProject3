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

public:
    std::vector<star> readStarFile() {
        std::fstream fin;
        //https://www.geeksforgeeks.org/file-handling-c-classes/ citation for file handling and opening .csv file
        fin.open("Star Data.csv", std::ios::in);

        if (!fin.is_open()) {
            // Handle file opening failure
            return stars; // Return empty vector
        }

        std::string line;
        int iter = 0;
        while (std::getline(fin, line)) {
            std::vector<std::string> row;
            std::stringstream lineStream(line);
            std::string attribute;

            while (std::getline(lineStream, attribute, ',')) {
                // Remove leading and trailing spaces from each field
                size_t start = attribute.find_first_not_of(" \t");
                size_t end = attribute.find_last_not_of(" \t");

                if (start != std::string::npos && end != std::string::npos)
                    row.push_back(attribute.substr(start, end - start + 1));
                else
                    row.push_back("");
            }

            if (!row.empty()) {
                if (row.size() != 37) {
                    row.push_back(""); // Ensure all rows have 37 columns
                }
                stars.emplace_back(star(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14], row[15], row[16], row[17], row[18], row[19], row[20], row[21], row[22], row[23], row[24], row[25], row[26], row[27], row[28], row[29], row[30], row[31], row[32], row[33], row[34], row[35], row[36]));
            }
            iter++;
        }
        fin.close();
        if (!stars.empty()) {
            stars.erase(stars.begin()); // Remove the header row
        }
        return stars;
    }

    // Vector of star objects
    std::vector<star> stars;

    /*** Constructor for star objects*/
    star(std::string id = "", std::string hipID = "", std::string  hdID = "", std::string hrID = "", std::string glID = "", std::string bfID = "", std::string asc = "", std::string dec = "",
         std::string commonName = "", std::string dist = "", std::string ascMotion = "", std::string decMotion = "", std::string radVelocity = "", std::string visMag = "", std::string absVisMag = "",
         std::string spect = "", std::string colorIndex = "", std::string xCord = "", std::string yCord = "", std::string zCord = "", std::string xVelo = "", std::string yVelo = "", std::string zVelo = "",
         std::string ascPos = "",std::string decPos = "", std::string ascPropMotion = "", std::string decPropMotion = "", std::string bayerDes = "", std::string flamNum = "", std::string constellAbv = "",
         std::string compID = "", std::string compPrimID = "", std::string baseID = "", std::string lum = "", std::string var = "", std::string varMin = "", std::string varMax = "");

    /*** Getter for the vector of star objects*/
    std::vector<star> getStarVector() {
        return readStarFile();
    }
    //citation: Module 6 - Sorting (Slide 38,74)
    std::vector<star> shellSort(const std::vector<star>& stars, std::string attribute) {
        std::vector<star> sortedStars = stars;
        int gap = sortedStars.size() / 2;
        while (gap > 0) {
            for (int i = gap; i < sortedStars.size(); i++) {
                star tempStar = sortedStars[i];
                int j = i;
                while (j >= gap && std::stod(sortedStars[j - gap].getAttribute(attribute)) > std::stod(tempStar.getAttribute(attribute))) {
                    sortedStars[j] = sortedStars[j - gap];
                    j -= gap;
                }
                sortedStars[j] = tempStar;
            }
            if(gap == 2){
                gap = 1;
            }else{
                gap = gap / 2;
            }
        }
        return sortedStars;
    }
// Code retrieved/inspired by Module 6 Sorting Slides
    std::vector<star> mergeSort(std::vector<star>& stars, std::string attribute) {
        // Initialize the left and right positions
        int left = 0;
        int right = stars.size() - 1;

        // Make a temporary vector with the same size as stars to help prevent
        // creation of redundant new vectors that would otherwise recursively be called
        // Reduces memory usage
        std::vector<star> temp(stars.size());

        // Call helper function
        mergeSortHelper(stars, temp, attribute, left, right);

        // Return stars and its changes
        return stars;
    }
    //        const std::string attributes[5] = {"Distance", "Radial Velocity", "Luminosity", "Color Index", "Visual Magnitude"};
    /*** Getter function for attributes */
    std::string getAttribute(std::string attribute) const {
        if(attribute == "commonName")
            return asc;  // WARNING commonName saves under asc
        if(attribute == "id")
            return id;
        if(attribute == "Distance")
            return dist;
        if(attribute == "Radial Velocity")
            return radVelocity;
        if(attribute == "Visual Magnitude")
            return visMag;
        if(attribute == "Color Index"){
            if(!colorIndex.empty()){
                return colorIndex;
            }else{
                return "0";
            }
        }
        if(attribute == "Luminosity")
            return lum;

        return "0";
    }

    std::vector<star> mergeSortHelper(std::vector<star>& stars, std::vector<star>& temp, std::string attribute, int left, int right) {
        // Checks if the right parameter is greater than left
        if (left < right) {
            // Calculate the middle of those two
            int mid = left + (right - left) / 2;
            // Call margeSortHelper until the vector can't be reduced anymore
            mergeSortHelper(stars, temp, attribute, left, mid);
            mergeSortHelper(stars, temp, attribute, mid + 1, right);
            // Call merge
            merge(stars, temp, left, mid, right, attribute);
        }
        // Return stars and its changes
        return stars;
    }
    void merge(std::vector<star>& stars, std::vector<star>& temp, int left, int mid, int right, std::string attribute) {
        // Declare index for the left subarray
        int i = left;
        // Declare index for the right subarray
        int j = mid + 1;
        // Declare starting index for the merged subarray
        int k = left;


        while (i <= mid && j <= right) {
            // Comparing and merging based on the attribute
            if (std::stod(stars[i].getAttribute(attribute)) <= std::stod(stars[j].getAttribute(attribute))){
                temp[k++] = stars[i++];
            } else {
                temp[k++] = stars[j++];
            }
        }

        // Copy the remaining elements of the left subarray, if any
        while (i <= mid) {
            temp[k++] = stars[i++];
        }

        // Copy the remaining elements of the right subarray, if any
        while (j <= right) {
            temp[k++] = stars[j++];
        }

        // Copy the merged elements back to the original array
        for (i = left; i <= right; ++i) {
            stars[i] = temp[i];
        }
    }
};
#endif //PROJECT3_STAR_H