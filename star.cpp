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


/*std::fstream fin;
    fin.open("Star Data.csv", std::ios::in);

    std::vector<std::string> row;
    std::string temp;
    int iter = 0;
    while (fin >> temp) {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        //getline(fin, line);

        // used for breaking words
        std::stringstream lineStream(temp);
        std::string attribute;
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(lineStream, attribute, ',')) {
                // add all the column data
                // of a row to a vector
                row.push_back(attribute);
            }

        if(!row.empty()){
            if(row.size() != 37){
                row.push_back("");
            }
            this->stars.push_back(star(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12], row[13], row[14], row[15], row[16], row[17], row[18], row[19], row[20], row[21], row[22], row[23], row[24], row[25], row[26], row[27], row[28], row[29], row[30], row[31], row[32], row[33], row[34], row[35], row[36]));
        }
        iter++;
    }
    this->stars.erase(this->stars.begin());
    return this->stars;*/
std::vector<star> star::readStarFile() {
    std::fstream fin;
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

std::vector<star> star::getStarVector() {
    return readStarFile();
}


