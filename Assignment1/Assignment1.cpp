#include <iostream>
#include <string>
#include <limits>

double BohrEnergy()
{
    int z, n_i, n_f;
    std::string unit;
    std::cout << "Separated by a space/new line: enter atomic number (Z), initial energy level (n_i), final energy level (n_f), and unit (J/e): ";
    if (!(std::cin >> z >> n_i >> n_f >> unit))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Wrong data type(s) used");
    }
    if (n_i <= 0 || n_f <= 0 || n_i < n_f)
    {
        throw std::invalid_argument("n_i and n_f should be positive integers > 0 where n_i should be greater than n_f");
    }
    double delta_E{13.6 * z * z * (1.0 / (n_f * n_f) - 1.0 / (n_i * n_i))};
    if (unit == "J")
    {
        delta_E *= 1.60218e-19;
        return delta_E;
    }
    else if (unit == "e")
    {
        return delta_E;
    }
    else
    {
        throw std::invalid_argument("Invalid units");
    }
}
int main()
{
    std::string cont{"y"};
    while (cont == "y")
    {

        try
        {
            std::cout << BohrEnergy() << std::endl;
        } catch (const std::exception& e){
            std::cerr << "Exception caught:" << e.what() << std::endl;
        }
        std::cout << "Continue/Retry? (y/n): " << std::endl;
        std::cin >> cont;
    }
    return 0;
}