#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

static int calculateFuelPerModule(int mass)
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

static int calculateFuelPerModuleRecursive(int mass)
{
    /* Recursive call calulation.
     * This is the change for day 1 B */
    int recursiveFuel = 0;
    int individualFuel = 0;
    int individualMass = mass;
    
    while(true)
    {
        individualFuel = calculateFuelPerModule(individualMass);
        //std::cout << "individualMass: " << individualMass << ", gives individualFuel: " << individualFuel << "\n";
        
        if (individualFuel <= 0)
        {
            break;
        }
        recursiveFuel += individualFuel;
        individualMass = individualFuel;
    }

    return recursiveFuel;
}

int calculateTotalFuel(std::vector<std::string> vectorMass)
{
    int totalFuel = 0;
    for (auto iterMass = vectorMass.begin(); iterMass != vectorMass.end(); ++iterMass)
    {
        totalFuel += calculateFuelPerModuleRecursive(std::stoi(*iterMass));
    }

    return totalFuel;
}

static bool runTestPerModule(int expected, int input)
{
    static int count = 1;
    int answer = calculateFuelPerModuleRecursive(input); // Note using Rrecursive
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

static bool runTestOnVector(int expected, std::vector<std::string> testData)
{
    int answer = calculateTotalFuel(testData);
    if (expected == answer)
    {
        std::cout << "vector test:" << " PASSED" << ", got: " << answer << "\n";
        return true;
    }
    else
    {
        std::cout << "vector test:" << " FAILED" << ", got: " << answer << ", expected: " << expected << "\n";
        return false;
    }
}

static void runUnitTests()
{
    bool result = true; 

    // Individual module calculations
    result &= runTestPerModule(2, 14);
    result &= runTestPerModule(966, 1969);
    result &= runTestPerModule(50346, 100756);

    // Simulate an input.txt file with text strings
    std::vector<std::string> testData;
    testData.push_back("14");
    testData.push_back("1969");
    testData.push_back("100756");

    result &= runTestOnVector(51314, testData);

    std::cout << "Unit tests result: " << (result ? "PASSED" : "FAILED") << "\n";
}

int main (int argc, char *argv[])
{
    runUnitTests();
    //exit(0); // Only run tests
    
    // Read in input.txt to a vector of strings
    std::ifstream infile("input.txt");
    std::string line;
    std::vector<std::string> realData;
   
    while (infile >> line)
    {
        std::cout << "processing \"" << line << "\"\n";
        realData.push_back(line);
    }

    int neededFuel = calculateTotalFuel(realData);

    std::cout << "Total fuel needed: " << neededFuel << "\n";

    return 0;
}