//
// Created by Burge on 2026/08/13.
//

#ifndef KEIBE_CUBE_H
#define KEIBE_CUBE_H


#pragma once

#include <array>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>

class Cube {

public:
    Cube();


    explicit Cube(std::array<char, 54> state);

    const std::array<char, 54> &getStickers() const;

    void doMoveSequence(const std::string &move);

    std::vector<std::string> cross();

    void doMoveSequence(const std::vector<std::string> &moves);

    std::vector<std::string> firstPair();

private:

    void print() const;

    int evaluateSolution(const std::vector<std::string>& solution);

    int heuristic();

    std::array<char, 54> stickers;
    std::map<char,int> startPos = {{'U',0},{'L',9},{'F',18},{'R',27},{'B',36},{'D',45}};
    std::unordered_set<char> validChar{'R','L','F','B','D','U','E','S','M','x','y','z'};

    std::array<std::string,12> testMoves = {"U","U'","F","F'","R","R'","L","L'"};

    std::map<std::string,std::array<int,3>> corners = {{"UBL",{0,38,9}},
                                                       {"UBR",{2,36,29}},
                                                       {"UFR",{8,20,27}},
                                                       {"UFL",{6,18,11}},
                                                       {"DFL",{45,24,17}},
                                                       {"DFR",{47,26,33}},
                                                       {"DBR",{53,42,35}},
                                                       {"DBL",{51,44,15}}};
    std::map<std::string,std::array<int,2>> edges = {{"UF",{7,19}},
                                                     {"UB",{1,37}},
                                                     {"UR",{5,28}},
                                                     {"UL",{3,10}},
                                                     {"FR",{23,30}},
                                                     {"FL",{21,14}},
                                                     {"DR",{50,34}},
                                                     {"DB",{52,43}},
                                                     {"DL",{48,16}},
                                                     {"DF",{46,25}},
                                                     {"BR",{39,32}},
                                                     {"BL",{41,12}}};
    std::map<std::string,std::array<int,2>> f2lEdges = {{"UF",{7,19}},
                                                     {"UB",{1,37}},
                                                     {"UR",{5,28}},
                                                     {"UL",{3,10}},
                                                     {"FR",{23,30}},
                                                     {"FL",{21,14}},
                                                     {"BR",{39,32}},
                                                     {"BL",{41,12}}};

    std::array<std::string,4> f2l = {"WGR","WGO","WOB","WBR"};

    [[nodiscard]] bool isSolved() const;

    std::string findEdge(const std::string &cornerColours) const;

    void turnFaceAntiClockwise(char layer);

    void doMovePrime(const char &move);

    void doMoveDouble(const char &move);

    void doMove(const char &move);
    void turnFaceClockwise(char layer);
    void rotateFaceStickersClockwise(char layer);
    void rotateFaceStickersAntiClockwise(char layer);
    void doRotation(const std::string &move);

    bool sameEdge(std::string edge1, std::string edge2) const;

    bool isWhiteCrossSolved();

    bool isPaired(const std::string &cornerColours);

    bool isEdgeSolved(const std::string& edge);


    bool goal(const std::string& pair);

    std::string toString();

    int countUnsolvedCrossEdges();

    int pairHeuristic(const std:: string& pair);

    bool isJoint(const std::string &cornerColours);

    bool isSplitPaired(const std::string &pair);

    static std::vector<std::vector<std::string>> generateFastTriggers();

};


#endif //KEIBE_CUBE_H
