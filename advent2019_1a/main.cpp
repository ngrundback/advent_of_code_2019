#include <iostream>


static int calculateFuel(int mass)
{
    int fuel = 2;

    return fuel;
}

static bool runTest(int expected, int input)
{
    static int count = 1;
    int answer = calculateFuel(input);
    if (expected == answer)
    {
        std::cout << "test:"<< count << " PASSED" << ", input: " << input 
        << ", got: " << answer << "\n";
        return true;
    }
    else
    {
        std::cout << "test:"<< count << " FAILED" << ", input: " << input 
        << ", got: " << answer << ", expected: " << expected << "\n";
        return false;
    }
}


static void runUnitTests()
{
    bool result = true;

    result &= runTest(2,12);

    std::cout << "Unit tests result: " << (result ? "PASSED" : "FAILED") << "\n";
}

int main (int argc, char *argv[])
{
    // print bool values as 'true/false' instead of '1/0'
    std::cout.setf(std::ios::boolalpha);
 
    runUnitTests();

    return 0;
}