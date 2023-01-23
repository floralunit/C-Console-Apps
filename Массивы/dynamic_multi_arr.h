int inputArrCol(); // Ввод размерности массива

int inputArrRows(); // Ввод размерности массива

int **createDimArray(int r, int c); // Вывод массива

void print_array(int **arr, int m, int n); // Вывод массива

int **initArrCode(int **arr, int m, int n); // Инициализация массива в коде

int **initArrRandom(int **arr, int m, int n); // Инициализация массива рандомными числами

int **initArrConsole(int **arr, int m, int n); // Инициализация массива через консоль

int **initArrFile(FILE *fp, int **arr, int m, int n); // Инициализация массива из файла

int **initArray(int **arr, int m, int n); // Выбор способа иницилизации массива

void write_array_to_file(FILE *fp, int **arr, int m, int n); // Запись массива в файл

int print_array_ways(int **arr, int m, int n); // Чтение массива