// Packaging problem

#include <iostream>
#include <algorithm>
#include <vector>



int packagingTimeLILO(std::vector<int> packages, const int n) {
    if (packages.empty()) return 0;
    else if (n > packages.size()) return *std::max_element(packages.begin(),packages.end());
    int minutes {0};
    std::vector<int> boxes(packages.rbegin(), packages.rbegin()+n); //! LILO
    for (int i = 0; i < n; i++){
        packages.pop_back();
    }
    while(packages.empty()!=true) {
        *std::min_element(boxes.begin(),boxes.end()) += packages.back();
        packages.pop_back();
    }
    minutes = *std::max_element(boxes.begin(), boxes.end());
    return minutes;

}

int packagingTimeFIFO(std::vector<int> packages, int n) {
    if (packages.empty()) return 0;
    else if (n > packages.size()) return *std::max_element(packages.begin(),packages.end());
    int minutes {0};
    std::vector<int> boxes(packages.begin(), packages.begin()+n); //! FIFO
    for (int i = 0; i < n; i++){
        packages.erase(packages.begin());
    }
    while(packages.empty()!=true) {
        *std::min_element(boxes.begin(),boxes.end()) += packages.front();
        packages.erase(packages.begin());
    }
    minutes = *std::max_element(boxes.begin(), boxes.end());
    return minutes;

}

int main() {
    std::vector<int> packages {1,5,7,2,8,12,15,3,8,12}; 
    const int n = 3;
    int input;
    std::cout << "All packages:";
    for (int x : packages) {
        std::cout << " " << x;
    }
    std::cout << "\nChoose the method to find out the total time to pack everything with each n-th boxes: FIFO (0) or LILO (1).\n";
    std::cin >> input;
    switch(input){
        case 0: std::cout << "Total packaging time: " <<  packagingTimeFIFO(packages, n); break;
        case 1: std::cout << "Total packaging time: " << packagingTimeLILO(packages, n); break;
        default: std::cout << "No appropriate input number found. Using the default: FIFO. Total packaging time: " << packagingTimeFIFO(packages, n); break;
    }
}

/*
    This program determines, based on given the queue order, how much time it takes to finish putting packages in nth boxes.
*/
