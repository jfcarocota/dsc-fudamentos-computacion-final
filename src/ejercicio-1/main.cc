
/* 
Ejercicio 1
Se desea escribir un programa para evaluar expresiones que representan operaciones entre
conjuntos de números naturales menores que 1000. Los conjuntos están expresados por listas
de valores separados por comas, y encerrados entre llaves. Los siguientes son cuatro ejemplos
de conjuntos representados de este modo: {1,3,9,77} {} {7,1,193} {55}.

1) Note que como las listas representan conjuntos, {1,3,9,77} y {77,3,1,9}
representan el mismo conjunto y pueden utilizarse indistintamente.

2) Una expresión puede ser simplemente una lista. Por ejemplo, {7,1,193} es una expresión
cuyo resultado es ese mismo conjunto.

3) Una expresión puede también formarse con dos listas, o expresiones, separadas por *, que
representa la intersección de conjuntos, es decir el conjunto de los elementos comunes a
ambos. Por ejemplo, {1,3,9,77}*{7,1,193} da como resultado {1}.

4) Con igual forma constructiva, pero usando +, se calcula la unión, es decir el conjunto de los
elementos que están al menos en uno de los dos conjuntos. Por ejemplo,
{1,3,9,77}+{7,1,193} da como resultado {1,3,7,9,77,193}.

5) Cuando hay múltiples operaciones seguidas, se evalúa de izquierda a derecha. Por ejemplo,
{1,3,9,77}*{7,1,193}+{55} da como resultado {1,55}.
Para expresar explícitamente un orden, cualquier expresión puede encerrarse entre
paréntesis. 
Por ejemplo, {1,3,9,77}*({7,1,193}+{55}) da como resultado {1}.

6) Estas reglas pueden aplicarse repetidamente. Por ejemplo, las siguientes expresiones son
válidas: (((({})))), (({1}+{2,3})*({4,5,6}+{})), {}+({}+{})+({5}).

7) El programa a escribir debe leer una expresión, de hasta 250 caracteres, del archivo
expres.in, evaluarla, y grabar el conjunto resultante como una lista en el mismo formato
que la entrada, en el archivo expres.out.

8) Por ejemplo, si expres.in contiene:
(({3}+({1,4,2}))*({1,2,3,4,5}*{4,3,2,5}*{2,3,4,5,6}+{}))+{}
el archivo expres.out podría contener
{2,3,4}
*/

#include <iostream>
#include<vector>
#include<fstream>
#include<string>
//std::vector<std::vector<int>> vec2 = {{1, 2}, {2}};

//std::string fileToString(std::ifstream file);

std::string data;

/// <summary>
///Imprime un objeto string en consola
///</summary>
void PrintString(const std::string data)
{
    std::cout << data << std::endl;
}

std::string fileToString(std::ifstream& file)
{
    std::string content
    {
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    };
    return content;
}

int main()
{

    //ReadFile("src/ejercicio-1/express.in");
    std::ifstream in("src/ejercicio-1/express.in");
    std::ifstream out("express.out");
    //data = fileToString(inf);
    std::cout << data << std::endl;
    if(in.is_open())
    {
        std::getline(in, data);
        PrintString("Data cargada, pulse cualquier tecla para continuar...");
        std::getchar();
        
        const char* datachar = data.data();
        for(int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << std::endl;
            switch(data[i])
            {
                case '(' :
                    break;
                case ')' :
                    break;
                case '+' :
                    break;
                case '*' :
                    break;
                case '{' :
                    break;
                case '}' :
                    break;
                case ',' :
                    break;
                case '0' :
                    break;
                case '1' :
                    break;
                case '2' :
                    break;
                case '3' :
                    break;
                case '4' :
                    break;
                case '5' :
                    break;
                case '6' :
                    break;
                case '7' :
                    break;
                case '8' :
                    break;
                case '9' :
                    break;
            }
        }
    } 
    else
    {
         std::cout << "Unable to open file";
    }
    in.close();

    //PrintString(data);

    std::getchar();
}

