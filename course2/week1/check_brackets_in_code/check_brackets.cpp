#include <iostream>
#include <stack>
#include <string>

struct Bracket 
{
    Bracket(char type = '[', int position = 0):
        type(type),
        position(position)
    {}

    bool Matchc(char c) 
	{
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
	int position_unmatched = 0;
	
    for (int position = 0; position < text.length(); ++position) 
	{
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') 
		{
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') 
		{
            Bracket opening_bracket;
			
			if(opening_brackets_stack.size() == 0)
			{
				std::cout << position + 1;
				return 0;
			}
			else
			{
				opening_bracket = opening_brackets_stack.top();
				opening_brackets_stack.pop();
			}
			
			if (opening_bracket.Matchc(next) == false)
			{
				std::cout << position + 1;
				return 0;
			}
        }
    }

	if(opening_brackets_stack.size() == 0)
	{
		std::cout << "Success";
	}
	else
	{
		Bracket opening_bracket = opening_brackets_stack.top();
		opening_brackets_stack.pop();
		std::cout << opening_bracket.position + 1;
	}
	
    return 0;
}
