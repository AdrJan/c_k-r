#include <stdio.h>
#include <math.h>

#define IS_WHITESPACE 1
#define NOT_WHITESPACE 0 
#define MAX_WORD_LENGTH 100
#define BAR_RESOLUTION 100

void fill_array_zeros(int[]);
void get_data(int[]);
void print_header();
void print_horizontal_histogram(int[]);
int get_total_word_length(int[]);
void print_histogram_line(int, int);

int main() 
{
    int word_lengths[MAX_WORD_LENGTH];

    fill_array_zeros(word_lengths);
    get_data(word_lengths);
    print_header();
    print_horizontal_histogram(word_lengths);
}

void fill_array_zeros(int arr[]) 
{
    for(int i = 0; i < MAX_WORD_LENGTH; i++) 
        arr[i] = 0;
} 

void get_data(int word_lengths[]) 
{
    int c;
    int ws_state = IS_WHITESPACE;
    int word_length = 0;

    while((c = getchar()) != EOF) 
    {
        if(c == ' ' || c == '\n' || c == '\t') 
        {
            if(!ws_state) 
            {
                word_lengths[word_length] += 1;
                word_length = 0;
            }
            ws_state = IS_WHITESPACE;
        } 
        else
            ws_state = NOT_WHITESPACE;
        word_length++;
    }
}

void print_header() {
    printf("=== WORD LENGTH HISTOGRAM ===\n");
}

void print_horizontal_histogram(int words_length[]) 
{
    int total = get_total_word_length(words_length);
    for(int i = 0; i < MAX_WORD_LENGTH; i++) 
    {
        if(words_length[i] > 0) 
        {
            printf("[%3d]", i);
            print_histogram_line(words_length[i], total);
        }
    }
}

void print_histogram_line(int word_len_cnt, int total) 
{
    int bar_len = round(((float) word_len_cnt / total) * BAR_RESOLUTION);
    printf("|");
    for(int i = 0; i < bar_len; i++)
        printf("=");
    printf("\n");
}

int get_total_word_length(int word_lengths[])
 {
    int total = 0;
    for(int i = 0; i < MAX_WORD_LENGTH; i++) 
    {
        total += word_lengths[i];
    }
    return total;
}
