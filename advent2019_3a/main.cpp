#include <iostream>
#include <vector>
#include <string>


int ManhattanDistanceFromOrigo(int x, int y)
{

    return 1;
}


bool testManhattanDistance(int expected, int x, int y)
{
    int answer = ManhattanDistanceFromOrigo(x, y);
    if (expected == answer)
    {
        std::cout << "Manhattan Distence test:" << " PASSED" << ", got: " << answer << "\n";
        return true;
    }
    else
    {
        std::cout << "Manhattan Distence test:" << " FAILED" << ", got: " << answer << ", expected: " << expected << "\n";
        return false;
    }
}


static void runUnitTests()
{
    bool result = true;

    // Test ManhattanDistance
    result &= testManhattanDistance(6, 3,3);

    /*
std::vector<std::string> testData;


R75,D30,R83,U83,L12,D49,R71,U7,L72
U62,R66,U55,R34,D71,R55,D58,R83
distance 159

R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51
U98,R91,D20,R16,D67,R40,U7,R15,U6,R7
distance 135
*/
    
}


int main(int argc, char *argv[])
{
    runUnitTests();

    return 0;
}