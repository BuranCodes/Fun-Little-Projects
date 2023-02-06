// Packaging problem

#include <iostream>
#include <algorithm>
#include <vector>



int packagingTimeLILO(std::vector<int> items, int n) {
    if (items.empty()) return 0;
    else if (n > items.size()) return *std::max_element(items.begin(),items.end());
    int minutes {0};
    std::vector<int> packages(items.rbegin(), items.rbegin()+n); //! LILO
    for (int i = 0; i < n; i++){
        items.pop_back();
    }
    while(items.empty()!=true) {
        *std::min_element(packages.begin(),packages.end()) += items.back();
        items.pop_back();
    }
    minutes = *std::max_element(packages.begin(), packages.end());
    return minutes;

}

int packagingTimeFIFO(std::vector<int> items, int n) {
    if (items.empty()) return 0;
    else if (n > items.size()) return *std::max_element(items.begin(),items.end());
    int minutes {0};
    std::vector<int> packages(items.begin(), items.begin()+n); //! FIFO
    for (int i = 0; i < n; i++){
        items.erase(items.begin());
    }
    while(items.empty()!=true) {
        *std::min_element(packages.begin(),packages.end()) += items.front();
        items.erase(items.begin());
    }
    minutes = *std::max_element(packages.begin(), packages.end());
    return minutes;

}

int main() {
    std::vector<int> items {1,5,7,2,8,12,15,3,8,12}; 
    int n = 3;
    int input;
    std::cout << "All items:";
    for (int x : items) {
        std::cout << " " << x;
    }
    std::cout << "\nChoose the method to find out the total time to pack everything with each n-th boxes: FIFO (0) or LILO (1).\n";
    std::cin >> input;
    switch(input){
        case 0: std::cout << "Total packaging time: " <<  packagingTimeFIFO(items, n); break;
        case 1: std::cout << "Total packaging time: " << packagingTimeLILO(items, n); break;
        default: std::cout << "No appropriate input number found. Using the default: FIFO. Total packaging time: " << packagingTimeFIFO(items, n); break;
    }
}

