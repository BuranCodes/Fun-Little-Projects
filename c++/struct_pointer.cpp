// Example program of accessing struct members with smart pointers 
#include <iostream>
#include <memory>


struct Test {
    
    int health = 50;
    int atk = 25;
    int def = 25;
    int mana = 10;
    int funds = 12;
    int numberCombatDeaths = 0;
    bool killedInCombat = false;
};

auto changeStructVariables(std::shared_ptr<Test> testPTR) {
    testPTR->health=100;
    testPTR->atk++;
    testPTR->def--;
    testPTR->mana-=5;
    testPTR->funds+=6;
    testPTR->numberCombatDeaths=1;
    testPTR->killedInCombat=true;

}

auto printStructVariables(std::shared_ptr<Test> testPTR) {
    std::cout << testPTR->health << "\n";
    std::cout << testPTR->atk << "\n";
    std::cout << testPTR->def << "\n";
    std::cout << testPTR->mana << "\n";
    std::cout << testPTR->funds << "\n";
    std::cout << testPTR->numberCombatDeaths << "\n";
    std::cout << testPTR->killedInCombat << "\n";
}

int main() {
auto testPTR = std::make_shared<Test>();
changeStructVariables(testPTR);
printStructVariables(testPTR);


}
