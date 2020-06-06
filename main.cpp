#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <stack>

bool valid_braces(std::string braces) 
{
  bool valid = false;
  std::stack<char> matches;
  std::map<char, char> validBraces = {{'(',')'}, {'{','}'}, {'[',']'}};
  
  for(char sign : braces)
  {
    auto searchOpenBracket = validBraces.find(sign);
    if (searchOpenBracket != validBraces.end())
    {
      matches.push(sign);
    }
    
    if (!matches.empty())
    {
      for (auto& element : validBraces)
      {
        if (sign == element.second)
        {
          if (sign == validBraces[matches.top()])
          {
            matches.pop();
            valid = matches.empty();
          }
          else
          {
            return false;
          }
        }
    }
    }
  }
  return valid;
}

int main(void)
{
	std::cout << "Type some string: " << std::endl;
	std::string input;
	std::cin >> input;
        if(valid_braces(input))
	{
		std::cout << "Valid!" << std::endl;
	}else{
		std::cout << "Invalid" << std::endl;
	}
	
}
