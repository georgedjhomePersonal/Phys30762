
#include <iostream>
#include <string>
int main()
{
    std::string cont{"y"};
    while (cont == "y")
    {
        int z, n_i, n_f;
        std::string unit;
        std::cin >> z >> n_i >> n_f >> unit;
        double delta_E{13.6 * z * z * (1.0 / (n_i * n_i) - 1.0 / (n_f * n_f))};
        if (unit == "j")
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
        std::cin >> cont;
    }
    return 0;
}