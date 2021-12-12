#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>

int chance = 6, len = 0;
char dictionary[10][20] = {"amazon", "google", " youtube", "yahoo", "facebook", "wikipedia", "twitter", "instagram", "flipkart", "ebay"};

void printman(int mistakes, char *man)
{
    printf("\tMistakes :%d\n", mistakes);
    switch (mistakes)
    {
    case 1:
        man[0] = '(', man[1] = ')';
        break;
    case 2:
        man[2] = '|';
        break;
    case 3:
        man[3] = '/';
        break;
    case 4:
        man[4] = '\\';
        break;
    case 5:
        man[5] = '/';
        break;
    case 6:
        man[6] = '\\';
        break;
    default:
        break;
    }

    printf("\t _________\n"
           "\t|         |\n"
           "\t|        %c %c\n"
           "\t|        %c%c%c\n"
           "\t|        %c %c\n"
           "\t|             \n"
           "\t|             \n",
           man[0], man[1], man[3],
           man[2], man[4], man[5], man[6]);
}

void printword(char *guessed, int len)
{
    printf("\t");
    for (int i = 0; i < len; i++)
        printf("%c ", guessed[i]);
    printf("\n\n");
}

int main()
{
    printf("\n\t\t ------------------------- Hangman -------------------------");
    printf("\n\n\t\t\t\t\t    Rules: ");
    printf("\n\t\t - you will get a maximum of 6 chances.");
    printf("\n\t\t - all alphabet are in lower case.");
    printf("\n\t\t - all words are names of popular websites. eg. Google");
    printf("\n\t\t syntax : alphabet");
    printf("\n\t\t example : a");
    printf("\n\n\t\t\t\t\t  Good Luck! \n");

    char *man = malloc(chance + 1);
    char *guessed = malloc(len);
    char *incorrectletters = malloc(chance);
    char *win;
    char guess;
    bool found;
    int mistakes = 0;

    //initialising the word
    int random = (rand() % 10); //returning a random number(1-10) for the index
    char *word = dictionary[random];
    len = strlen(word);

    //filling in the empty spaces
    memset(man, ' ', chance + 1);
    memset(guessed, '_', len);

    do
    {
        found = false;
        printf("\n\n");
        printman(mistakes, man);
        printf("\n\n");
        printf("\tIncorrect Letters : ");
        if (mistakes == 0)
            printf("None\n");
        for (int i = 0; i < mistakes; i++)
            printf("%c ", incorrectletters[i]);
        printf("\n\n");
        printword(guessed, len);
        printf("\tenter any alphabet in lower case : ");
        do
            scanf("%c", &guess);
        while (getchar() != '\n');
        for (int i = 0; i < len; i++)
        {
            if (word[i] == guess)
            {
                found = true;
                guessed[i] = guess;
            }
        }
        if (!found)
        {
            incorrectletters[mistakes] = guess;
            mistakes += 1;
        }
        win = strchr(guessed, '_'); //returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found
    } while (mistakes < chance && win != NULL);

    if (win == NULL)
    {
        printf("\n");
        printword(guessed, len);
        printf("\n\tCongradulations! You have won!\n\n"); // : %s\n\n", word);
    }
    else
    {
        printf("\n");
        printman(mistakes, man);
        printf("\n\n\tBetter luck next time. The word was %s\n\n", word);
    }

    //replay
    printf("\tpress 1 to play again...\n\t      0 to quit.\n");
    if (getchar() == '0')
        exit(0);
    while (getchar() == '\n')
        main();

    //buffer
    sleep(10);

    free(man);
    free(word);
    free(guessed);
    return 0;
}