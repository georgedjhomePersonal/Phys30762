
#include <iostream>
#include <string>
#include <limits>
int main()
{
    std::string cont{"y"};
    while (cont == "y")
    {
        int z, n_i, n_f;
        std::string unit;
        std::cout << "Separated by a space/new line: enter atomic number (Z), initial energy level (n_i), final energy level (n_f), and unit (J/e): ";
        if (std::cin >> z >> n_i >> n_f >> unit)
        {
        if (n_i< n_f)
        {
            std::cout << "n_i must be greater than n_f" << std::endl;
            
        }
        else
        {
        double delta_E{13.6 * z * z * (1.0 / (n_f * n_f) - 1.0 / (n_i * n_i))};
        if (unit == "J")
        {
            delta_E *= 1.60218e-19;
            std::cout << delta_E << std::endl;
        }
        else if (unit == "e")
        {
            std::cout << delta_E << std::endl;
        }
        else
        {
            std::cout << "Invalid unit" << std::endl;
        } 
        }
    }
    else
    {
        std::cout << "Wrong input type/format" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
        std::cout << "Continue/Retry? (y/n): " << std::endl;
        std::cin >> cont;
    }
    return 0;
}