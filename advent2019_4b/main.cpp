#include <iostream>
#include <cstdlib>
#include <string>

/* NOTES:
   What is faster
    - working with int
        modulus (%)
        some sort of lookup table. See https://stackoverflow.com/questions/7890194/optimized-itoa-function 
    - working with string
        sprintf("%d")
        itoa()
        << operator
        std::string with to_string()
    - probably depends on how many digits
 */


#define NUM_DIGITS 6

static bool hasAtleastTwoAdjecentValues(int value)
{
    char str[NUM_DIGITS + 1];
    snprintf(str, NUM_DIGITS + 1, "%d", value);

    //std::cout << "converted " << value << " to " << str << "\n";

    int i = 0;
    char c = str[0];

    while(++i) 
    {
        if (i == NUM_DIGITS)
        {
            //std::cout << "return false, reached end, c=" << c << " i=" << i << "\n";
            return false;
        }
        if (c == str[i])
        {
            //std::cout << "return true, c=" << c << " i=" << i << "\n";
            return true;
        }
        c = str[i];
    }
}

static bool testHasAtleastTwoAdjecentValues(bool expect, int value)
{
    bool answer = hasAtleastTwoAdjecentValues(value);

    if (answer == expect)
    {
        std::cout << "AdjecentValues PASSED for: " << value << "\n";
        return true;
    }
    else
    {
        std::cout << "AdjecentValues FAILED for: " << value << "\n";
        return false;
    }
}

static bool hasExactDouble(int value)
{
    char str[NUM_DIGITS + 1];
    snprintf(str, NUM_DIGITS + 1, "%d", value);

    //std::cout << "\nconverted " << value << " to " << str << "\n";

    int i = 0;
    char c = str[0];

    while(++i) 
    {
        //std::cout << "c=" << c << " i=" << i << "\n";

        if (i == NUM_DIGITS)
        {
            //std::cout << "return false, reached end, c=" << c << " i=" << i << "\n";
            return false;
        }
        if (c == str[i])
        {
            //std::cout << "found adjecent, investigate... c=" << c << " i=" << i << "\n";
            if (i == NUM_DIGITS - 1)
            {
                //std::cout << "return true, double at end of string, c=" << c << " i=" << i << "\n";
                return true;
            }
            if (c != str[i + 1])
            {
                //std::cout << "return true, exactly a double, c=" << c << " i=" << i << "\n";
                return true;
            }
            if (c == str[i + 1])
            {
                //std::cout << "found tripple or more, skip forward, c=" << c << " i=" << i << "\n";
                while(c == str[i])
                {
                    ++i;
                    if (i == NUM_DIGITS)
                    {
                        //std::cout << "return false, reached end while skipping, c=" << c << " i=" << i << "\n";
                        return false;
                    }
                }
            }
        }
        c = str[i];
    }

}

static bool testHasExactDouble(bool expect, int value)
{
    bool answer = hasExactDouble(value);

    if (answer == expect)
    {
        std::cout << "HasExactDouble PASSED for: " << value << "\n";
        return true;
    }
    else
    {
        std::cout << "HasExactDouble FAILED for: " << value << "\n";
        return false;
    }
}

static bool digitsNeverDecrease(int value)
{
    char str[NUM_DIGITS + 1];
    snprintf(str, NUM_DIGITS + 1, "%d", value);

    //std::cout << "converted " << value << " to " << str << "\n";

    int i = 0;
    char c = str[0];

    while(++i) 
    {
        if (i == NUM_DIGITS)
        {
            //std::cout << "return true, reached end without decrease, c=" << c << " i=" << i << "\n";
            return true;
        }
        if (c > str[i])
        {
            //std::cout << "return false, c=" << c << " next:" << str[i] << " i=" << i << "\n";
            return false;
        }
        c = str[i];
    }
    return true;
}

static bool testDigitsNeverDecrease(bool expect, int value)
{
    bool answer = digitsNeverDecrease(value);

    if (answer == expect)
    {
        std::cout << "NeverDecrease PASSED for: " << value << "\n";
        return true;
    }
    else
    {
        std::cout << "NeverDecrease FAILED for: " << value << "\n";
        return false;
    } 
}

static void runUnitTests()
{
    bool result = true;

    result &= testHasAtleastTwoAdjecentValues(true,  111111);
    result &= testHasAtleastTwoAdjecentValues(false,  123789);
    result &= testHasAtleastTwoAdjecentValues(true,  123345);
    result &= testHasAtleastTwoAdjecentValues(true,  123455);
    result &= testHasAtleastTwoAdjecentValues(false, 123456);
    result &= testHasAtleastTwoAdjecentValues(false, 121212);

    std::cout << "\n";
    result &= testDigitsNeverDecrease(false, 223450);
    result &= testDigitsNeverDecrease(true,  123456);

    std::cout << "\n";
    result &= testHasExactDouble(false,  123456);
    result &= testHasExactDouble(true,  123455);
    result &= testHasExactDouble(true,  112233);
    result &= testHasExactDouble(false, 123444);
    result &= testHasExactDouble(true,  111122);
    result &= testHasExactDouble(true,  111223);

    

    std::cout << "\nUnit tests " << (result ? "PASSED" : "FAILED") << "\n";
}

static void solveProblem()
{
    int possiblePasswords = 0;
    int lowestValue = 356261;
    int highestValue = 846303;

    int value = lowestValue;

    while (value < highestValue)
    {
        if (hasExactDouble(value) && digitsNeverDecrease(value))
        {
            ++possiblePasswords;
        }

        ++value;
    }

    std::cout << "Number of possible passwords: " << possiblePasswords << "\n";

    // Your puzzle answer was 334.
}

int main(int argc, char *argv[])
{
    runUnitTests();

    solveProblem();
    
    return 0;
}
