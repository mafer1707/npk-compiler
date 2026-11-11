#include <npk_lexer.hpp>

int main() 
{
    Lexer lexer = make_lexer();
    DynArray<Token> tokens = lexer.tokenize("entero miVariable = 10 real miVariable2 = 98.89");

    for (nat_t i = 0; i < tokens.size(); ++i)
    {
        const Token& t = tokens[i];

        if (t.name == "EB")
        {
            continue;
        }

        std::cout << t.name << "(\"" << t.lexeme << "\") @" << t.position << std::endl;
    }

    return 0;
}