/*
 * A reverse-polish notation calculator.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>


auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}


auto evaluate_addition(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

auto evaluate_subtraction(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto evaluate_division(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for //"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    int p=a/b;
    stack.push(p);
}
auto evaluate_division2(std::stack<double>& stack) -> void  // dzielenie z ułamkami
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for /"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a / b);
}
auto evaluate_multiply(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for *"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto evaluate_mod(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    auto const p = fmod(a,b);
    stack.push(p);
}

auto evaluate_pot(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for **"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    auto const p = pow(a,b);
    stack.push(p);
}
auto evaluate_sqrt(std::stack<double>& stack) -> void
{
   // if (stack.size() < 2) {
    //    throw std::logic_error{"not enough operands for +"};
   // }
    auto const b = pop_top(stack);
  //  auto const a = pop_top(stack);
  //  auto const p = pow(a,1/double(b));

  //  stack.push(p);
     stack.push(sqrt(b));
}
auto evaluate_nwd(std::stack<double>& stack) -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for nwd"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    int p1=a;
    int p2=b;
    while(p1!=p2){
    if(p1>p2) p1-=p2;
    else p2-=p1;
}
    stack.push(p1);
}

auto make_args(int argc, char* argv[]) -> std::vector<std::string>
{
    auto args = std::vector<std::string>{};
    std::copy_n(argv, argc, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    auto const args = make_args(argc - 1, argv + 1);

    auto stack = std::stack<double>{};
    for (auto const each : args) {
        try {
            if (each == "p") {
                std::cout << pop_top(stack) << "\n";
            } else if (each == "+") {
                evaluate_addition(stack);
            } else if (each == "-") {
                evaluate_subtraction(stack);
            }
                else if(each == "*") {
                std::cout<<"tak";
                evaluate_multiply(stack);
            }   else if(each == "/") {
                evaluate_division2(stack);
            }   else if(each == "//") {
                evaluate_division(stack);
            }   else if(each == "%") {
                evaluate_mod(stack);
            }   else if(each == "**") {
                evaluate_pot(stack);
            }   else if(each == "sqrt") {
                evaluate_sqrt(stack);
            }   else if(each == "nwd") {
                evaluate_nwd(stack);
            }

                 else {
                stack.push(std::stod(each));
            }
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }

    return 0;
}
