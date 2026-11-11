#include <npk_lexer.hpp>
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[]) 
{
    if (argc < 2)  
    {
        std::cerr << "Uso incorrecto. Formato esperado: " << argv[0] << " <archivo.txt>\n";
        return 1; 
    }

    std::string nombre_archivo = argv[1];
    std::ifstream archivo(nombre_archivo);

    if (!archivo.is_open()) 
    {
        std::cerr << "Error: No se pudo abrir el archivo '" << nombre_archivo << "'\n";
        return 1;
    }

    Lexer lexer = make_lexer();

    DynArray<Token> all_tokens;
    std::string linea;

    while (std::getline(archivo, linea))
    {
        if (!linea.empty() && linea.back() == '\r') 
        {
            linea.pop_back(); 
        }

        std::replace(linea.begin(), linea.end(), '\t', ' ');

        DynArray<Token> tokens = lexer.tokenize(linea);
     
        for (nat_t i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i].name != "EB")
            {
                all_tokens.append(tokens[i]);
            }
        }         
    }

    for (nat_t i = 0; i < all_tokens.size(); ++i)
    {
        const Token& t = all_tokens[i];
        std::cout << t.name << "(\"" << t.lexeme << "\") @" << t.position << std::endl;
    }

    return 0;
}