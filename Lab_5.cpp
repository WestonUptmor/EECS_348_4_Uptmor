#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std :: string getfilename() {
    char temp [101];
    std :: string filename;
    printf("What is the file name?: ");
    scanf("%100s", temp);
    filename = temp;
    return filename;
}


int main(){
    std :: string filename = getfilename();
    int openfile=0;
    std::ifstream f(filename);

    std :: string line;
    int size;
    std :: getline(f, line);
    size = std :: stoi(line);


    int** matrix1 = new int*[size];
    for (int i = 0; i < size; i++)
        matrix1[i] = new int[size]();

    int** matrix2 = new int*[size];
    for (int i = 0; i < size; i++)
        matrix2[i] = new int[size]();
    for (int i=0;i<size;i++){
        getline(f, line);
        std :: istringstream stream(line);
        int num;
        int i2 = 0;
        while (i2 < size && stream >> num){
            matrix1[i][i2] = num;
            i2++;
}
    }
    for (int i=0;i<size;i++){
        getline(f, line);
        std :: istringstream stream(line);
        int num;
        int i2 = 0;
        while (i2 < size && stream >> num){
            matrix2[i][i2] = num;
            i2++;
}
    }
    printf("Matrix A:\n");
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    printf("\nMatrix B:\n");
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    printf("\nA + B: \n");
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            std::cout << matrix2[i][j]+matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i=0; i<size;i++){
        for (int j=0;j<size;j++){
            printf("%i ", matrix1[i][j]+matrix2[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    return 0;
}