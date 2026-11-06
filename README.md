# Hangman

**A Word-Guessing Game in C**

## Overview

A console version of Hangman. The computer picks the name of a popular website, and the player guesses it one letter at a time. Each wrong guess adds a body part to the drawing; six wrong guesses and the game is lost. The project practises C basics: arrays and strings, dynamic memory, loops and console input and output.

## Repository layout

| Path | Content |
| --- | --- |
| `main.c` | The whole game |
| `main.exe` | A compiled build for Windows |

## How to run

**Windows:** run `main.exe`, or compile it yourself with Code::Blocks or MinGW: `gcc main.c -o hangman` and then `hangman`.

The code includes `<Windows.h>`, so it builds on Windows only. On macOS or Linux, replace that line with `#include <unistd.h>` and compile with `gcc main.c -o hangman`.

## Rules

| Rule | Detail |
| --- | --- |
| Words | One of 10 website names: amazon, google, youtube, yahoo, facebook, wikipedia, twitter, instagram, flipkart, ebay |
| Guesses | Type one lower-case letter and press Enter |
| Chances | 6 wrong guesses allowed; wrong letters are listed on screen |
| End | Win by filling in every letter; lose on the 6th mistake, when the word is revealed |
| Replay | Press 1 to play again or 0 to quit |

## How it works

| Part | Content |
| --- | --- |
| Word choice | `rand() % 10` picks an index into the word list |
| Board | The guessed word starts as underscores and fills in as letters are found |
| Drawing | Each mistake adds a part of the figure: head, body, arms, legs |
| Win check | `strchr` looks for any underscore left in the guessed word |

## Notes

`rand()` is never seeded, so the same word comes up first every time the program starts; adding `srand(time(NULL));` at the start of `main` would fix this. The word " youtube" has a leading space in the list, so it cannot be fully guessed.
