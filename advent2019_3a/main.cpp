#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

int ManhattanDistanceFromOrigo(int x, int y)
{
    return std::abs(x) + std::abs(y);
}

std::vector<std::string> splitString(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

static void expandPath(std::string path, std::vector<std::pair<int , int>> &steps)
{
    // Start at origo
    int x = 0, y = 0;
    
    std::vector<std::string> tokens = splitString(path, ',');

    for (const auto &token: tokens)
    {
        char direction = token.at(0);
        int increments = std::stoi(token.substr(1));
        switch (direction)
        {
            case 'R':
                while (increments--)
                {
                    steps.push_back({++x, y});
                }
                break;
            case 'L':
                while (increments--)
                {
                    steps.push_back({--x, y});
                }
                break;
            case 'U':
                while (increments--)
                {
                    steps.push_back({x, ++y});
                }
                break;
            case 'D':
                while (increments--)
                {
                    steps.push_back({x, --y});
                }
                break;
        } 
    }
}

bool testManhattanDistance(int expected, int x, int y)
{
    int answer = ManhattanDistanceFromOrigo(x, y);
    if (expected == answer)
    {
        std::cout << "Manhattan Distance test:" << " PASSED" << ", got: " << answer << "\n";
        return true;
    }
    else
    {
        std::cout << "Manhattan Distance test:" << " FAILED" << ", got: " << answer << ", expected: " << expected << "\n";
        return false;
    }
}

static int getNearestIntersection(std::pair<std::string, std::string> stringPair)
{

    return 159;
}

static bool testSplitString(std::vector<std::string> expected, std::string str)
{
    std::vector<std::string> answer = splitString(str, ',');
    if (expected == answer)
    {
        std::cout << "Split String test: '" << str << "' PASSED" << ", got: ";
        for (auto &p: answer)
        {
            std::cout << "'" << p << "' ";
        }
        std::cout << "\n";
        return true;
    }
    else
    {
        std::cout << "Split String test: '" << str << "' FAILED" << ", got: ";
        for (auto &p: answer)
        {
            std::cout << "'" << p << "' ";
        }

        std::cout << ", expected: ";
        for (auto &p: expected)
        {
            std::cout << "'" << p << "' ";
        }
        std::cout << "\n";        
        return false;
    }
}

static bool testPathExpander(std::vector<std::pair<int, int>> expected, std::string path)
{
    std::vector<std::pair<int, int>> answer;
    expandPath(path, answer);

    if ( expected == answer)
    {
        std::cout << "Step Expander test: '" << path << "'" << " PASSED" << ", got: {";
        for (const auto& p : answer)
        {
            std::cout << p.first << "," << p.second << " ";
        }
        std::cout << "}\n";
        return true;
    }
    else
    {
        std::cout << "Step Expander test: '" << path << "'" " FAILED" << ", got: {";
        for (const auto& p : answer)
        {
            std::cout << p.first << "," << p.second << " ";
        } 
        
        std::cout << "}, expected: {";
        for (const auto& p : expected)
        {
            std::cout << p.first << "," << p.second << " ";
        }
        
        std::cout << "}\n";
        return false;
    }
}

static bool testNearestIntersection (int expected, std::pair<std::string, std::string> stringPair)
{
    int answer = getNearestIntersection(stringPair);

    if (expected == answer)
    {
        std::cout << "Nearest Intersection test:" << " PASSED" << ", got: " << answer << "\n";
        return true;
    }
    else
    {
        std::cout << "Nearest Intersection test:" << " FAILED" << ", got: " << answer << ", expected: " << expected << "\n";
        return false;
    }
}

static void runUnitTests()
{
    bool result = true;

    // Test ManhattanDistance
    result &= testManhattanDistance(6, 3,3);
    result &= testManhattanDistance(6, -3,-3);
    result &= testManhattanDistance(0, 0,0);
    result &= testManhattanDistance(1, 0,1);

    // Test SplitString
    result &= testSplitString({"R1"}, "R1");
    result &= testSplitString({"R1", "U1"}, "R1,U1");
    result &= testSplitString({"R8", "U5", "L5", "D3"}, "R8,U5,L5,D3");

    // Test path exapander;
    result &= testPathExpander({{1,0}}, "R1");
    result &= testPathExpander({{-1,0}}, "L1");
    result &= testPathExpander({{0,1}}, "U1");
    result &= testPathExpander({{0,-1}}, "D1");

    result &= testPathExpander({{1,0}, {2,0}}, "R2");
    result &= testPathExpander({{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}, {10,0}, {11,0}}, "R11");

    result &= testPathExpander({{1,0}, {1,1}}, "R1,U1");
    result &= testPathExpander({{1,0}, {1,1}, {1,2}, {0,2}, {-1,2}, {-2,2}, {-2,1}, {-2,0}, {-2,-1}, {-2,-2}}, "R1,U2,L3,D4");

/*
    //std::pair<std::vector<std::string>, std::vector<std::string>> testData1
    std::pair<std::string, std::string> testData1, testData2, testData3;

    testData1.first = "R8,U5,L5,D3";
    testData1.second = "U7,R6,D4,L4";
    result &= testNearestIntersection(6, testData1);


    testData2.first = "R75,D30,R83,U83,L12,D49,R71,U7,L72";
    testData2.second = "U62,R66,U55,R34,D71,R55,D58,R83";
    result &= testNearestIntersection(159, testData2);
    
    testData3.first = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51";
    testData3.second = "U98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
    result &= testNearestIntersection(135, testData3);
*/
    std::cout << "Unit tests result: " << (result ? "PASSED" : "FAILED") << "\n";
}

int main(int argc, char *argv[])
{
    runUnitTests();

    return 0;
}