#include "RGBHex.h"


int main()
{
    unsigned int numInputs = 0;
    std::string  hexColor;
    char         *hex;
    
    std::ifstream     input("HexInput.txt");

    if(input.is_open())
    {
        input >> numInputs;
        for(int i = 0; i < numInputs; i++)
        {
            input >> hexColor;
            std::cout << "The color entered is: "<<hexColor<<std::endl;
            hex = const_cast<char *>(hexColor.c_str());
            if(hex[0]=='#')
            std::cout << "The dominant color is: "<<findMax(hex);
        }
    }
    input.close();
    return 0;
}

std::string findMax(char *str)
{
    unsigned int red = 0x00, green = 0x00, blue = 0x00;
    std::string temp[3] = {"0x","0x","0x"};
    for(int i=1, j=0;i<strlen(str);i = i + 2,j++)
    {
        // Concatenate elements of temp with values in str making
        // the comparison of those numbers as hex values possible.
        temp[j] += str[i];
        temp[j] += str[i+1];
    }
    std::stringstream convertRed (temp[R]);
    convertRed >> std::hex >> red;
    std::stringstream convertGreen (temp[G]);
    convertGreen >> std::hex >> green;
    std::stringstream convertBlue (temp[B]);
    convertBlue >> std::hex >> blue;
    
    if(red > blue && red > green)
        return "red.\n";
    else if (blue > red && blue > green)
        return "blue.\n";
    else if (green >red && green > blue)
        return "green.\n";
    else if(red == blue && red != green && red > green)
        return "magenta.\n";
    else if(red == green && red != blue && red > blue)
        return "yellow.\n";
    else if(blue == green && blue != red && blue > red)
        return "cyan.\n";
    else if(red == green && red == blue)
        return "grey.\n";
   /*
    if(atoi(temp[R].c_str()) > temp[G])
    {
        if(temp[R1]>temp[B1])
            return "red.\n";
        else if(temp[R1]==temp[B1])
            return "magenta.\n";
    } */
    //return "Trying to find out.\n";
}

