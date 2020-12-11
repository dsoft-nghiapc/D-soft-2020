#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class TextInput
{

public:
    std::vector<std::string> dst = {};
    std::string ResultTextInput;   
    virtual void add(char c) {
        std::string temp;
        temp.push_back(c);
        dst.push_back(temp);
     }
    virtual std::string getValue() { 
        for (int i = 0; i < dst.size(); i++)
        {
       //std::cout << dst[i] << std::ends;
          ResultTextInput.append(dst[i]);
        }
      return ResultTextInput;
    }
     
};

class NumericInput : public TextInput { 

public:
    std::vector<std::string> dst = {};
    bool CheckValue;
    std::string ResultNumberInput;  
    void add(char c) {
        std::string temp;
        temp.push_back(c);
        dst.push_back(temp);
     }

    std::string getValue() { 
        for (int i = 0; i < dst.size(); i++)
    {
       //std::cout << dst[i] << std::ends;
            try
            {  std::string x = dst[i];
               int myint1 = std::stoi(x);
               CheckValue = true;
            }
             catch(const std::exception& e)
            {
                 CheckValue = false;
                //std::cout << CheckValue << std::ends;
            }
            
        //std::cout << CheckValue << std::ends;
        if (CheckValue == true)
        {
            ResultNumberInput.append(dst[i]);
        }
      }
      return ResultNumberInput;
    }


};


int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
