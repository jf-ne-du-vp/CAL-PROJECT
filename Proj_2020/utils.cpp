#include "utils.h"


vector<Vertex *> appendPaths(vector<Vertex *> path1, vector<Vertex *> path2){
    vector<Vertex *> res;

    for(auto v : path1){
        res.push_back(v);
    }

    for(auto v : path2){
        res.push_back(v);
    }

    return res;
}

int menuOption(int minimum, int max){
    int numberInput;

    while (1) {
        std::cin >> numberInput;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(200, '\n');
            std::cout << "Please input a valid number: ";
            continue;
        }
        if (numberInput < minimum || numberInput > max) {
            std::cout << "Please input a single number between " << minimum << " and " << max << " (inclusive): ";
            std::cin.clear();
            std::cin.ignore(200, '\n');
            continue;
        }
        break;
    }
    return numberInput;
}