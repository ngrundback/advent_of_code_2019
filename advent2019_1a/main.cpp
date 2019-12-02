#include <iostream>
#include <cmath>


static int calculateFuel(int mass)
{
    /* Fuel required to launch a given module is based on its mass.
     * Specifically, to find the fuel required for a module, 
     * take its mass, 
     * divide by three,
     * round down, 
     * and subtract 2. */
    double fuel = mass / 3.0 ;
    //std::cout << "fuel after division by 3: " << fuel << "\n";
    fuel = std::floor(fuel);
    //std::cout << "fuel after rounding down: " << fuel << "\n";
    fuel -= 2;
    //std::cout << "fuel after subtracting 2: " << fuel << "\n";

    return (int)fuel;
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

    result &= runTest(2, 12);
    result &= runTest(2, 14);
    result &= runTest(654, 1969);
    result &= runTest(33583, 100756);

    std::cout << "Unit tests result: " << (result ? "PASSED" : "FAILED") << "\n";
}

int main (int argc, char *argv[])
{
    // print bool values as 'true/false' instead of '1/0'
    std::cout.setf(std::ios::boolalpha);
 
    runUnitTests();

    return 0;
}