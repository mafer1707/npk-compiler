#include <npk_lexer.hpp>

using namespace Designar;

Lexer make_lexer() 
{
    std::cout<<"Run make_lexer!"<<std::endl;
    Lexer lexer;

    std::string num = "0|1|2|3|4|5|6|7|8|9";
    std::string mayus = "A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z";
    std::string minus = "a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z";

    //Tipos
    lexer.add_token("ENTERO", "entero");
    lexer.add_token("REAL", "real");
    lexer.add_token("BOOL", "booleano");
    lexer.add_token("CADENA", "cadena");
    lexer.add_token("CARACTER", "caracter");

    //Control de flujo
    lexer.add_token("SI", "si");
    lexer.add_token("HACER", "hacer");
    lexer.add_token("FIN_SI", "fin si");
    lexer.add_token("ELSE", "sino");
    lexer.add_token("ELSE_IF", "sino si");
    lexer.add_token("MIENTRAS", "mientras");
    lexer.add_token("FIN_MIENTRAS", "fin mientras");
    lexer.add_token("REPETIR", "repetir");
    lexer.add_token("VECES", "veces");
    lexer.add_token("FIN_REPETIR", "fin repetir");
    lexer.add_token("DESDE", "desde");
    lexer.add_token("HASTA", "hasta");
    lexer.add_token("SALIR", "salir");
    lexer.add_token("CONTINUAR", "continuar");
    lexer.add_token("VERDADERO", "verdadero");
    lexer.add_token("FALSO", "falso");

    //Funciones
    lexer.add_token("IMPRIMIR", "imprimir");
    lexer.add_token("LEER", "leer");

    //Operadores lógicos
    lexer.add_token("LOGICO_Y", "y");
    lexer.add_token("LOGICO_O", "o");

    //Literales
    lexer.add_token("CAD", "\"(" + mayus + "|" + minus + "|" + num + "|.|,|<|>|=|\\+|-|!|#|%|\\*|\\?|\\(|\\)|{|}|[|])*\""); 
    lexer.add_token("CAR", "'(" + mayus + "|" + minus + "|" + num + "|.|,|<|>|=|\\+|-|!|#|%|\\*|\\?|\\(|\\)|{|}|[|])+'");
    lexer.add_token("NUM_ENTERO",  "-?(" + num + ")+");
    lexer.add_token("NUM_REAL", "-?(" + num + ")+" + "(.(" + num + ")+)?"); 
    
    //Operadores aritméticos
    lexer.add_token("SUMA", "\\+");
    lexer.add_token("RESTA", "-");
    lexer.add_token("MUL", "\\*");
    lexer.add_token("DIV", "/");
    lexer.add_token("ASIGNAR", ":=");
    lexer.add_token("IGUAL", "=");
    lexer.add_token("DISTINTO", "!=");
    lexer.add_token("MAYOR", ">");
    lexer.add_token("MAYOR_I", ">=");
    lexer.add_token("MENOR", "<");
    lexer.add_token("MENOR_I", "<=");
    
    // Símbolos de agrupación
    lexer.add_token("PAREN_I", "\\(");
    lexer.add_token("PAREN_D", "\\)");
    lexer.add_token("COR_I", "]");
    lexer.add_token("COR_D", "[");
    lexer.add_token("LLAVE_I", "{");
    lexer.add_token("LLAVE_D", "}");
    lexer.add_token("COMA", ",");
    lexer.add_token("DOS_PUNTOS", ":");
    
    //Espacios en Blanco
    lexer.add_token("ID", "(" + minus + "|" + mayus + ")" + "(" + minus + "|" + mayus + "|" + num + ")*");
    lexer.add_token("EB", " "); 

    return lexer;
}