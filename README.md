# TDD com jogo-da-velha
Esse projeto é um trabalho da disciplina de Métodos de Programação (CIC0234) do curso de Engenharia de Computação da UnB. O objetivo é o desenvolvimento guiado por testes (TDD) de um programa de validação de uma partida de jogo-da-velha.

### Requisitos:
<li> C++ (11+)
<li> GTest
<li> CMake 3.14
<li> CPPLInt
<li> Gcov
<li> Valgrind

<br>Para <b>compilar e iniciar o executável</b>, use a regra <i><b>all</b></i> do Makefile. Para <b>executar os testes unitários</b>, utilize a regra <i><b>test</b></i>. As outras regras do Makefile são descritas a seguir:

```makefile
    all : Compila e executa o programa
    compila : Compila o executável
    valida_velha : Cria o programa final a partir de um arquivo objeto
    velha.o : Cria um arquivo objeto a partir do código-fonte
    run : Executa o programa compilado
    test : Compila e executa o programa de testes com o GTest
    cpplint : Executa o Cpplint nos arquivos de código-fonte
    gcov : Realiza e apresenta (em um HTML) a cobertura de testes com o gcov e gcovr
    valgrind : Executa o verificar dinâmico Valgrind no programa compilado
    debug : Executa o programa compilado com o gdb
    clean : Apaga os arquivos criados e reinicia o diretório para o estado inicial
```
