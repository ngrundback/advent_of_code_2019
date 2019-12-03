#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int ManhattanDistanceFromOrigo(int x, int y)
{
    return std::abs(x) + std::abs(y);
}

static void expandPath(std::string path, std::vector<std::pair<int , int>> &steps)
{
    steps.push_back({1, 0});
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

static bool testStepExpander(std::vector<std::pair<int, int>> expected, std::string path)
{
    std::vector<std::pair<int, int>> answer;
    expandPath(path, answer);

    if ( expected == answer)
    {
        std::cout << "Step Expander test:" << " PASSED" << ", got: {";
        for (const auto& p : answer)
        {
            std::cout << p.first << ", " << p.second << " ";
        }
        std::cout << "}\n";
        return true;
    }
    else
    {
        std::cout << "Step Expander test:" << " FAILED" << ", got: {";
        for (const auto& p : answer)
        {
            std::cout << p.first << ", " << p.second << " ";
        } 
        
        std::cout << "}, expected: {";
        for (const auto& p : expected)
        {
            std::cout << p.first << ", " << p.second << " ";
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

    // Test step exapander
    std::string testPath1 = "R1";
    std::vector<std::pair<int, int>> expectedSteps1 = {{1,0}};
    result &= testStepExpander(expectedSteps1, testPath1);
    result &= testStepExpander({{-1,0}}, "L1");

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