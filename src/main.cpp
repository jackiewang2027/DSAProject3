/*#include <iostream>
#include <chrono>
#include <ctime>
#include "star.h"
#include "star.cpp"
#include <iomanip>

int main(){

    // Initialize star object and vector of star objects
    star s;
    std::vector<star> stars = s.getStarVector();

    // Print welcome message
    std::cout << "Hello! Welcome to star sorting!" << std::endl;

    // Conditional to keep program running until user stops
    bool isDone = false;

    // While loop until user wishes to stop program
    while (!isDone){
        std::cout << "" << std::endl;

        // Intialize vectors that will be sorted by merge and/or shell sort
        std::vector<star> shellSortedStars;
        std::vector<star> mergeSortedStars;

        // Resize them to be 5000-star objects
        shellSortedStars.resize(5000);
        mergeSortedStars.resize(5000);

        // Ask user what they want the vectors to be sorted by
        std::cout << "What attribute would you like the stars to be sorted by?" << std::endl;
        std::cout << "Attributes include distance, radial velocity, visual magnitude, color index, and star luminosity." << std::endl;

        // Get attribute from user
        std::cout << "Enter \"done\" if you would like to end the program" << std::endl;
        std::string attribute;
        std::getline(std::cin, attribute);
        std::cout << "" << std::endl;

        // Make the 2 new vectors equal to the first 5000-star objects from stars
        for(int i = 0; i < 5000; i++) {
            shellSortedStars[i] = stars[i];
            mergeSortedStars[i] = stars[i];
        }
        // Sort based on distance
        if(attribute == "Distance" || attribute == "distance"){
            // Perform and track time for shell sort
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "dist");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            // Perform and track time for merge sort
            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"dist");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            // Gets the star with the lowest distance and also has a common name
            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest distance of " << shellSortedStars[i].getAttribute("dist") << std::endl;
                    break;
                }
            }

            // Gets the star with the highest distance and also has a common name
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the highest distance of " << shellSortedStars[i].getAttribute("dist") << std::endl;
                    break;
                }
            }

            // Output time
            std::cout << "" << std::endl;
            std::cout << "Time to perform shell sort was " << std::fixed << std::setprecision(2) << timeToDoShellSecs << " seconds." << std::endl;
            std::cout << "Time to perform merge sort was " << std::fixed << std::setprecision(2) << timeToDoMergeSecs << " seconds." << std::endl;
        }

            // Sort based on radial velocity
        else if(attribute == "Radial Velocity" || attribute == "radial velocity"){

            // Perform and track time for shell sort
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "radVelocity");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            // Perform and track time for merge sort
            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"radVelocity");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            // Gets the star with the lowest radial velocity and also has a common name
            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest radial velocity of " << shellSortedStars[i].getAttribute("radVelocity") << std::endl;
                    break;
                }
            }

            // Gets the star with the radial velocity and also has a common name
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the highest radial velocity of " << shellSortedStars[i].getAttribute("radVelocity") << std::endl;
                    break;
                }
            }
            std::cout << "" << std::endl;
            std::cout << "Time to perform shell sort was " << std::fixed << std::setprecision(2) << timeToDoShellSecs << " seconds." << std::endl;
            std::cout << "Time to perform merge sort was " << std::fixed << std::setprecision(2) << timeToDoMergeSecs << " seconds." << std::endl;
        }

            // Sort based on visual magnitude
        else if(attribute == "Visual Magnitude" || attribute == "visual magnitude"){

            // Perform and track time for shell sort
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "visMag");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            // Perform and track time for merge sort
            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"visMag");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            // Gets the star with the lowest visual magnitude and also has a common name
            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest visual magnitude of " << shellSortedStars[i].getAttribute("visMag") << std::endl;
                    break;
                }
            }

            // Gets the star with the highest visual magnitude and also has a common name
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the highest visual magnitude of " << shellSortedStars[i].getAttribute("visMag") << std::endl;
                    break;
                }
            }
            std::cout << "" << std::endl;
            std::cout << "Time to perform shell sort was " << std::fixed << std::setprecision(2) << timeToDoShellSecs << " seconds." << std::endl;
            std::cout << "Time to perform merge sort was " << std::fixed << std::setprecision(2) << timeToDoMergeSecs << " seconds." << std::endl;
        }

            // Sort based on color index
        else if(attribute == "Color Index" || attribute == "color index"){

            // Perform and track time for shell sort
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "colorIndex");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            // Perform and track time for merge sort
            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"colorIndex");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            // Gets the star with the lowest color index and also has a common name
            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest color index of " << shellSortedStars[i].getAttribute("colorIndex") << std::endl;
                    break;
                }
            }

            // Gets the star with the highest color index and also has a common name
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the highest color index of " << shellSortedStars[i].getAttribute("colorIndex") << std::endl;
                    break;
                }
            }
            std::cout << "" << std::endl;
            std::cout << "Time to perform shell sort was " << std::fixed << std::setprecision(2) << timeToDoShellSecs << " seconds." << std::endl;
            std::cout << "Time to perform merge sort was " << std::fixed << std::setprecision(2) << timeToDoMergeSecs << " seconds." << std::endl;
        }

            // Sort based on star luminosity
        else if(attribute == "Star Luminosity" || attribute == "star luminosity"){

            // Perform and track time for shell sort
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "lum");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            // Perform and track time for merge sort
            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"lum");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            // Gets the star with the lowest star luminosity and also has a common name
            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the star luminosity of " << shellSortedStars[i].getAttribute("lum") << std::endl;
                    break;
                }
            }
            // Gets the star with the highest star luminosity and also has a common name
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the highest star luminosity of " << shellSortedStars[i].getAttribute("lum") << std::endl;
                    break;
                }
            }
            std::cout << "" << std::endl;
            std::cout << "Time to perform shell sort was " << std::fixed << std::setprecision(2) << timeToDoShellSecs << " seconds." << std::endl;
            std::cout << "Time to perform merge sort was " << std::fixed << std::setprecision(2) << timeToDoMergeSecs << " seconds." << std::endl;
        }

            // End program
        else if(attribute == "done" || attribute == "Done"){
            isDone = true;
            break;
        }

            // Make user type a valid input
        else{
            std::cout << "Invalid attribute" << std::endl;
            continue;
        }


        // Clear space to prevent device from slowing down
        mergeSortedStars.clear();
        shellSortedStars.clear();
    }

    // End message
    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}*/