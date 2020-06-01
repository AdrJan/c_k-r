#include <stdio.h>
#include <math.h>
#include <string.h>

#define IS_WHITESPACE 1
#define NOT_WHITESPACE 0 
#define MAX_LETTER_COUNT 256
#define BAR_RESOLUTION 150
#define COLUMN_WIDTH 5

void fill_array_zeros(int[]);
void get_data(int[]);
void print_header();
void print_vertical_histogram(int[]);
int get_total_letter_counts(int[]);
int get_max_count(int[]);
void print_legend(int[]);
void map_letter_counts(int[], int[]);
int get_letters_count(int[]);

int main() 
{
    int letter_counts[MAX_LETTER_COUNT];
    int mapped_letter_counts[MAX_LETTER_COUNT];

    fill_array_zeros(letter_counts);
    fill_array_zeros(mapped_letter_counts);
    get_data(letter_counts);
    map_letter_counts(letter_counts, mapped_letter_counts);
    print_header(get_letters_count(letter_counts));
    print_vertical_histogram(mapped_letter_counts);
    print_legend(letter_counts);
}

void fill_array_zeros(int arr[]) 
{
    for(int i = 0; i < MAX_LETTER_COUNT; i++) 
        arr[i] = 0;
} 

void get_data(int word_counts[]) 
{
    int c;
    int ws_state = IS_WHITESPACE;

    while((c = getchar()) != EOF) 
    {
        word_counts[c] += 1;
    }
}

void print_header(int offset_width) 
{   
    char header_text[] = "=== LETTER COUNT HISTOGRAM ===\n";
    int header_offset_width = offset_width * COLUMN_WIDTH - strlen(header_text);

    printf("\n");
    for(int i = 0; i < header_offset_width; i++)
        printf("=");
    printf("%s", header_text);
}

void print_vertical_histogram(int letter_counts[]) 
{
    int mapped_max_length = get_max_count(letter_counts);
    for(int i = mapped_max_length; i >= 0; i--) 
    {
        for(int j = 0; j < MAX_LETTER_COUNT; j++)
                if(letter_counts[j] > 0) 
                {
                    if(letter_counts[j] > i) 
                        printf("%*s", COLUMN_WIDTH, "====");
                    else
                        printf("%*s", COLUMN_WIDTH, "    ");
                }
        printf("\n");
    }
}

void print_legend(int words_length[]) 
{
    for(int i = 0; i < MAX_LETTER_COUNT; i++) 
    {
        if(words_length[i] > 0) {
            if(i == '\n')
                printf("[%*s]", COLUMN_WIDTH - 2, "nl");
            else
                printf("[%*c]", COLUMN_WIDTH - 2, i);
        }
    }
    printf("\n");
}

void map_letter_counts(int src_letter_counts[], int dst_letter_counts[]) 
{
    int total = get_total_letter_counts(src_letter_counts);
    for(int i = 0; i < MAX_LETTER_COUNT; i++) 
    {
        if(src_letter_counts[i] > 0)
            dst_letter_counts[i] = round(((float) src_letter_counts[i] / total) * BAR_RESOLUTION);
    }
}

int get_max_count(int letter_counts[]) 
{
    int max = 0;
    for(int i = 0; i < MAX_LETTER_COUNT; i++)
        if(max < letter_counts[i])
            max = letter_counts[i];
    return max;
}

int get_letters_count(int letter_counts[]) {
    int letters_count = 0;
    for(int i = 0; i < MAX_LETTER_COUNT; i++)
        if(letter_counts[i] > 0)
            letters_count++;
    return letters_count;
}

int get_total_letter_counts(int letter_counts[]) 
{
    int total = 0;
    for(int i = 0; i < MAX_LETTER_COUNT; i++)
        total += letter_counts[i];
    return total;
}
