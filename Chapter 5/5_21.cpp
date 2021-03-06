#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main () 
{
  std::vector<std::string> text;
  std::string word;
  int cnt = 0;

  while (std::cin >> word && !word.empty())
  {
    if (isupper(word [0]))
    {
      text.push_back(word);
      for (size_t i = 0; i != text.size(); ++i)
        if (text[i] == text [i+1])
        {
          ++cnt;
          std::cout << "Word " << '"' << text[i] << '"' << " repeated." << std::endl;
          break;
        }     
    }
    else continue;
    
    if (cnt == 1)
      break;
  }
  if (cnt == 0)
    std::cout << "No word was repeated." << std::endl;

  return 0;
}

