/*
    convert.cpp

    Convert the text

    Note: The "@concern" are for pedagogical purposes only.

    * @concern are assume to be [in], meaning they are predefined and used in the code
    * @concern marked [out] meaning they are produced in that section
*/

#include <iostream>
#include <string>
#include <cctype>

// @concern "--lower", isOptionLower[out]
bool isOptionLower(const std::string& s) {

    return s == "--lower";
}

// @concern "--upper", isOptionUpper[out]
bool isOptionUpper(const std::string& s) {

    return s == "--upper";
}

// output character to standard output
// @concern output format, std::cout, output[out]
void output(char c) {
    std::cout << c;
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concern input format, argc, argv, error handling, std::cerr
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @concern input format, argv, std::string, option[out]
    std::string option(argv[1]);

    // input text
    // @concern input format, argv, std::string, text[out]
    std::string text(argv[2]);

    // convert the string according to the option
    // @concern option, text, isOptionUpper(), isOptionLower()
    // @concern std::string, std::toupper(), std::tolower(), iteration
    // @concern error handling, std::cerr
    if (isOptionUpper(option)) {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::toupper(*pc);

    } else if (isOptionLower(option)) {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::tolower(*pc);

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // output converted text
    // @concern output format, text, std::string, iteration, output()
    for (auto pc = text.cbegin(); pc != text.cend(); ++pc)
        output(*pc);
    std::cout << '\n';

    return 0;
}
