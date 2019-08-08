/* Generated by re2c 1.1.1 */
#line 1 "tokenizer.re"
#include "tokenizer.h"
#include "parser.tab.hh"

namespace SymEngine
{

void Tokenizer::set_string(const std::string &str)
{
    // The input string must be NULL terminated, otherwise the tokenizer will
    // not detect the end of string. After C++11, the std::string is guaranteed
    // to end with \0, but we check this here just in case.
    SYMENGINE_ASSERT(str[str.size()] == '\0');
    cur = (unsigned char *)(&str[0]);
}

int Tokenizer::lex(YYSTYPE &yylval)
{
    for (;;) {
        tok = cur;

#line 24 "tokenizer.cpp"
        {
            unsigned char yych;
            static const unsigned char yybm[] = {
                0,   0,   0,   0,   0,   0,   0,   0,   0,   32,  32,  32,  0,
                32,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   32,  0,   0,   0,   0,   0,   0,
                0,   0,   0,   0,   0,   0,   0,   0,   0,   192, 192, 192, 192,
                192, 192, 192, 192, 192, 192, 0,   0,   0,   0,   0,   0,   0,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                0,   0,   0,   0,   128, 0,   128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 0,   0,   0,   0,   0,   128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
                128, 128, 128, 128, 128, 128, 128, 128, 128,
            };
            yych = *cur;
            if (yybm[0 + yych] & 32) {
                goto yy6;
            }
            if (yych <= '9') {
                if (yych <= '*') {
                    if (yych <= 0x00)
                        goto yy2;
                    if (yych <= '\'')
                        goto yy4;
                    if (yych <= ')')
                        goto yy9;
                    goto yy11;
                } else {
                    if (yych == '.')
                        goto yy4;
                    if (yych <= '/')
                        goto yy9;
                    goto yy12;
                }
            } else {
                if (yych <= '^') {
                    if (yych <= '?')
                        goto yy4;
                    if (yych <= '@')
                        goto yy15;
                    if (yych <= 'Z')
                        goto yy17;
                    goto yy4;
                } else {
                    if (yych <= '`') {
                        if (yych <= '_')
                            goto yy17;
                        goto yy4;
                    } else {
                        if (yych <= 'z')
                            goto yy17;
                        if (yych <= 0x7F)
                            goto yy4;
                        goto yy17;
                    }
                }
            }
        yy2:
            ++cur;
#line 37 "tokenizer.re"
            {
                return yytokentype::END_OF_FILE;
            }
#line 97 "tokenizer.cpp"
        yy4:
            ++cur;
#line 36 "tokenizer.re"
            {
                throw SymEngine::ParseError("Unknown token: '" + token() + "'");
            }
#line 102 "tokenizer.cpp"
        yy6:
            yych = *++cur;
            if (yybm[0 + yych] & 32) {
                goto yy6;
            }
#line 38 "tokenizer.re"
            {
                continue;
            }
#line 110 "tokenizer.cpp"
        yy9:
            ++cur;
        yy10 :
#line 41 "tokenizer.re"
        {
            return tok[0];
        }
#line 116 "tokenizer.cpp"
        yy11:
            yych = *++cur;
            if (yych == '*')
                goto yy15;
            goto yy10;
        yy12:
            yych = *++cur;
            if (yybm[0 + yych] & 64) {
                goto yy12;
            }
#line 44 "tokenizer.re"
            {
                yylval.string = token();
                return yytokentype::NUMERIC;
            }
#line 128 "tokenizer.cpp"
        yy15:
            ++cur;
#line 42 "tokenizer.re"
            {
                return yytokentype::POW;
            }
#line 133 "tokenizer.cpp"
        yy17:
            yych = *++cur;
            if (yybm[0 + yych] & 128) {
                goto yy17;
            }
#line 43 "tokenizer.re"
            {
                yylval.string = token();
                return yytokentype::IDENTIFIER;
            }
#line 141 "tokenizer.cpp"
        }
#line 45 "tokenizer.re"
    }
}

} // namespace SymEngine
