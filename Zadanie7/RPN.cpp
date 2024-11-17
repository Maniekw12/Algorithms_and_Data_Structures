#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include "vector"
#include "cassert"

bool isoperator(std::string c);
int rpn(const std::vector<std::string>& input);


int main()
{
    std::vector<std::string> onp1 { "2", "3", "+","6","*" };
    std::vector<std::string> onp2 {"6", "2", "/" };
    std::vector<std::string> onp3 {"+4", "-2", "-"};

    assert(rpn(onp1)==30);
    std::cout <<"\n(2+3)*6 = "<< rpn(onp1) << std::endl;


    assert(rpn(onp2) == 3);
    std::cout << "\n6/2= " << rpn(onp2) << std::endl;


    assert(rpn(onp3) == 6);
    std::cout << "\n+4-(-2)= " << rpn(onp3) << std::endl;


}

bool isoperator(std::string c) {
    return c == "+" || c == "-" || c == "*" || c == "/";
}

int rpn(const std::vector<std::string>& input) {
    std::stack<int> stack;

    for(auto letter : input) {
        if (isdigit(letter[0]) || ((letter[0] == '-' || letter[0] == '+') && letter.length() != 1)) {
            stack.push(stoi(letter));
        } else if (isoperator(letter)) {
            char a = stack.top();
            stack.pop();
            char b = stack.top();
            stack.pop();
            if(letter == "-") {
                stack.push(b-a);
            }
            else if (letter=="+") {
                stack.push(b+a);
            }
            else if (letter=="*") {
                stack.push(b*a);
            }
            else if (letter=="/") {
                stack.push(b/a);
            }
        }
    }
    return stack.top();
}





