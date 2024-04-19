#include <iostream>
#include <chrono>
#include <ctime>
#include "star.h"
#include <iomanip>
int main(){
    star s;
    std::vector<star> stars = s.getStarVector();
    std::cout << "Hello! Welcome to star sorting!" << std::endl;
    bool isDone = false;
    while (!isDone){
        std::cout << "" << std::endl;
        std::vector<star> shellSortedStars;
        std::vector<star> mergeSortedStars;
        shellSortedStars.resize(5000);
        mergeSortedStars.resize(5000);
        std::cout << "What attribute would you like the stars to be sorted by?" << std::endl;
        std::cout << "Attributes include distance, radial velocity, visual magnitude, color index, and star luminosity." << std::endl;
        std::cout << "Enter \"done\" if you would like to end the program" << std::endl;
        std::string attribute;
        std::getline(std::cin, attribute);
        std::cout << "" << std::endl;
        for(int i = 0; i < 5000; i++) {
            shellSortedStars[i] = stars[i];
            mergeSortedStars[i] = stars[i];
        }
        if(attribute == "Distance" || attribute == "distance"){
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "dist");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"dist");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest distance of " << shellSortedStars[i].getAttribute("dist") << std::endl;
                    break;
                }
            }
            for(int i = 4999; i >= 0; i--){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the highest distance of " << shellSortedStars[i].getAttribute("dist") << std::endl;
                    break;
                }
            }
            std::cout << "" << std::endl;
            std::cout << "Time to perform shell sort was " << std::fixed << std::setprecision(2) << timeToDoShellSecs << " seconds." << std::endl;
            std::cout << "Time to perform merge sort was " << std::fixed << std::setprecision(2) << timeToDoMergeSecs << " seconds." << std::endl;
        }
        else if(attribute == "Radial Velocity" || attribute == "radial velocity"){
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "radVelocity");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"radVelocity");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest radial velocity of " << shellSortedStars[i].getAttribute("radVelocity") << std::endl;
                    break;
                }
            }
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
        else if(attribute == "Visual Magnitude" || attribute == "visual magnitude"){
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "visMag");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"visMag");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest visual magnitude of " << shellSortedStars[i].getAttribute("visMag") << std::endl;
                    break;
                }
            }
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
        else if(attribute == "Color Index" || attribute == "color index"){
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "colorIndex");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"colorIndex");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the lowest color index of " << shellSortedStars[i].getAttribute("colorIndex") << std::endl;
                    break;
                }
            }
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
        else if(attribute == "Star Luminosity" || attribute == "star luminosity"){
            auto shellStartTime = std::chrono::steady_clock::now();;
            shellSortedStars = s.shellSort(shellSortedStars, "lum");
            auto shellEndTime = std::chrono::steady_clock::now();
            auto timeToDoShell = shellEndTime - shellStartTime;
            double timeToDoShellSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoShell).count();

            auto mergeStartTime = std::chrono::steady_clock::now();
            mergeSortedStars = s.mergeSort(mergeSortedStars,"lum");
            auto mergeEndTime = std::chrono::steady_clock::now();
            auto timeToDoMerge = mergeEndTime - mergeStartTime;
            double timeToDoMergeSecs = std::chrono::duration_cast<std::chrono::duration<double>>(timeToDoMerge).count();

            for(int i = 0; i < shellSortedStars.size(); i++){
                if(!shellSortedStars[i].getAttribute("commonName").empty()){
                    std::cout << "Star " << shellSortedStars[i].getAttribute("commonName") << " has the star luminosity of " << shellSortedStars[i].getAttribute("lum") << std::endl;
                    break;
                }
            }
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
        else if(attribute == "done" || attribute == "Done"){
            isDone = true;
            break;
        }
        else{
            std::cout << "Invalid attribute" << std::endl;
            continue;
        }


        // Clear space to prevent device from slowing down
        mergeSortedStars.clear();
        shellSortedStars.clear();
    }
    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}
