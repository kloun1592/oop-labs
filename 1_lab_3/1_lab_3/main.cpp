#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

bool ArgumentsExist(int argc, const int argumentsQuantity)
{
    if (argc != argumentsQuantity)
    {
        cout << "Invalid arguments count" << endl
        << "Usage: copyfile.exe <input file> <output file>" << endl;
        return false;
    };
    return true;
}

bool TryReadMatrixFromFile(const string& matrixFilename, float matrixName[3][3])
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
            
            if(!(matrixFile >> matrixName[x][y]))
            {
                matrixFile.close();
                return false;
            }
        }
    }
    matrixFile.close();
    return true;
}

void MultiplyOfTwoMatricies(float matrix1[3][3], float matrix2[3][3], float resMatrix[3][3])
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
};

void PrintResultOfMultiplication(float resMatrix[3][3])
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            cout << setprecision (3) << fixed << resMatrix[x][y] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char * argv[])
{
    const int matrixRowQuantity = 3;
    const int matrixColummQuantity = 3;
    
    float matrix1[matrixRowQuantity][matrixColummQuantity];
    float matrix2[matrixRowQuantity][matrixColummQuantity];
    float resMatrix[matrixRowQuantity][matrixColummQuantity];
    
    if (ArgumentsExist(argc, 3) && TryReadMatrixFromFile(argv[1], matrix1) && TryReadMatrixFromFile(argv[2], matrix2))
    {
        MultiplyOfTwoMatricies(matrix1, matrix2, resMatrix);
        PrintResultOfMultiplication(resMatrix);
        return 0;
    }
    cout << "Something went wrong" << endl;
    return 1;
}
