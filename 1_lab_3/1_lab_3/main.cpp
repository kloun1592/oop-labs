#include <iostream>
#include <fstream>

using namespace std;

bool isArgumentsExist(int argc, const int argumentsQuantity)
{
    if (argc != argumentsQuantity)
    {
        cout << "Invalid arguments count" << endl
        << "Usage: copyfile.exe <input file> <output file>" << endl;
        return false;
    };
    return true;
}

bool TryReadMatrixFromFile(const string matrixFilename, int matrixName[3][3], const int martixRowQuantity, const int martixColummQuantity)
{
    ifstream matrixFile(matrixFilename);
    if (!matrixFile.is_open())
    {
        cout << "Cannot open file." << endl;
    }
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            matrixFile >> matrixName[x][y];
        }
    }
    matrixFile.close();
    return true;
}

int MultiplicateOfTwoMatrix(const int matrix1[3][3], const int matrix2[3][3], int resMatrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            resMatrix[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                resMatrix[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    return resMatrix[3][3];
};

void PrintResultOfMultiplication(const int resMatrix[3][3],  const int martixRowQuantity, const int martixColummQuantity)
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << resMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char * argv[])
{
    const int martixRowQuantity = 3;
    const int martixColummQuantity = 3;
    
    int matrix1[martixRowQuantity][martixColummQuantity];
    int matrix2[martixRowQuantity][martixColummQuantity];
    int resMatrix[martixRowQuantity][martixColummQuantity];
    
    if (isArgumentsExist(argc, 3) && TryReadMatrixFromFile(argv[1], matrix1, martixRowQuantity, martixColummQuantity) && TryReadMatrixFromFile(argv[2], matrix2, martixRowQuantity, martixColummQuantity))
    {
        MultiplicateOfTwoMatrix(matrix1, matrix2, resMatrix);
        PrintResultOfMultiplication(resMatrix, martixRowQuantity, martixColummQuantity);
        return 0;
    }
    
    return 1;
}
