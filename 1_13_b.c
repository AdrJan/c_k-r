#include <stdio.h>
#include <math.h>
#include <string.h>

#define IS_WHITESPACE 1
#define NOT_WHITESPACE 0 
#define MAX_WORD_LENGTH 100
#define BAR_RESOLUTION 100

void fill_array_zeros(int[]);
void get_data(int[]);
void print_header();
void print_vertical_histogram(int[]);
int get_total_word_length(int[]);
int get_max_length(int[]);
void print_legend(int[]);
void map_word_len(int[], int[]);

int main() 
{
    int word_lengths[MAX_WORD_LENGTH];
    int mapped_word_lengths[MAX_WORD_LENGTH];

    fill_array_zeros(word_lengths);
    fill_array_zeros(mapped_word_lengths);
    get_data(word_lengths);
    map_word_len(word_lengths, mapped_word_lengths);
    print_header();
    print_vertical_histogram(mapped_word_lengths);
    print_legend(word_lengths);
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

void print_header() 
{
    printf("=== WORD LENGTH HISTOGRAM ===\n");
}

void print_vertical_histogram(int words_length[]) 
{
    int mapped_max_length = get_max_length(words_length);
    for(int i = mapped_max_length; i >= 0; i--) 
    {
        for(int j = 0; j < MAX_WORD_LENGTH; j++)
                if(words_length[j] > 0) 
                {
                    if(words_length[j] > i) 
                        printf("===");
                    else
                        printf("   ");
                }
        printf("\n");
    }
}

void print_legend(int words_length[]) 
{
    for(int i = 0; i < MAX_WORD_LENGTH; i++) 
    {
        if(words_length[i] > 0)
            printf("%3d", i);
    }
    printf("\n");
}

void map_word_len(int src_words_length[], int dst_words_length[]) 
{
    int total = get_total_word_length(src_words_length);
    for(int i = 0; i < MAX_WORD_LENGTH; i++) 
    {
        if(src_words_length[i] > 0)
            dst_words_length[i] = round(((float) src_words_length[i] / total) * BAR_RESOLUTION);
    }
}

int get_max_length(int words_length[]) 
{
    int max = 0;
    for(int i = 0; i < MAX_WORD_LENGTH; i++)
        if(max < words_length[i])
            max = words_length[i];
    return max;
}

int get_total_word_length(int word_lengths[]) 
{
    int total = 0;
    for(int i = 0; i < MAX_WORD_LENGTH; i++)
        total += word_lengths[i];
    return total;
}
