
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
#include<algorithm>
#include<sstream>

std::string data;
std::vector<char> vecData;
std::ifstream in("src/ejercicio-1/express.in");
std::ifstream out("src/ejercicio-1/express.out");

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

void FillVector(const std::string &data, std::vector<char> &vecData)
{
    for(int i = 0; i < data.size(); i++)
    {
        vecData.push_back(data[i]);
    }
}

std::vector<std::string> Concatenate2Vector(const std::vector<std::string> a, const std::vector<std::string> b)
{
    std::vector<std::string> result;
    result.reserve(a.size() + b.size());
    result.insert(result.end(), a.begin(), a.end());
    result.insert(result.end(), b.begin(), b.end());
    
    return result;
}

std::vector<std::string> operator * (const std::vector<std::string> setA, const std::vector<std::string> setB)
{
    std::vector<std::string> result;
    result = Concatenate2Vector(setA, setB);

    return result;
}

std::vector<int> StrVec2IntegerVec(const std::vector<std::string> strvec)
{
    std::vector<int> result;
    for(int i = 0; i < strvec.size(); i++)
    {
        int conversion = 0;
        std::istringstream iss(strvec[i]);
        iss >> conversion;
        result.push_back(conversion);
    }
    return result;
}

int main()
{
    /* if(in.is_open())
    {
        std::getline(in, data);
        PrintString("Data cargada, pulse cualquier tecla para continuar...");
        std::getchar();
        
        FillVector(data, vecData);
        for(int i = 0; i < vecData.size(); i++)
        {
            std::cout << vecData[i] << std::endl;
        }
    } 
    else
    {
         std::cout << "Unable to open file";
    }
    in.close();*/

    std::vector<std::string> vectorA {"1", "2", "3"};
    std::vector<std::string> vectorB {"1", "22", "4"};

    std::vector<std::string> vecResult = Concatenate2Vector(vectorA, vectorB);
    std::vector<int> vecint = StrVec2IntegerVec(vecResult);
    std::sort(vecint.begin(), vecint.end());

    for(int i = 0; i < vecint.size(); i++)
    {
        std::cout << vecint[i] << std::endl;
    }

    std::getchar();
}

