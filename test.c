# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void free_memory(int **arr, int *mas, int n);
void output(int **arr, int *mas, int n);
int *filling(int n, int *mas);
int up(const int *i, const int *j);
int down(const int *i, const int *j);
int **sort(int **arr, int *mas, int n);


int main() {
    int n, i, **arr, *mas;
    char key;
    int err = 0;
    printf("Введите размер массива: ");
    if ((!scanf("%d%c", &n, &key)) ||
        (n <= 0) ||
        (key != '\n')) {  // проверка на валидность
        err = 1;
    } else {
        arr = (int**)malloc(n * sizeof(int*));
        mas = (int*)malloc(n * sizeof(int));
        srand(time(NULL));
        filling(n, mas);
        for (i = 0; i < n; i++) {
            arr[i] = (int*)malloc(mas[i] * sizeof(int));
            for (int j = 0; j < mas[i]; j++) {
                arr[i][j] = rand() %1000;  // заполняем arr случайными числами
            }
        }
        sort(arr, mas, n);
        output(arr, mas, n);
        free_memory(arr, mas, n);
    }
    return err;
}

int *filling(int n, int *mas) {
    int x;
    int i = 0;
    while (i < n) {
        int r = 1 + rand() % 21;  // ограничение 20 массивов
        for (x = 0; x < i; x++) {
            if (mas[x] == r) {
                break;
            }
        }
        if (x == i) {
            mas[i++] = r;
        }
    }
    return mas;
}

int **sort(int **arr, int *mas, int n) {
    for (int i = 0; i < n; i = i + 2) {
        qsort(arr[i], mas[i], sizeof (int),
              (int(*) (const void *, const void *)) down);
    }
    for (int i = 1; i < n; i = i + 2) {
        qsort(arr[i], mas[i], sizeof (int),
              (int(*) (const void *, const void *)) up);
    }
    return arr;
}

int up(const int *i, const int *j) {  // сравнение двух интов для убывания
    return *i - *j;
}

int down(const int *i, const int *j) {  // сравнение двух интов для возрастания
    return *j - *i;
}

void free_memory(int **arr, int *mas, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(mas);
}

void output(int **arr, int *mas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mas[i]; j++) {
            printf("%-6d ", arr[i][j]);
        }
        printf("\n");
    }
}
