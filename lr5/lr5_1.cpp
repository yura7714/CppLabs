#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <ctype.h>
#include <string.h>

using namespace std;

// Функция для подсчёта пустых и непустых символов
void count_empty_and_nonempty(FILE *file, int *empty, int *non_empty)
{
    char ch;
    *empty = 0;
    *non_empty = 0;
    
    // Возвращаем указатель файла в начало
    rewind(file);
    
    while (!feof(file))
    {
        ch = getc(file);
        if (feof(file)) break;
        
        if (isspace(ch) || iscntrl(ch))
            (*empty)++;
        else
            (*non_empty)++;
    }
}

// Функция для поиска подстроки в файле и записи результата в отдельный файл
void search_substring(FILE *input_file, const char *substring, const char *output_filename)
{
    char line[1024];  // буфер для хранения строки
    int line_number = 0;
    int found_count = 0;
    FILE *output_file;
    
    // Возвращаем указатель файла в начало
    rewind(input_file);
    
    // Открываем файл для записи результатов
    output_file = fopen(output_filename, "w");
    if (output_file == NULL)
    {
        printf("Не удалось создать файл результатов %s\n", output_filename);
        return;
    }
    
    fprintf(output_file, "=== Результаты поиска подстроки \"%s\" ===\n\n", substring);
    
    // Поиск подстроки построчно
    while (fgets(line, sizeof(line), input_file) != NULL)
    {
        line_number++;
        
        // Ищем подстроку в текущей строке
        if (strstr(line, substring) != NULL)
        {
            found_count++;
            fprintf(output_file, "Строка %d: %s", line_number, line);
            // Если строка не заканчивается переводом строки, добавляем его
            if (line[strlen(line) - 1] != '\n')
                fprintf(output_file, "\n");
        }
    }
    
    if (found_count == 0)
    {
        fprintf(output_file, "Подстрока \"%s\" не найдена в файле.\n", substring);
    }
    else
    {
        fprintf(output_file, "\n--- Итого найдено: %d совпадений ---\n", found_count);
    }
    
    fclose(output_file);
    printf("\nРезультаты поиска сохранены в файл: %s\n", output_filename);
    printf("Найдено совпадений: %d\n", found_count);
}

void main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char ch, name[50];
    char substring[100];
    char result_filename[100];
    FILE *in;
    int empty_count = 0;
    int non_empty_count = 0;
    
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    
    if ((in = fopen(name, "r")) == NULL)
    {
        printf("Файл %s не открыт", name);
        return;
    }
    
    // Вывод содержимого файла
    printf("\n--- Содержимое файла ---\n");
    while (!feof(in))
    {
        ch = getc(in);
        if (feof(in)) break;
        putchar(ch);
    }
    
    // Подсчёт пустых и непустых символов
    count_empty_and_nonempty(in, &empty_count, &non_empty_count);
    
    // Вывод статистики
    printf("\n\n--- Статистика ---\n");
    printf("Пустых символов: %d\n", empty_count);
    printf("Непустых символов: %d\n", non_empty_count);
    printf("Всего символов: %d\n", empty_count + non_empty_count);
    
    // Поиск подстроки
    printf("\n--- Поиск подстроки ---\n");
    printf("Введите подстроку для поиска: ");
    scanf("%s", substring);
    printf("Введите имя файла для сохранения результатов: ");
    scanf("%s", result_filename);
    
    search_substring(in, substring, result_filename);
    
    fclose(in);
}